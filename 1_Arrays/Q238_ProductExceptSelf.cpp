/*
 * Problem Info : 238. Product of Array Except Self
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

//
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        int zeros = 0, idx = -1, prod = 1;

        for (int i = 0; i < arr.size(); ++i) // Count zeros and track the index of the zero
        {
            if (arr[i] == 0)
            {
                zeros++;
                idx = i;
            }
            else
                prod *= arr[i];
        }

        vector<int> res(arr.size(), 0);
        if (zeros == 0) // If no zeros, calculate the product for all elements
        {
            for (int i = 0; i < arr.size(); i++)
                res[i] = prod / arr[i];
        }
        else if (zeros == 1) // If one zero, set product only at the zero's index
            res[idx] = prod;

        return res;
    }
};

//!!!! FOLLOW UP: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)