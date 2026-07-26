/*
 * Problem Link : https://leetcode.com/problems/rotate-image/description/
 ! Problem Name : Rotate Img / Sq Matrix by 90 deg.
 * Problem No.  : 48
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! ----------------------------- Initial Try ------------------- brute force by creating new matrix
// Time:  O(n^2)
// Space: O(n^2)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Create a new matrix `ans` with dimensions `cols x rows`
        vector<vector<int>> ans(cols, vector<int>(rows));

        // Fill `ans` by reading columns of the original matrix in reverse
        for (int c = 0; c < cols; c++)
        {
            for (int r = rows - 1; r >= 0; r--)
            {
                ans[c][rows - 1 - r] = matrix[r][c];
            }
        }

        // Assign `ans` back to the original matrix
        matrix = ans;
    }
};
//! Brute Force
class Solution
{
public:
    // Function to rotate the matrix 90 degrees clockwise using extra space
    vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix)
    {
        // Get the size of the square matrix
        int n = matrix.size();

        // Create a new matrix of same size to store rotated result
        vector<vector<int>> rotated(n, vector<int>(n));

        // Traverse each element of original matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Place the element at its new rotated position ------- !
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        // Return the rotated matrix
        return rotated;
    }
};
/*
! --------------------------------------------- Optimized Solutions ---------------------------------------------

? Time complexity:  O(n^2)
? Space complexity: O(1)

---
? Intuition
We want to rotate an n x n matrix 90 degrees clockwise in-place.

A very clean way to do this is to break the rotation into two simple operations:
1. Reverse the matrix vertically
2. Transpose the matrix

Why this works:
- Reversing the matrix flips it upside down
- Transposing swaps rows with columns
- Doing both together results in a 90° clockwise rotation
This method is elegant, easy to remember, and avoids extra space.
---
? Algorithm
1. Reverse the matrix vertically:
- the first row becomes the last
- the last row becomes the first
2. Transpose the matrix:
- swap elements across the main diagonal
- for all i < j, swap matrix[i][j] with matrix[j][i]
3. The matrix is now rotated 90 degrees clockwise in-place.
---
(as n x n - Sq Matrix is there) we used here  In-Place Transposition rather than Gernal Trans.
Refer: https://algo.monster/liteproblems/867



*/
// ! ------------------------- Reverse And Transpose the MATRIX -------------------
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        //  Step 1:  Reverse the ***matrix*** vertically
        reverse(matrix.begin(), matrix.end());

        // Step 2:  Transpose the matrix (as n x n - Sq Matrix is there, we used Inplace Transposition)
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
// ! -------------------------Transpose & Reverse EACH ROW -------------------------
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]); // Swap element at (i, j) with (j, i) to transpose
        }

        // Step 2: Reverse ****each row****
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

/*

! ----------------------------- Another way ------ Rotate By Four Cells -----(not so good)----------------------
https://neetcode.io/solutions/rotate-image

? Time complexity:  O(n^2)
? Space complexity: O(n^2)


? Intuition
We want to rotate an n x n matrix 90 degrees clockwise in-place.
A useful way to visualize this is to rotate the matrix layer by layer, starting from the outermost layer and moving inward.

For each square layer:
    - elements move in groups of four
    - each element in the group shifts to its new rotated position

Specifically, for a given layer:
    - top-left → top-right
    - top-right → bottom-right
    - bottom-right → bottom-left
    - bottom-left → top-left

? Algorithm
1. Initialize two pointers:
    - l = 0 → left boundary of the current layer
    - r = n - 1 → right boundary of the current layer
2. While l < r (process each layer):
3. For each position i in the current layer (from 0 to r - l - 1):
    - Identify:
        - top = l
        - bottom = r
    - Save the top-left value temporarily
    - Move bottom-left → top-left
    - Move bottom-right → bottom-left
    - Move top-right → bottom-right
    - Move saved top-left → top-right
4. After finishing one layer:
    - increment l
    - decrement r
5. Continue until all layers are rotated.


*/