#include "threaded_timer.h"
#include "sleep_util.h"

ThreadedTimer::~ThreadedTimer() {
    mActive.store(false);
    WaitForCompletion();
}

void ThreadedTimer::OneShot(TimerFunction function, int32_t delayInMsec) {
    mActive = true;
    mThread = std::make_unique<std::thread>([=]() {
        if (!mActive.load())
            return;
        SleepUtil::PreciseSleep(delayInMsec / 1000.0);

        if (!mActive.load())
            return;

        function();
    });
}

void ThreadedTimer::Periodic(TimerFunction function, int32_t intervalInMsec) {
    mActive = true;
    mThread = std::make_unique<std::thread>([=]() {
        while (mActive.load()) {
            SleepUtil::PreciseSleep(intervalInMsec / 1000.0);

            if (!mActive.load())
                return;

            function();
        }
    });
}

void ThreadedTimer::Stop() {
    mActive = false;
}

void ThreadedTimer::WaitForCompletion() {
    if (nullptr != mThread) {
        if (mThread->joinable()) {
            mThread->join();
        }
    }
}