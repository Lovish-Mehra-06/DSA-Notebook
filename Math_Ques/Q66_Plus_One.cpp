/*
 * Problem Link : https://leetcode.com/problems/plus-one/
 ! Problem Name : plus-one/
 * Problem No.  : 66
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! My Code with edge case hint taken by ai
? Time: O(n)
? Space: O(1) extra space (excluding the returned vector)

One small improvement: carry isn't really needed as a counter.
You only need to know whether the carry is still present.  But your current solution is accepted and correct.
*/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                carry++;
                digits[i] = 0;
            }
            else
            {
                carry = 0;
                digits[i] += 1;
                break;
            }
        }
        // Edge case when [9], or [9,9]  --add the leading 1.   -- by checking carry after loop
        if (carry)
        {
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};

/*
! optimal code

? Time:  O(n)
? Space: O(1) extra space (ignoring output storage).
*/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};