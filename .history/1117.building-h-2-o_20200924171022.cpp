/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */

// @lc code=start
#include<mutex>
#include<condition_variable>
class H2O {
public:
    mutex mt;
    condition_variable cv;
    int hnum;
    H2O() {
        hnum = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> locker(mt);
        cv.wait(locker, [this]{return (hnum>=-2&&hnum<2);});
        hnum++;
        cv.notify_all();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> locker(mt);
        cv.wait(locker, [this]{return (hnum>=0&&hnum<=2);});
        hnum -= 2;
        cv.notify_all();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};
// @lc code=end

