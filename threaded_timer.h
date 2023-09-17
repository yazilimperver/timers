/**
 * @file threaded_timer.h.
 * @date 7.03.2023
 * @author Yazilimperver
 * @brief Yuksek hassasiyete sahip, threaded timer. 
 * @remark Copyright (c) 2023, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */

#ifndef THREADED_TIMER_H
#define THREADED_TIMER_H

#include <atomic>
#include <memory>
#include <thread>
#include <functional>

using TimerFunction = std::function<void(void)>;
/**
 * @brief Yuksek hassasiyete sahip, bir kerelik ve periyodik zamanlama kabiliyeti sunan threaded timer. 
 * 
 */
class ThreadedTimer {
public:
    /// @brief Sinif yikicisidr
    virtual ~ThreadedTimer();

    /// @brief Bir kerelik zamanlama sonrasi cagri icin kullanilabilecek API'dir
    void OneShot(TimerFunction function, int32_t delayInMsec);
    
    /// @brief Periyodik cagri icin kullanilabilecek API'dir
    void Periodic(TimerFunction function, int32_t intervalInMsec);
    
    /// @brief Devam eden periyodik zamanlayiciyi durdurmak icin  kullanilabilecek API'dir
    void Stop();

    /// @brief Sinifi yok etmeden bloklayarak beklemek icin kullanilabilecek API'dir
    void WaitForCompletion();

protected:
    std::atomic<bool> mActive{ true };
    std::unique_ptr<std::thread> mThread{ nullptr };
};

#endif // !THREADED_TIMER_H

/**
Copyright (c) [2023][Yazilimperver - yazilimpervergs@gmail.com]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */