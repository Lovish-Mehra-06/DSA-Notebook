/*
 * Problem Info : 1137. N-th Tribonacci Number
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/*
! ------------------------------ Recursion: ------------------------------

? Time :  3^n  ---- TLE :(
? Space:  n
*/
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 2)
        {
            return n == 0 ? 0 : 1;
            // OR This is the ternary operator, a shorter form of if-else.
            //  if (n == 0)
            //      return 0;
            //  else
            //      return 1;  // for n= 1 and n=2
        }
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

/*
! ------------------------------ Dynamic Programming (Bottom-Up)  ------------------------------

*Intuition:
Instead of working backwards from n and relying on recursion, we can build up the solution from the base cases.
Start with the known values T(0), T(1), and T(2), then iteratively compute each subsequent value until we reach T(n).
This eliminates recursion overhead and makes the computation straightforward.


? Time :  n
? Space:  n

*``for (int i = 3; i <= n; i++)``    make sure i="3" --> "<= n"
*/
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 2)
            return n == 0 ? 0 : 1; // Base cases: T(0) = 0, T(1) = 1, T(2) = 1

        vector<int> dp(n + 1, 0);    // dp[i] stores the (i)th Tribonacci number
        dp[1] = dp[2] = 1;           // Initialize base cases and dp[0] is 0 and we initialized vector elements as 0 so no need
        for (int i = 3; i <= n; i++) // Each number is the sum of the previous three numbers
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n]; // Return the nth Tribonacci number
    }
};
/*
! ------------------------------ Dynamic Programming (Top-Down)  ------------------------------

*Intuition:
The recursive solution wastes time by recomputing the same values over and over.
We can fix this with memoization: store each computed result in a cache. Before computing T(n), check if it already exists in the cache. If so, return the cached value immediately.
This transforms our exponential algorithm into a linear one, since each unique subproblem is solved only once.

? Time :  n
? Space:  n

*/
class Solution
{
    unordered_map<int, int> dp;

public:
    int tribonacci(int n)
    {
        if (n <= 2)
            return n == 0 ? 0 : 1;
        if (dp.count(n))
            return dp[n];

        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};

/*
! ------------------------------ Dynamic Programming - Space Optimized ------------------------------

*Intuition:
Notice that to compute T(n), we only need the three most recent values: T(n-1), T(n-2), and T(n-3).
We do not need to store the entire history.
By keeping just three variables (or a small fixed-size array), we can reduce space complexity from O(n) to O(1).

A clever trick uses an array of size 3 and the modulo operator.
At iteration i, we store the new value at index i % 3, which naturally overwrites the oldest value we no longer need.

? Time :  n
? Space:  1    :)


for (int i = 3; i <= n; """++i)""""
*/
class Solution
{
public:
    int tribonacci(int n)
    {
        int t[] = {0, 1, 1};
        if (n < 3)
            return t[n];

        for (int i = 3; i <= n; ++i)
        {
            t[i % 3] = t[0] + t[1] + t[2];
        }
        return t[n % 3];
    }
};

/*
! ------------------------------ Brute Force 2 ways  ------------------------------ as we know it is n=1 to 37 give in question

class Solution { // More time
public:
int tribonacci(int n) {
static const long long trib[] = {
    0,          1,         1,        2,         4,         7,
    13,         24,        44,       81,        149,       274,
    504,        927,       1705,     3136,      5768,      10609,
    19513,      35890,     66012,    121415,    223317,    410744,
    755476,     1389537,   2555757,  4700770,   8646064,   15902591,
    29249425,   53798080,  98950096, 181997601, 334745777, 615693474,
    1132436852, 2082876103};

if (n >= 0 && n <= 37)
    return trib[n];
return -1; // Handles invalid input
}
};
! same  but less time ------------------------------
class Solution { // less time
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        if (n == 5)
            return 7;
        if (n == 6)
            return 13;
        if (n == 7)
            return 24;
        if (n == 8)
            return 44;
        if (n == 9)
            return 81;
        if (n == 10)
            return 149;
        if (n == 11)
            return 274;
        if (n == 12)
            return 504;
        if (n == 13)
            return 927;
        if (n == 14)
            return 1705;
        if (n == 15)
            return 3136;
        if (n == 16)
            return 5768;
        if (n == 17)
            return 10609;
        if (n == 18)
            return 19513;
        if (n == 19)
            return 35890;
        if (n == 20)
            return 66012;
        if (n == 21)
            return 121415;
        if (n == 22)
            return 223317;
        if (n == 23)
            return 410744;
        if (n == 24)
            return 755476;
        if (n == 25)
            return 1389537;
        if (n == 26)
            return 2555757;
        if (n == 27)
            return 4700770;
        if (n == 28)
            return 8646064;
        if (n == 29)
            return 15902591;
        if (n == 30)
            return 29249425;
        if (n == 31)
            return 53798080;
        if (n == 32)
            return 98950096;
        if (n == 33)
            return 181997601;
        if (n == 34)
            return 334745777;
        if (n == 35)
            return 615693474;
        if (n == 36)
            return 1132436852;
        // if (n == 37)
        return 2082876103;
    }
};*/
