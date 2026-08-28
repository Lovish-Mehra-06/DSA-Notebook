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

/*
TODO:   Optimal Solution

?   Time:  O(n)
?   Space: O(1)

* Algorithm: First Missing Positive

1. Start.
2. Let `n = nums.size()`.
3. Traverse the array from `i = 0` to `n-1`.
4. For each element, keep swapping it to its correct position while:
   - `nums[i] > 0`
   - `nums[i] <= n`
   - `nums[i]` is not already at its correct position.
5. The correct position of a number `x` is index `x - 1`.
6. After rearranging, traverse the array again.
7. For each index `i`:
   - If `nums[i] != i + 1`, return `i + 1`.
8. If every position contains its correct value, return `n + 1`.
9. Stop.

 Example
nums = [3, 4, -1, 1]

After rearranging:
[1, -1, 3, 4]

Index:     0   1   2   3
Expected:  1   2   3   4
Actual:    1  -1   3   4
                ↑
          missing = 2
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
