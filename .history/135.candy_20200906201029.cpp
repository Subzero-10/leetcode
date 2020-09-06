/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        stack<int> s;
        int len = ratings.size();
        vector<int> left(len);
        vector<int> right(len);
        int sum = 0;
        for (int i = 0; i < (int)ratings.size(); i++)
        {
            if (!s.empty()&&ratings[i]>ratings[s.top()])
            {
                int a = 1;
                while (!s.empty())
                {
                    int st = s.top();
                    right[st] = a;
                    if (st == 0)
                    {
                        left[st] = 1;
                    }
                    else
                    {
                        left[st] = left[st-1]+1;
                    }
                    a++;
                    s.pop();
                    sum += max(left[st],right[st]);
                }
            }
            s.push(i);
        }
        int a = 1;
        while (!s.empty())
        {
            int st = s.top();
            right[st] = a;
            if (st == 0)
            {
                left[st] = 1;
            }
            else
            {
                left[st] = left[st-1]+1;
            }
            a++;
            s.pop();
            sum += max(left[st],right[st]);
        }
        return sum;
    }
};
// @lc code=end

