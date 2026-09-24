/*
 * Problem Info : 238. Product of Array Except Self
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

//! Approach 1: Brute Force

//! FOLLOW UP: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

/*
!  - - - Approach 2:  DIVISION   - - -

?Time complexity:  O(n)
?Space complexity: O(1) extra space.
O(n) space for the output array.*/
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
// version2 (same)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1, zeroCount = 0;
        for (int num : nums)
        {
            if (num != 0)
                prod *= num;
            else
                zeroCount++;
        }

        if (zeroCount > 1)
            return vector<int>(nums.size(), 0);

        vector<int> res(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (zeroCount > 0)
                res[i] = (nums[i] == 0) ? prod : 0;
            else
                res[i] = prod / nums[i];
        }
        return res;
    }
};

// https://neetcode.io/solutions/product-of-array-except-self

/*
! Approach 3: Prefix & Suffix
?Time complexity:  O(n)
?Space complexity: O(n)

For each index, we need the product of all elements before it and all elements after it.
Instead of recomputing the product repeatedly, we can pre-compute two helpful arrays:
 - Prefix product: pref[i] = product of all elements to the left of i
 - Suffix product: suff[i] = product of all elements to the right of i

 Then, the final answer for each index is simply:
result[i] = pref[i] × suff[i]

This works because:
 - The pref handles everything before the index
 - The suff handles everything after the index

Both pieces together form the product of all numbers except the one at that position.

*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;

        // Build prefix products: product of all elements before i
        for (int i = 1; i < n; i++)
            pref[i] = nums[i - 1] * pref[i - 1];

        // Build suffix products: product of all elements after i
        for (int i = n - 2; i >= 0; i--)
            suff[i] = nums[i + 1] * suff[i + 1];

        // Multiply prefix and suffix to get product except nums[i]
        for (int i = 0; i < n; i++)
            res[i] = pref[i] * suff[i];
        return res;
    }
};
/*
! Approach 4: Prefix & Suffix (OPTIMAL)
?Time complexity:  O(n)
?Space complexity: O(1) & O(n)

We can compute the product of all elements except the current one without using extra prefix and suffix arrays.
Instead, we reuse the result array and build the answer in two simple passes:
 - In the first pass, we fill res[i] with the product of all elements to the left of i (prefix product).
 - In the second pass, we multiply each res[i] with the product of all elements to the right of i (postfix product).

 By maintaining two running values — prefix and postfix — we avoid the need for separate pref and suff arrays.
This gives us the same logic as the previous method, but with ***O(1) extra space.***
*/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);

        // Store product of all elements to the left
        for (int i = 1; i < n; i++)
            res[i] = res[i - 1] * nums[i - 1];

        int postfix = 1;

        // Multiply with product of all elements to the right
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};