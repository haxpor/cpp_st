#pragma once

//#include "ThreadPool.h"
#include "Common.h"
#include "GameState.h"
#include "TGAImage.h"
#include "ProfileCommon.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <atomic>
#include <queue>
#include <vector>
#include <cstring>

class RenderingThreadManager
{
public:
    RenderingThreadManager(int screenWidth, int screenHeight)
        : screenWidth(screenWidth)
        , screenHeight(screenHeight)
        , preComputed_squredScreenWH(screenWidth * screenHeight)
        , signalKillThread(false)
        , thQueueBusyLock(ATOMIC_FLAG_INIT)
        , syncObj(nullptr)
    {
        zBuffer.resize(preComputed_squredScreenWH, 1.0f);
        frameBuffer.resize(preComputed_squredScreenWH, 0);
    }

    // destructor will block to finish terminating the thread
    ~RenderingThreadManager()
    {
        if (!signalKillThread)
        {
            // behave like std::async() with policy std::launch::async
            // to block in destructor if it isn't killed before via killThreadAndWait()
            killThreadAndWait();
        }
    }

    void startThread()
    {
        std::thread t(&RenderingThreadManager::endlessReusableRenderWorker, this);
        dedicatedTH = std::move(t);
    }

    // this function is not thread-safe
    // it will kill thread, then wait until this manager has done its termination
    void killThreadAndWait()
    {
        // notify to kill the thread
        signalKillThread = true;
        // notify all to be killed
        thCV.notify_all();

        dedicatedTH.join();
    }

    void enqueue(const GameState& gameState)
    {
        if (signalKillThread)
            return;

        // spinlock when we add a new item into the working queue
        Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] waiting for adding a new queue\n");
        while (thQueueBusyLock.test_and_set(std::memory_order_acquire))
                ;
        renderingQueue.push(gameState);
        thQueueBusyLock.clear();
        Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] added one more work into queue\n");

        // notify the thread
        thCV.notify_one();
    }

    // return true if success, otherwise false
    bool writeToTGAImage(const char* filename)
    {
        return TGAImage::writeImage(filename, static_cast<unsigned int*>(&frameBuffer[0]), screenWidth, screenHeight);
    }

    inline void setSyncObj(SyncObj& obj) { syncObj = &obj; }
    inline const std::vector<unsigned int> getFrameBuffer() const { return frameBuffer; }

protected:
    void clearFrameBuffer()
    {
        std::memset(&zBuffer[0], 1, preComputed_squredScreenWH);
        std::memset(&frameBuffer[0], 0, preComputed_squredScreenWH);
    }

private:
    void endlessReusableRenderWorker()
    {
        do{
            Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] waiting\n");
            std::unique_lock<std::mutex> lock(thCheckCondMX);
            // if there is some works need to be done, or order to kill itself come
            thCV.wait(lock, [&]() { return renderingQueue.size() > 0 || signalKillThread; });
            lock.unlock();

            if (signalKillThread)
            {
                Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] kill itself\n");
                break;
            }
            else if (renderingQueue.size() > 0)
            {
                // remove work item from the working queue
                // use atomic_flag here as we know it won't take long time to do this
                //
                // use lock-free spinlock to quickly clear the framebuffer + zbuffer
                // as we use std::memset, this is quickest we could get
                while (thQueueBusyLock.test_and_set(std::memory_order_acquire))
                    ;
                GameState& gs = renderingQueue.front();
                renderingQueue.pop();
                thQueueBusyLock.clear();

                // do real work
                Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] render for game-state id[%d]\n", gs.id);
                Profile::Start();
                // rendering tasks don't need locking mechanism as this is a dedicated thread to
                // handle all of the remaining rendering work
                clearFrameBuffer();
                renderWork(gs);
                Profile::EndAndPrintA("-- [rendering thread]");

                // notify task done
                if (syncObj != nullptr)
                {
                    syncObj->setComplete(1);
                    syncObj->waitReadyOnCurrentThread();
                }
            }
        } while (!signalKillThread);
    }

    void renderWork(GameState& gs)
    {
        auto ccs = gs.circles;
        const int kCircleCount = ccs.size();

        // sort according to z-depth value
        // we try to draw near the camera first before further to reduce overdraw
        std::sort(gs.circles.begin(), gs.circles.end(), [](const Circle& a, const Circle& b) { return a.depth < b.depth; });

        for (int i=0; i<kCircleCount; ++i)
        {
            renderRectangle(ccs[i]);
        }

        Logger::LogA<Logger::TextColor::CYAN>("[rendering thread] render %d circles\n", kCircleCount);
    }

    void renderRectangle(const Circle& c)
    {
        const int minX = c.x - c.r;
        const int maxX = c.x + c.r;
        const int minY = c.y - c.r;
        const int maxY = c.y + c.r;

        const int centerX = c.x;
        const int centerY = c.y;
        
        const int squaredR = c.r * c.r;

        Logger::LogA<Logger::TextColor::GREEN>(":%d,%d %d,%d\n", c.x, c.y, c.depth, c.r);
        Logger::LogA<Logger::TextColor::GREEN>("%d,%d %d,%d %d\n", minX, maxX, minY, maxY, squaredR);

        for (int x=minX; x<=maxX; ++x)
        {
            for (int y=minY; y<=maxY; ++y)
            {
                long dx = x - centerX;
                long dy = y - centerY;

                if (dx*dx + dy*dy > squaredR)
                    continue;

                if (x<0 || x>screenWidth)
                    continue;
                if (y<0 || y>screenHeight)
                    continue;

                frameBuffer[x + y*screenWidth] = c.colorARGB;       // both are in the same format
            }
        }
    }

private:
    int screenWidth;
    int screenHeight;
    int preComputed_squredScreenWH;

    std::vector<float> zBuffer; 
    std::vector<unsigned int> frameBuffer;  // in format ARGB

    std::queue<GameState> renderingQueue;
    std::atomic_flag thQueueBusyLock;
    std::mutex thCheckCondMX;
    std::condition_variable thCV;
    std::thread dedicatedTH;    // not thread yet 
    bool signalKillThread;      // make it like Order 66

    SyncObj* syncObj;
};
