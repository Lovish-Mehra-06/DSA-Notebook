/*
 * Problem Link : https://leetcode.com/problems/pascals-triangle/
 ! Problem Name : Pascal's Triangle
 * Problem No.  : 118
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/pascals-triangle/
// https://neetcode.io/solutions/pascals-triangle

// TODO:  Important Formulas:
//? 1. Pascal Identity (DP)
//  Pascal[i][j] = Pascal[i-1][j-1] + Pascal[i-1][j]

//? 2. Binomial Coefficient
// nCr = n! / ( r! * (n-r)! )

//? 3. Optimized Recurrence
// nCr = nC(r-1) * (n-r+1) / r

//! -------------------------------- Mathematical / Combinatorial Approach ------------------------- without factorials
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        // Stores the complete Pascal Triangle
        vector<vector<int>> ans;

        // Generate each row one by one
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row;

            // First element of every row is always 1
            int val = 1;
            row.push_back(val);

            // Generate remaining elements using
            // nCr = previous_value * (n-r+1) / r
            for (int k = 1; k < i; k++)
            {

                // Compute next binomial coefficient
                val = val * (i - k) / k;

                // Add value to current row
                row.push_back(val);
            }

            // Add completed row to answer
            ans.push_back(row);
        }
        return ans;
    }
};

//! -------------------------------- 2. Brute Force ------------------    RUN TIME ERROR
// Complexity	    Value
// Time	        O(n^3) approx
// Space	    O(1) auxiliary
class Solution
{
public:
    int factorial(int n) // Function to calculate factorial
    {
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }
        return fact;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;          // Stores the complete Pascal Triangle
        for (int i = 0; i < numRows; i++) // Generate each row one by one
        {
            vector<int> row;
            for (int k = 0; k <= i; k++) // Generate every element using nCr formula
            {
                // nCr = n! / (r! * (n-r)!)
                int val = factorial(i) /
                          (factorial(k) * factorial(i - k));
                row.push_back(val); // Add value to current row
            }
            ans.push_back(row); // Add completed row to answer
        }
        return ans;
    }
};
/*
! -------------------------------- 2. Brute Force ------------------    *FIXED*

apply the formula of binomial coefficient i.e. (r-1)!/(c-1)!(r-c)!.

*Instead of computing full factorials (which can overflow and be slow), we can multiply and divide in a loop to compute the coefficient efficiently.

?   Time Complexity  : O(N³), each element is computed using the nCr formula.
?   Space Complexity : O(N²), to store the Pascal's Triangle.

?   Auxiliary Space  : O(1)
?   Total Space      : O(N²), including the output.


*/
class Solution
{
public:
    long long findPascalElement(int r, int c)
    {
        int n = r - 1;
        int k = c - 1;

        long long result = 1;

        for (int i = 0; i < k; i++)
        {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> row;

            for (int k = 0; k <= i; k++)
            {
                row.push_back(findPascalElement(i + 1, k + 1));
            }
            ans.push_back(row);
        }
        return ans;
    }
};

//! -------------------------------- 3. Dynamic Programming ------------------ Ai
//!   Time  complexity:  O(numRows^2)
//!   Space complexity:  O(numRows^2)
//? Approach
// This is the Dynamic Programming (Bottom-Up Tabulation) approach.

// It uses Pascal Identity:
// Pascal[i][j]=Pascal[i−1][j−1]+Pascal[i−1][j]

//? Main Idea
// Every middle element is the sum of:
// upper-left element
// upper-right element

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++)
        {
            // Create row filled with 1s
            vector<int> row(i + 1, 1);

            // Fill middle elements using previous row
            for (int j = 1; j < i; j++)
            {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            // Store row in result
            res.push_back(row);
        }

        return res;
    }
};

//! -------------------------------- 4. Space-Optimized Dynamic Programming ------------------ Ai
//!   Time  complexity:  O(numRows^2)
//!   Auxiliary Space complexity:  O(numRows)
//!   Total Space complexity:  O(numRows^2)

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        vector<int> prev; // Stores only previous row

        for (int i = 0; i < numRows; i++)
        {

            vector<int> row(i + 1, 1); // Current row initialized with 1s

            for (int j = 1; j < i; j++) // Compute middle elements using previous row
            {
                row[j] = prev[j - 1] + prev[j];
            }

            ans.push_back(row); // Store current row

            prev = row; // Update previous row
        }

        return ans;
    }
};
