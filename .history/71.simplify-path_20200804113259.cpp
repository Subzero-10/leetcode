/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (31.18%)
 * Likes:    831
 * Dislikes: 1824
 * Total Accepted:    214.8K
 * Total Submissions: 659.5K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathvector;
        bool isLetter = false;
        bool isDot = false;
        int len = path.size();
        int beginpos = 0;
        for (int i = 0; i < len; i++)
        {
            if(path[i] == '.')
            {
                isDot = true;
            }
            else if (path[i] == '/')
            {
                if (isLetter)
                {
                    isLetter = false;
                    pathvector.push_back(path.substr(beginpos, i-beginpos));
                }
                if (isDot)
                {
                    if (i-beginpos == 2)
                    {
                        pathvector.pop_back();
                    }
                    isDot = false;
                }
            }
            else
            {
                isLetter = true;
                beginpos = i;
            }
        }
        string output = "";
        for (int i = 0; i < pathvector.size(); i++)
        {
            output.append("/");
            output.append(pathvector[i]);
        }
        return output;
    }
};
// @lc code=end

