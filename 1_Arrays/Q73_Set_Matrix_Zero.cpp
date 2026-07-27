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
!  ------------- Brute Force 1 : O( m * n * (m+n) ) time, O(1) space -------------
Time Complexity: O(m * n * (m + n)), We iterate through every cell (m * n), and for each zero,
we potentially mark its entire row (O(n)) and column (O(m)), leading to O(m * n * (m + n)) overall.
?Time Complexity  : O(mn(m+n))
                 = O(m²n + mn²)
                 for sq matrix m=n  then it is O(n^3)

?Space Complexity : O(1)

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
! -------------  Brute Force 2 : O(m * n) time, O(m + n) space -------------
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
! -------------------------- Optimal Approach : O(m * n) time, O(1) space --------------------------
- Use the first row and first column of the matrix itself to store the zeroing information.
- First, determine if the first row and first column need to be zeroed by checking for zeros in them.
- Then, traverse the rest of the matrix. If you find a zero, mark the corresponding first row and first column cells as zero.
- Finally, traverse the matrix again and set cells to zero based on the markers in the first row and first column. Don't forget to handle the first row and first column separately at the end based on the initial checks.

?   Time Complexity  : O(M × N),    traverse the matrix a constant number of times.
?   Space Complexity : O(1),        uses the first row and first column as markers.

*### Intuition

Instead of using extra row and column arrays, use the first row and first
column of the matrix itself to store which rows and columns need to be
zeroed. Since the first row and column are used as markers, store their
original state separately using two boolean flags.

*### Algorithm
1. Check the **first row** for any `0` and store the result in `firstRowZero`.
2. Check the **first column** for any `0` and store the result in `firstColZero`.
3. Traverse the remaining matrix (excluding the first row and first column):
   - If `matrix[i][j] == 0`:
     - Mark its row by setting `matrix[i][0] = 0`.
     - Mark its column by setting `matrix[0][j] = 0`.
4. Traverse the remaining matrix again:
   - If `matrix[i][0] == 0` or `matrix[0][j] == 0`, set `matrix[i][j] = 0`.
5. If `firstRowZero` is `true`, set every element in the **first row** to `0`.
6. If `firstColZero` is `true`, set every element in the **first column** to `0`.
7. The matrix is now updated in-place.

*### Pseudocode
firstRowZero = check if first row contains 0
firstColZero = check if first column contains 0

for each cell (i, j) excluding first row and first column:
    if matrix[i][j] == 0:
        matrix[i][0] = 0
        matrix[0][j] = 0

for each cell (i, j) excluding first row and first column:
    if matrix[i][0] == 0 OR matrix[0][j] == 0:
        matrix[i][j] = 0

if firstRowZero:
    make first row all 0

if firstColZero:
    make first column all 0


    ! ------------- Short Version -------------
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (firstRowZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};

//! ------------- Code With Comments -------------
class Solution
{
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0 (Optimal O(1) space)
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Get dimensions of matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Flag to track if first row should be zeroed
        bool firstRowZero = false;
        // Flag to track if first column should be zeroed
        bool firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns in first row/column
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowZero)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (firstColZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

//
//
//
// --------------------------------- Driver Code(s) ---------------------------------
//
//
//
int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    obj.setZeroes(matrix);
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

// int main()
// {
//     // Create the matrix
//     vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

//     // Create Solution object
//     Solution obj;
//     // Call function
//     obj.setZeroes(matrix);

//     // Print the updated matrix
//     for (auto row : matrix)
//     {
//         for (auto val : row)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }