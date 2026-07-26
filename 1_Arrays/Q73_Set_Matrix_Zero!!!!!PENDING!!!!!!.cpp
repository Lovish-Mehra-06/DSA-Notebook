/*
 * Problem Link : https://leetcode.com/problems/set-matrix-zeroes/
 ! Problem Name : Set Matrix Zeroes
 * Problem No.  : 73
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
!  ------------- Brute Force 1 : O(m*n) time, O(1) space -------------
- Traverse the entire matrix.
- If an element is zero:
   - Mark all elements in its row (except already zero) as -1.
   - Mark all elements in its column (except already zero) as -1.
- Once the full traversal is complete, replace all -1 with 0.
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If current cell is zero
                if (matrix[i][j] == 0)
                {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++)
                    {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++)
                    {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) // Second pass: replace all -1 markers with 0
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};

/*
! -------------  Brute Force 2 : O(m*n) time, O(m*n) space -------------
Instead of marking directly in the matrix, keep two extra arrays:
  - One to track which rows need to be zeroed.
  - One to track which columns need to be zeroed.
When you find a zero, mark its row index in the row array and column index in the col array. After the scan, you go back and zero out all marked rows and columns. This avoids accidental over-zeroing in the first pass.
    Create a row array of size m (rows) and a col array of size n (columns) initialized to false.
    First pass: Traverse the matrix, and when you find a zero:
            Mark the corresponding row index in row array.
            Mark the corresponding col index in col array.
    Second pass: Traverse the matrix again, and if either the row or col is marked, set the cell to zero.
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix) // Function to set entire row and column to 0 if an element in the matrix is 0
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0); // Create row marker array
        vector<int> col(n, 0); // Create column marker array

        for (int i = 0; i < m; i++) // First pass: mark rows and columns that need to be zeroed
        {
            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == 0) // If element is zero, mark its row and column
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) // Second pass: set cells to zero based on markers
        {
            for (int j = 0; j < n; j++)
            {

                if (row[i] == 1 || col[j] == 1) // If the row or column is marked, set cell to zero
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
! ------------- Optimal Approach : O(m*n) time, O(1) space -------------
- Use the first row and first column of the matrix itself to store the zeroing information.
- First, determine if the first row and first column need to be zeroed by checking for zeros in them.
- Then, traverse the rest of the matrix. If you find a zero, mark the corresponding first row and first column cells as zero.
- Finally, traverse the matrix again and set cells to zero based on the markers in the first row and first column. Don't forget to handle the first row and first column separately at the end based on the initial checks.
*/
// class Solution
// {

//
//
//
//

// --------------------------------- Driver Code ---------------------------------
int main()
{
    // Create the matrix
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    // Create Solution object
    Solution obj;
    // Call function
    obj.setZeroes(matrix);

    // Print the updated matrix
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}