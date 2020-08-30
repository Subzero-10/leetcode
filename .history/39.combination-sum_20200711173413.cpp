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
        findAns(candidates, target, 0);
        return ansSet;
    }
private:
    // 需要的参数尽量放在函数中
    void findAns(vector<int>& candidates, int target, int startIndex)
    {
        //结束条件
        if(target == 0) {
            ansSet.push_back(oneAns);
            return;
        }
        //减枝
        if(target < 0) return;
        // i从startIndex，传入可以避免更深层的节点使用其父节点及其父节点之上的值(总的来说就是之前用过的值)，避免答案重复
        for(int i = startIndex; i < candidates.size(); ++i) {
            if(target >= 0) {
                oneAns.push_back(candidates[i]);
                // 得到一个加法因子后，target值要变小
                findAns(candidates, target-candidates[i], i);
                //撤销操作，以免上次结果影响下次的搜索结果
                oneAns.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> ansSet;
    vector<int> oneAns;
};

// @lc code=end

