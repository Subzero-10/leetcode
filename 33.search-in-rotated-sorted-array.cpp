/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.65%)
 * Likes:    4727
 * Dislikes: 443
 * Total Accepted:    704.7K
 * Total Submissions: 2.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftpos = 0;
        int rightpos = nums.size()-1;
        int nowpos;
        int numSize = nums.size();
        int output = -1;
        bool firstIn = true;
        if (nums.empty())
        {
            return -1;
        }
        
        while (1)
        {
            if (nums[leftpos] == target)
            {
                output = leftpos;
                break;
            }
            if (nums[rightpos] == target)
            {
                output = rightpos;
                break;
            }
            if ((int)(rightpos - leftpos)/2 == 0)
            {
                break;
            }

                if (nums[leftpos]>target&&nums[rightpos]>target)
                {
                    nowpos = (rightpos - leftpos)/2 + leftpos;
                    if (nums[nowpos]<target)
                    {
                        leftpos = nowpos;
                    }
                    else
                    {
                        if (nums[nowpos]>nums[rightpos])
                        {
                            leftpos = nowpos;
                        }
                        else
                        {
                            rightpos = nowpos;
                        }
                    }
                }
                else if (nums[leftpos]<target&&nums[rightpos]>target)
                {
                    nowpos = (rightpos - leftpos)/2 + leftpos;
                    if (nums[nowpos]>target)
                    {
                        rightpos = nowpos;
                    }
                    else
                    {
                        leftpos = nowpos;
                    }
                }
                else if (nums[leftpos]<target&&nums[rightpos]<target)
                {
                    nowpos = (rightpos - leftpos)/2 + leftpos;
                    if (nums[nowpos]>target)
                    {
                        rightpos = nowpos;
                    }
                    else
                    {
                        if (nums[nowpos]>nums[rightpos])
                        {
                            leftpos = nowpos;
                        }
                        else
                        {
                            rightpos = nowpos;
                        }
                    }
                }
                else
                {
                    break;
                }     
        }
        return output;
    }
};
// @lc code=end

