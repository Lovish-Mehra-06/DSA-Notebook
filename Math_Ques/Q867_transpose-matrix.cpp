/*
 * Problem Link : https://leetcode.com/problems/transpose-matrix/
 ! Problem Name : Transpose Martrix
 * Problem No.  : 867
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! ------------------ Solution------------------

?  Time  :  O(m × n)
?  Space :  O(m × n) (for the new transposed matrix)
*/
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                ans[j][i] = matrix[i][j];
        }
        return ans;
    }
};

/* Doubts

! ------------------ 1. Code Error ------------------
* Correct Code:
*       int m = matrix.size();
*       int n = matrix[0].size();
*       vector<vector<int>> ans(n, vector<int>(m));

? Why not  ` vector<vector<int>> ans(); `

This is not creating a matrix.
It is interpreted as a function declaration (known as the Most Vexing Parse).
The compiler reads it as:
vector<vector<int>> ans();
➡️ "ans is a function that takes no arguments and returns vector<vector<int>>."
So ans is not a variable.

! ------------------ 2. Incorrect approach for non-square matrices: ------------------
refer `48. rotate img`.. we used there because matrix was sq ie n x n so we just swapped in-place

# This ONLY works for square matrices!
def transpose(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    return matrix
Solution: Always create a new matrix for the transpose unless you're certain you're dealing with square matrices:
*/