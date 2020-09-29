/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int helper(vector<int>& v1,vector<int>& v2, int len1, int len2){
        for (int i = 0; i < len1; i++)
        {
            if (v1[i]>v2[i])
            {
                return 1;
            }
            else if (v1[i]<v2[i])
            {
                return -1;
            }
        }
        for (int i = len1; i < len2; i++)
        {
            if (v2[i] != 0)
            {
                return -1;
            }
        }
        return 0;
        
    }
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1);
        istringstream iss2(version2);
        vector<int> v1;
        vector<int> v2;
        string tem;
        while (getline(iss1,tem,'.'))
        {
            v1.push_back(stoi(tem));
        }
        while (getline(iss2,tem,'.'))
        {
            v2.push_back(stoi(tem));
        }
        int len1 = v1.size();
        int len2 = v2.size();
        return len1<=len2 ? helper(v1,v2, len1,len2) : (0-helper(v2,v1, len2,len1));
    }
};
// @lc code=end

