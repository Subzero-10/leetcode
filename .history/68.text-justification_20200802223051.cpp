/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (26.22%)
 * Likes:    698
 * Dislikes: 1594
 * Total Accepted:    138.4K
 * Total Submissions: 500.4K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0;
        int right = 0;
        int lennow = -1;
        int len = words.size();
        vector<string> output;
        for (int i = 0; i < len; i++)
        {
            printf("%d",i);
            if (i == len)
            {
                string temstring;
                while (left != right)
                {
                    temstring.append(words[left]);
                    temstring.append(" ");
                    left++;
                }
                temstring.append(words[right]);
                string temstring2(maxWidth - (int)temstring.size(), ' ');
                temstring.append(temstring2);
                output.push_back(temstring);
            }
            else
            {
                lennow += words[i].size() + 1;
                if (lennow > maxWidth)
                {
                    right--;
                    lennow -= words[i].size() + 1;
                    if (right == left)
                    {
                        string temstring(maxWidth - (int)words[left].size(), ' ');
                        words[left].append(words[temstring]);
                        output.push_back(words[left]);
                    }
                    else
                    {
                        lennow -= right-left;
                        int spaceBaseNum = (words[left].size() - lennow)/(right-left);
                        int spacePlusNum = (words[left].size() - lennow)%(right-left);
                        string temstring;
                        for (int j = 0; j < right-left; j++)
                        {
                            temstring.append(words[left+j]);
                            if (j<spacePlusNum)
                            {
                                string temstring2(spaceBaseNum+1, ' ');
                                temstring.append(words[temstring2]);
                            }
                            else
                            {
                                string temstring2(spaceBaseNum, ' ');
                                temstring.append(words[temstring2]);
                            }
                        }
                        temstring.append(words[right]);
                        output.push_back(temstring);
                    }
                    right++;
                    left = right;
                }
                else
                {
                    right++;
                }
            }
            
            
        }
        return output;
    }
};
// @lc code=end

