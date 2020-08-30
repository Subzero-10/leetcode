/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.86%)
 * Likes:    1340
 * Dislikes: 519
 * Total Accepted:    200.6K
 * Total Submissions: 561.6K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string s containing only digits. Return all possible valid IP
 * addresses that can be obtained from s. You can return them in any order.
 * 
 * A valid IP address consists of exactly four integers, each integer is
 * between 0 and 255, separated by single points and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses. 
 * 
 * 
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "1111"
 * Output: ["1.1.1.1"]
 * Example 4:
 * Input: s = "010010"
 * Output: ["0.10.0.10","0.100.1.0"]
 * Example 5:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 3000
 * s consists of digits only.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> output;
        if ((int)s.size()>12||(int)s.size()<4)
        {
            return output;
        }
        return restoreIp(s, 0, 0);
    }
    vector<string> restoreIp(string s, int i, int begin)
    {
        vector<string> output;
        string tem = s.substr(begin, s.size()-begin);
        if (i==3)
        {
            if ((int)tem.size() == 1)
            {
                output.push_back(tem);
            }
            else if ((int)tem.size() == 2)
            {
                if (tem[0] != '0')
                {
                    output.push_back(tem);
                }
            }
            else if ((int)tem.size() == 3)
            {
                if (tem[0] == '1')
                {
                    output.push_back(tem);
                }
                else if (tem[0] == '2')
                {
                    if (tem[1] == '5')
                    {
                        if (tem[2]-'0' <= 5 )
                        {
                            output.push_back(tem);
                        }
                    }
                    else if (tem[1]-'0' < 5)
                    {
                        output.push_back(tem);
                    }
                }
            }
            return output;
        }
        else
        {
            for (int j = 1; j <= 3; j++)
            {
                if ((int)s.size()-begin>j+3*(3-i)||(int)s.size()-begin<(3-i+j))
                {
                    continue;
                }
                tem = s.substr(begin, j);
                vector<string> outputtem(restoreIp(s, i+1, begin+j));
                if (outputtem.empty())
                {
                    continue;
                }
                if (j==2)
                {
                    if (tem[0] == '0')
                    {
                        continue;
                    }
                }
                else if (j==3)
                {
                    if (tem[0] == '0')
                    {
                        continue;
                    }
                    else if (tem[0] == '2'&&tem[1] == '5'&&(tem[2]-'0' > 5))
                    {
                        continue;
                    }
                    else if (tem[0] == '2'&&tem[1]-'0' > 5)
                    {
                        continue;
                    }
                    else if (tem[0]-'0' > 2)
                    {
                        continue;
                    }
                }
                vector<string>::iterator it;
                for(it=outputtem.begin();it!=outputtem.end();it++)
                {
                    *it = tem + "." + *it;
                }
                output.insert(output.end(), outputtem.begin(), outputtem.end());
            }
            return output;
        }
        
    }
};
// @lc code=end

