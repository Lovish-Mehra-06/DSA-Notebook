/*
 * Problem Link : https://leetcode.com/problems/maximum-product-of-three-numbers/description
 ! Problem Name : maximum-product-of-three-numbers
 * Problem No.  : 628
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        // Case with 3 elements only
        if (nums.size() == 3)
            return nums[0] * nums[1] * nums[2];
    }
};