/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (38.24%)
 * Likes:    2431
 * Dislikes: 4307
 * Total Accepted:    630.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is equal to m + n) to
 * hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1.length == m + n
 * nums2.length == n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1);
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (b == nums2.size())
            {
                nums3[i] = nums1[a++];
            }
            else if (a == nums1.size()-nums2.size())
            {
                nums3[i] = nums1[b++];
            }
            else
            {
                if (nums1[a]<nums2[b])
                {
                    nums3[i] = nums1[a++];
                }
                else
                {
                    nums3[i] = nums1[b++];
                }
            }
        }
        nums1.assign(nums3.begin(), nums3.end());
    }
};
// @lc code=end

