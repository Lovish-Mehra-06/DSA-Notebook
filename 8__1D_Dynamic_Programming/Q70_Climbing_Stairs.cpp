/*
 * Problem Info : 70. Climbing Stairs
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

// ! ---------------------- dynamic-programming- Bottom Up  --------------- n n ---------------
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
//* it is --> fib(n+1)
// class Solution
// {
// public:
//     int fib(int n)
//     {
//         if (n <= 1) // base cases
//             return n;
//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; i++)
//             dp[i] = dp[i - 1] + dp[i - 2];
//         return dp[n];
//     }

//     int climbStairs(int n)
//     {
//         return fib(n + 1);
//     }
// };

// ! ---------------------- dynamic-programming-top-down  ---------------- n n ---------------

// ! ---------------------------------- Recursion  --------------------  2^n n ---------------

// ! -------------------- dynamic-programming Space Optimized ------------ n 1 :) ------------ just 2 var used

// ! ---------------------------------- Matrix Exponential  ------------ logn 1 --------------
/*
! ----------------------------------------- Math  ---------------------- logn 1 --------------

*Intuition
The number of ways to climb stairs follows the Fibonacci sequence.
There is a ""closed-form mathematical formula (called Binet’s Formula)"" that directly computes the nth Fibonacci number using powers and square roots, without loops or recursion.

This works because Fibonacci numbers can be expressed using two constants derived from the golden ratio.

*Algo:
1. Compute the golden ratio φ = (1 + √5) / 2 and its conjugate ψ = (1 − √5) / 2.
2. Use Binet’s Formula to compute the Fibonacci value directly.
3. Since climbing stairs corresponds to Fib(n+1), adjust n accordingly.
4. Round the result to handle floating-point precision.

*/
class Solution
{
public:
    int climbStairs(int n)
    {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;

        n++;
        return round((pow(phi, n) - pow(psi, n)) / sqrt5);
    }
};