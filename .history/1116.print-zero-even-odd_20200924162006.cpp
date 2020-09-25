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
    mutex mtx0;
    condition_variable cv;
    int step;
    int one;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        step = 0;
        one = 2;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> mtx(mtx0);
        cv.wait(mtx,[this]{return step==0;});
        one = one%2 + 1;
        step = 1;
        cv.notify_all();
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> mtx(mtx0);
        cv.wait(mtx,[this]{return step==1&&one==1;});
        step = 0;
        cv.notify_all();
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> mtx(mtx0);
        cv.wait(mtx,[this]{return step==1&&one==2;});
        step = 0;
        cv.notify_all();
    }
};
// @lc code=end

