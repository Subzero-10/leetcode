/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (53.00%)
 * Likes:    3611
 * Dislikes: 186
 * Total Accepted:    696.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        map<vector<int>,vector<string>> mapAnagrams;
        map<vector<int>,vector<string>>::iterator it;
        for(int i = 0; i < (int)strs.size(); i++)
        {
            vector<int> code(26,0);
            for(int j = 0; j < (int)strs[i].size(); j++)
            {
                code[strs[i][j]-'a']++;
            }
            mapAnagrams[code].push_back(strs[i]);
        }
        it = mapAnagrams.begin();
        while(it != mapAnagrams.end()){
            output.push_back(it->second);
            it++;
        }
        return output;
    }
};
// @lc code=end

