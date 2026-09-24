/*
 * Problem Info : 36_Valid Sudoku
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<int> seen(9);
            for (int j = 0; j < 9; j++)
            {
                int ele = board[i][j];
                if (ele == '.')
                    continue;
                if (seen.count(ele))
                    return false;
                seen.insert(ele);
            }
        }

        for (int i = 0; i < 9; i++)
        {
            unordered_set<int> seen(9);
            for (int j = 0; j < 9; j++)
            {
                int ele = board[j][i];
                if (ele == '.')
                    continue;
                if (seen.count(ele))
                    return false;
                seen.insert(ele);
            }
        }

        // Check Each Sq:
        for (int square = 0; square < 9; square++)
        {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.')
                        continue;
                    if (seen.count(board[row][col]))
                        return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};

/*
!  - - - - - More Optimal solution    1 1   - - - -
? Time: O(1) — board is always 9 × 9
? Space: O(1) — fixed-size arrays

The important formula is:
*                         => int b = (i / 3) * 3 + (j / 3);
It converts (row, col) into one of the 9 box numbers (0–8).

*1. Understanding b
int b = (i / 3) * 3 + (j / 3);

This converts a cell's (row, col) into its 3×3 box number from 0 to 8.

For example, suppose:

i = 4
j = 5

This is the cell in the middle 3×3 box.

i / 3 = 4 / 3 = 1
j / 3 = 5 / 3 = 1

Therefore:

b = (1 * 3) + 1
  = 4

So box 4 is the middle box:

0 1 2
3 4 5
6 7 8

*2. Understanding the if
if (row[i][num] || col[j][num] || box[b][num])
    return false;

It checks 3 places:
    - row[i][num] → Is this number already in the row?
    - col[j][num] → Is this number already in the column?
    - box[b][num] → Is this number already in the 3×3 box?

|| means OR.

So if any one of these is true, there is a duplicate:

Row duplicate    → true
Column duplicate → true
Box duplicate    → true
                     ↓
            return false

*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[b][num])
                    return false;

                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }

        return true;
    }
};