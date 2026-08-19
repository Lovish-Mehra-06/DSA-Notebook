/*
 * Problem Link : https://leetcode.com/problems/powx-n/
 ! Problem Name : Pow(x, n)
 * Problem No.  : Problem No
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <cmath>
using namespace std;

// Using Pow()
class Solution
{
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};

//! Multiplying 'n' times
// ?   Problem time limit exceds
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                ans *= x;
            }
        }
        else if (n < 0)
        {
            for (int i = 0; i < -n; i++)
            {
                ans /= x;
            }
        }

        return ans;
    }
};

/* Fixed TLE's
For:
n = 2147483647
your loop runs 2.1 billion times.
! You need Binary Exponentiation, which reduces it to about 31 iterations.  omg

?  Time:  O(log |n|)
?  Space: O(1)
Uses Binary Exponentiation / Fast Power
Handles n = INT_MIN safely using long long
*/
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;

        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N > 0)
        {
            if (N % 2 == 1)
                ans *= x;

            x *= x;
            N /= 2;
        }

        return ans;
    }
};

//!  Optimal Solution (ANSWER)
class Solution
{
private:
    // Function to calculate power
    // of 'x' raised to 'n'
    double power(double x, long n)
    {
        // Base case: anything raised to 0 is 1
        if (n == 0)
            return 1.0;

        // Base case: anything raised to 1 is itself
        if (n == 1)
            return x;

        // If 'n' is even
        if (n % 2 == 0)
        {
            // Recursive call: x * x, n / 2
            return power(x * x, n / 2);
        }
        // If 'n' is odd
        // Recursive call: x * power(x, n-1)
        return x * power(x, n - 1);
    }

public:
    // Function to calculate x raised to n
    double myPow(double x, int n)
    {
        // Store the value of n in a separate variable
        int num = n;

        // If n is negative
        if (num < 0)
        {
            // Calculate the power of -n and take reciprocal
            return (1.0 / power(x, -1 * num));
        }
        // If n is non-negative
        return power(x, num);
    }
};