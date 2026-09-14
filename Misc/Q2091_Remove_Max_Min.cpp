/*
 * Problem Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
 ! Problem Name : 2091. Removing Minimum and Maximum From Array
 * Problem No.  : 2091
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! Approach:1 Tried

Using 1 loop to find max and min and their respective indexes
now ans could be found out from their indexes
*/
class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int max_element = nums[0], min_element = nums[0], max_index = 0, min_index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max_element)
            {
                max_element = nums[i];
                max_index = i;
            }

            else if (nums[i] < min_element)
            {
                min_element = nums[i];
                min_index = i;
            }
        }

        // Get Min Deletions:
        int ans = 0;
        if (max_index + min_index > n)
        {
            if (min_index < n - max_index)
            {
                ans += min_index;
            }
            else if (min_index > n - max_index)
            {
                ans += n - max_index;
            }
        }
    }
};