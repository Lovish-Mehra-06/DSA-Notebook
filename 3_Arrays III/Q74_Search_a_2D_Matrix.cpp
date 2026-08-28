/*
 * Problem Link : https://leetcode.com/problems/search-a-2d-matrix/
 ! Problem Name : Search a 2D Matrix
 * Problem No.  : 74
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = ((row * col) - 1);

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int element = matrix[mid / col][mid % col];

            if (target == element)
            {
                return 1;
            }

            else if (target > element)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return 0;
    }
};