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
        int right = len-1;
        int need = -1;
        for (int i = 0; i < len; i++)
        {
            if (isLeft)
            {
                if (s[left]-'a'>= 0 && s[left]-'a'<= 25)
                {
                    need = s[left]-'a';
                    isLeft = false;
                }
                else if (s[left]-'A'>= 0 && s[left]-'A'<= 25)
                {
                    need = s[left]-'A';
                    isLeft = false;
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
                    printf("%d",need);
                    if (need == s[right]-'a')
                    {
                        isLeft = true;
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

