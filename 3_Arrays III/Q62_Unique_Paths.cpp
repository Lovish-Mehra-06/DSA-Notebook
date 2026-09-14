/*
 * Problem Info : 62. Unique Paths
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
    }
};

/*
Let:
d = m−1
r  =n−1
So we need to find the number of ways to arrange d identical items and r identical items.

The number of arrangements is:
(d+r)! / d! r!
​
Further, since:... read https://leetcode.com/problems/unique-paths/solutions/8495748/java-100-math-combinations-by-anshikkuma-4vkp/

( dd+r​ )=( rd+r​ )
we use min(d,r) to reduce the number of iterations.

Complexity
?   Time complexity: (O(\min(m,n)))
?   Space complexity: (O(1))
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int d = m - 1;
        int r = n - 1;
        int k = min(d, r);

        long result = 1;

        // Calculate the combination using the smaller value.
        for (int i = 1; i <= k; i++)
        {
            result = result * (d + r - k + i) / i;
        }

        return result;
    }
};