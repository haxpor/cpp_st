#pragma once

//#include "ThreadPool.h"
#include "Common.h"
#include "GameState.h"
#include "ProfileCommon.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <atomic>
#include <queue>
#include <vector>
#include <memory>

// assume these are commands supported in-game
// the actual amount associated with the command depends on GameThreadManager
enum GameCommandType
{
    ROTATE_RIGHT_ALL_OBJS,
    ROTATE_LEFT_ALL_OBJS,
    ADD_NEW_RANDOM_CIRCLE,
    FIRST_FRAME_SPECIAL,
    NEXT_TICK           // normal by all if there is no other commands sending in
};

struct GameCommand
{
    GameState* gs;
    GameCommandType type;

    // create a game command associated with game-state
    GameCommand(GameState* gs_, GameCommandType type_)
        : gs(gs_)
        , type(type_)
    {
    }
};

class GameThreadManager
{
public:
    GameThreadManager()
        : signalKillThread(false)
        , thQueueBusyLock(ATOMIC_FLAG_INIT)
        , syncObj(nullptr)
    {
    }

    ~GameThreadManager()
    {
        if (!signalKillThread)
        {
            // behave like std::async() with policy std::launch::async
            // to block in destructor if it isn't killed before via killThreadAndWait()
            killThreadAndWait();
        }
    }

    // initialize initial game-state
    void initialize(int maxCirclesCount)
    {
        circles.reserve(maxCirclesCount);

        for (int i=0; i<maxCirclesCount; ++i)
        {
            circles.push_back(Circle(
                MathUtil::randInt(512),
                MathUtil::randInt(512),
                MathUtil::randFloat(1.0f, 100.0f),  // depth
                MathUtil::randInt2(35, 50.0f),  // r
                getRandomizedCircleColor(static_cast<CircleColor>(MathUtil::randInt(3)))));
        }
    }

    inline unsigned int getRandomizedCircleColor(CircleColor cc) const
    {
        switch (cc)
        {
        case CircleColor::RED: return RED;
        case CircleColor::GREEN: return GREEN;
        case CircleColor::BLUE: return BLUE;
        case CircleColor::WHITE: return WHITE;
        default: return RED;
        }
    }

    void startThread()
    {
        std::thread t(&GameThreadManager::updateGameWorldThreadWorker, this);
        dedicatedTH = std::move(t);
    }

    void killThreadAndWait()
    {
        // notify to kill the thread
        signalKillThread = true;
        // notify all to be killed
        thCV.notify_all();

        dedicatedTH.join();
    }

    void enqueue(const GameCommand& gc)
    {
        if (signalKillThread)
            return;

        // spinlock when we add a new item into the working queue
        Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] waiting for adding a new item\n");
        while (thQueueBusyLock.test_and_set(std::memory_order_acquire))
            ;
        workQueue.push(gc);
        Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] added one more work into queue\n");
        thQueueBusyLock.clear();
    
        // notify the thread that new work item is added
        thCV.notify_one();
    }

    inline void setSyncObj(SyncObj& obj) { syncObj = &obj; }

protected:
    // assume does work one command per frame
    void gamework(const GameCommand& gc)
    {
        // update logic according to command
        switch (gc.type)
        {
        case FIRST_FRAME_SPECIAL:
            Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] prepare game state for first frame - no sync will be needed\n");
            break;
        case ADD_NEW_RANDOM_CIRCLE:
            Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] add new circle\n");
            break;
        case NEXT_TICK:
            Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] update for next frame\n");
            break;
        }

        // now sending the result into associated game-state of this command
        // TODO: Optimize for efficient copy from thread to game-state
        Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] copy updated game-state to target game-state id[%d]\n", gc.gs->id);
        gc.gs->circles = circles;
    }

private:
    void updateGameWorldThreadWorker()
    {
        do{
            Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] waiting\n");
            std::unique_lock<std::mutex> lock(thCheckCondMX);
            // if there is some works need to be done, or order to kill itself come
            thCV.wait(lock, [&]() { return workQueue.size() > 0 || signalKillThread; });
            lock.unlock();

            if (signalKillThread)
            {
                Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] kill itself\n"); 
                break;
            }
            else if (workQueue.size() > 0)
            {
                // remove work item from the working queue
                // use atomic_flag here as we know it won't take long time to do this
                while (thQueueBusyLock.test_and_set(std::memory_order_acquire))
                    ;
                const GameCommand& gc = workQueue.front();
                workQueue.pop();        // std::queue::pop (derived from std::deque) won't invalidate front and back iterator and reference
                thQueueBusyLock.clear();

                // do real work
                Logger::LogA<Logger::TextColor::MAGENTA>("[game thread] do some work\n");
                Profile::Start();
                gamework(gc);
                Profile::EndAndPrintA("-- [game thread]");

                // notify task done
                if (syncObj != nullptr)
                {
                    syncObj->setComplete(0);

                    // no need to wait for offline first frame preparation
                    if (gc.type != GameCommandType::FIRST_FRAME_SPECIAL)
                        syncObj->waitReadyOnCurrentThread();
                }
            }
        } while (!signalKillThread);
    }

private:
    std::queue<GameCommand> workQueue;
    std::atomic_flag thQueueBusyLock;
    std::mutex thCheckCondMX;
    std::condition_variable thCV;
    std::thread dedicatedTH;    // not thread yet 
    bool signalKillThread;      // make it like Order 66

    // -- section of game related variables --//
    std::vector<Circle> circles;
    //std::weak_ptr<SyncObj> syncObj_weakPtr;
    SyncObj* syncObj;
};
