/**
  * ThreadPool implementation.
  *
  * The architecture demonstrated in this project is separating into 2 threads
  *     Thread 1 : working on game state, gameplay, etc; to construct game state data then feed to
  *                Thread 2 for rendering
  *     Thread 2 : rendering thread picks input game state data from Thread 1 then rendering
  *
  * The way both thread communicates for game state data is by having 2 game state buffers.
  * While Thread 2 is rendering which is working with one of the two game state buffers, then
  * Thread 1 can keep constructing and preparing game state data for next frame, by working with
  * another game state buffer.
  *
  * [Extra]
  * This architecture also allows optimization opportunity for rendering thread to go further
  * by introducing threads in its own dedicated thread to help in rendering. But this is an idea
  * for now, not implemented yet.
  *
  * Conditions
  * - .tga output image will be in fixed size of 512x512.
  * - single-precision for z-buffer
  */

#include "Common.h"
#include "MathUtil.h"
#include "GameState.h"
#include "GameThreadManager.h"
#include "RenderingThreadManager.h"

#include <iostream>
#include <atomic>

#define IMG_FILENAME "a.tga"

const int WIDTH = 512;
const int HEIGHT = 512;

int main()
{
    MathUtil::init();

    int frameCount = 0;
    const int kTargetFrameCount = 1000;

    LOGA_YELLOW("--Begin Game Initialization--\n");

    // we will swap between these two game states (as dataset)
    // for game-thread and rendering-thread to work on it in parallel
    GameState gs1(1, MAX_CIRCLES);
    GameState gs2(2, MAX_CIRCLES);

    GameState* gs1Ptr = &gs1;
    GameState* gs2Ptr = &gs2;
 
    SyncObj syncObj;

    // create rendering-thread manager
    RenderingThreadManager renderingThread(WIDTH, HEIGHT);
    renderingThread.setSyncObj(syncObj);
    renderingThread.startThread();

    // create game-thread manager
    GameThreadManager gameThread;
    gameThread.setSyncObj(syncObj);
    gameThread.initialize(MAX_CIRCLES);
    gameThread.startThread();
    // initial frame, we all have ready data to enqueue
    gameThread.enqueue(GameCommand(gs1Ptr, GameCommandType::FIRST_FRAME_SPECIAL));

    // wait until first frame is prepared
    syncObj.waitForOnCurrentThread(0);

    LOGA_YELLOW("--Begin Game Loop--\n");
    while (frameCount < kTargetFrameCount)
    {
        gameThread.enqueue(GameCommand(gs2Ptr, GameCommandType::ADD_NEW_RANDOM_CIRCLE));
        renderingThread.enqueue(gs1Ptr);

        // simulate gameplay for frameCount
        ++frameCount;

        // sync between two threads
        // usually render thread should finish later so fps won't lack behind due to logic update
        syncObj.waitForBothOnCurrentThread();

        LOGA_YELLOW("[main thread] -------- swap --------\n");
        using std::swap;    // for ADL
        swap(gs1Ptr, gs2Ptr);

        LOGA_YELLOW("[main thread] finished rendering frame %d\n", frameCount);
        syncObj.setReadyAndResetAllComplete();
    }
    auto s = renderingThread.getFrameBuffer();
    // write into file from framebuffer
    // do this before kill rendering thread
    Logger::LogA<Logger::TextColor::YELLOW>("[main thread] Rendered for %lu frames\n", frameCount);
    renderingThread.writeToTGAImage(IMG_FILENAME);

    // kill and wait
    LOGA_YELLOW("[main thread] kill both threads\n");
    gameThread.killThreadAndWait();
    renderingThread.killThreadAndWait();

    // use this to always print out even in debug build
    Logger::LogA<Logger::TextColor::YELLOW>("[main thread] Wrote into .tga file\n");

    return 0;
}
