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
            if (!s.empty()&&ratings[i]>=ratings[s.top()])
            {
                int a = 1;
                if (ratings[i]==ratings[s.top()])
                {
                    left[i] = 1;
                }
                while (!s.empty())
                {
                    int st = s.top();
                    right[st] = a;
                    s.pop();
                    if (s.empty())
                    {
                        if (left[st] != 1)
                        {
                            left[st] = left[st-1]+1;
                        }
                    }
                    a++;
                    sum += max(left[st],right[st]);
                }
            }
            if (i==0)
            {
                left[0] = 1;
            }
            s.push(i);
        }
        int a = 1;
        while (!s.empty())
        {
            int st = s.top();
            right[st] = a;
            s.pop();
            if (s.empty())
            {
                if (left[st] != 1)
                {
                    left[st] = left[st-1]+1;
                }
            }
            a++;
            sum += max(left[st],right[st]);
        }
        return sum;
    }
};
// @lc code=end

