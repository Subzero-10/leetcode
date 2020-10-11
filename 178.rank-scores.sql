--
-- @lc app=leetcode id=178 lang=mysql
--
-- [178] Rank Scores
--

-- @lc code=start
# Write your MySQL query statement below
select Score,dense_rank() over(order by Score desc) as 'Rank' from Scores;
-- @lc code=end

