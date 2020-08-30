/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    1737
 * Dislikes: 65
 * Total Accepted:    325.1K
 * Total Submissions: 682.3K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        set<vector<int>> s(output.begin(), output.end());
        output.assign(s.begin(), s.end());
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
        else if (nowTarget - candidates[nowI]< candidates[nowI])
        {
            return 0;
        }
        else
        {
            int addNew = 0;
            int i = nowI+1;
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

