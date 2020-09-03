/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        bool isLeft = true;
        int len = s.size();
        int left = 0;
        int right = len;
        int need = -1;
        for (int i = 0; i < len; i++)
        {
            if (isLeft)
            {
                if (s[left]-'a'>= 0 && s[left]-'a'<= 25)
                {
                    need = s[left]-'a';
                    isLeft = false;
                    right--;
                }
                else if (s[left]-'A'>= 0 && s[left]-'A'<= 25)
                {
                    need = s[left]-'A';
                    isLeft = false;
                    right--;
                }
                else if (s[left]-'0'>= 0 && s[left]-'0'<= 9)
                {
                    need = '0' - s[left] - 1;
                    isLeft = false;
                    right--;
                }
                else
                {
                    left++;
                }
            }
            else
            {
                if (s[right]-'a'>= 0 && s[right]-'a'<= 25)
                {
                    if (need == s[right]-'a')
                    {
                        isLeft = true;
                        left++;
                    }
                    else
                    {
                        return false;
                    }
                    
                }
                else if (s[right]-'A'>= 0 && s[right]-'A'<= 25)
                {
                    if (need == s[right]-'A')
                    {
                        isLeft = true;
                        left++;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[right]-'0'>= 0 && s[right]-'0'<= 9)
                {
                    if (need == '0' - s[right] - 1)
                    {
                        isLeft = true;
                        left++;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    right--;
                }
            }
        }
        return true;
    }
};
// @lc code=end

