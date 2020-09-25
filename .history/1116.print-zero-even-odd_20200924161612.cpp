/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
#include<mutex>
#include<condition_variable>
class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int step = 0;
    int one = 2;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        mtx.lock();
        cv.wait(mtx,[this]{return step==0;});
        one = one%2 + 1;
        step = 1;
        cv.notify().all();
        mtx.unlock();
    }

    void even(function<void(int)> printNumber) {
        mtx.lock();
        cv.wait(mtx,[this]{return step==1&&one==1;});
        step = 0;
        cv.notify().all();
        mtx.unlock();
    }

    void odd(function<void(int)> printNumber) {
        mtx.lock();
        cv.wait(mtx,[this]{return step==1&&one==2;});
        step = 0;
        cv.notify().all();
        mtx.unlock();
    }
};
// @lc code=end

