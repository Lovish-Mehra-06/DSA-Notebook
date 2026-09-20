/*
 * Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
 ! Problem Name : Longest Consecutive Sequence
 * Problem No.  : 128
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
! -----------------------Tried Own----------------- + edge case hint given by ai--------
!------- Better (Sorting) --------
?   Time Complexity  : `O(N log N)`    ; sorting takes O(N log N) and the traversal takes O(N).
?   Space Complexity : `O(1)`          ; ignoring the space used by the sorting algorithm.

*### Intuition

Sort the array so that consecutive numbers become adjacent. Then traverse the
sorted array, skip duplicates, count the length of each consecutive sequence,
and keep track of the maximum streak.

*### Algorithm

1. If the array is empty, return `0`.
2. Sort the array in ascending order.
3. Initialize `currentStreak = 1` and `longestStreak = 1`.
4. Traverse the sorted array:
   - If the current element is a duplicate, skip it.
   - If it is consecutive (`nums[i] == nums[i-1] + 1`), increment `currentStreak`.
   - Otherwise, update `longestStreak` and reset `currentStreak` to `1`.
5. Return the maximum of `currentStreak` and `longestStreak`.
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longest_streak = 1;
        int current_streak = 1;

        int n = nums.size();
        if (n == 0) // Edge Case
            return 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1]) // Skip Duplicates
                continue;
            else if (nums[i] == nums[i - 1] + 1) // Increase Streak
                current_streak++;
            else
            {
                longest_streak = max(current_streak, longest_streak);
                current_streak = 1;
            }
        }
        return max(current_streak, longest_streak);
    }
};

/*
! ---------------------------------Optimal Solution------------------------------

?   Time Complexity  : `O(n)`
?   Space Complexity : `O(n)`

*### Algorithm
Insert all elements into an unordered_set.
For each number, check if num - 1 exists.
If it doesn't, num is the start of a sequence.
Keep checking num + 1, num + 2, etc.
Track the maximum sequence length.
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int num : st)
        {
            if (!st.count(num - 1))
            {
                int curr = num;
                int len = 1;

                while (st.count(curr + 1))
                {
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};