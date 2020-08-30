/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (53.54%)
 * Likes:    3788
 * Dislikes: 115
 * Total Accepted:    537.1K
 * Total Submissions: 967.1K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = (int)candidates.size();
        vector<vector<int>> output;
        sort(candidates.begin(),candidates.end());
        for (int i = 0; i < len; i++)
        {
            if (candidates[i]>target)
            {
                continue;
            }
            else
            {
                findResult(candidates, i, target, output);
            }
        }
        return output;
    }
    int findResult(vector<int>& candidates, int nowI, int nowTarget,vector<vector<int>>& output)
    {
        vector<int> lastVector;
        if (nowI == (int)candidates.size())
        {
            return 0;
        }
        
        if (nowTarget == candidates[nowI])
        {
            lastVector.push_back(nowTarget);
            output.push_back(lastVector);
            return 1;
        }
        else if (nowTarget - candidates[nowI] < candidates[nowI])
        {
            return 0;
        }
        else
        {
            int addNew = 0;
            int i = nowI;
            while (i<(int)candidates.size())
            {
                int lastAdd = findResult(candidates, i, nowTarget-candidates[nowI], output);
                int outputLen = (int)output.size();
                while (lastAdd)
                {
                    output[outputLen-lastAdd].push_back(candidates[nowI]);
                    lastAdd--;
                    addNew++;
                }
                i++;
            }
            return addNew;
        }
    }
};
// @lc code=end

