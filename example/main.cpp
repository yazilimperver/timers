#include "threaded_timer.h"

#include <iostream>

#include "spdlog/spdlog.h"

int main(){
    // ThreadedTimer kullanim ornegi
    ThreadedTimer instance1;
    uint32_t counter{4};
    instance1.Periodic([&counter](){ spdlog::info("Periodic timer ornegi! Sayac:{}", counter--);}, 1000);
    ThreadedTimer instance2;
    instance2.OneShot([](){ spdlog::info("Oneshot timer ornegi!");}, 500);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));   
    return 0;
}