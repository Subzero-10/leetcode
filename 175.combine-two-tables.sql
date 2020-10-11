--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
# Write your MySQL query statement below

select FirstName,LastName,City,State from Person a left join Address b on a.PersonId = b.PersonId;
-- @lc code=end

