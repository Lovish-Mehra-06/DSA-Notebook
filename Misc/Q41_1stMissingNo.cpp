/*
 * Problem Link : https://leetcode.com/problems/first-missing-positive/
 ! Problem Name : 1st Missing No.
 * Problem No.  : 41
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Hard
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! Brute Force Approach
*/
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int ans = 1;
        while (true)
        {
            bool present = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == ans)
                {
                    present = 1;
                    ans += 1;
                    break;
                }
            }
            if (!present)
                break;
        }
        return ans;
    }
};
/*
! Sorting

Sorting: O(n log n)
Scan: O(n)
Overall: O(n log n)
Extra space: O(1) (ignoring the implementation details of sort)*/
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ans = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ans)
                ans++;
        }

        return ans;
    }
};

/*Optimal Solution
 */

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        // Place each positive integer at its correct position
        // nums[i] should be at index nums[i] - 1
        // For example: 1 should be at index 0, 2 should be at index 1, etc.
        for (int i = 0; i < n; ++i)
        {
            // Keep swapping while:
            // 1. Current number is positive
            // 2. Current number is within valid range [1, n]
            // 3. Current number is not already at its correct position
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                // Swap current number to its correct position
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first position where the number doesn't match its expected value
        for (int i = 0; i < n; ++i)
        {
            // Position i should contain value i + 1
            if (nums[i] != i + 1)
            {
                return i + 1; // Return the first missing positive
            }
        }

        // All positions [0, n-1] contain correct values [1, n]
        // So the first missing positive is n + 1
        return n + 1;
    }
};
