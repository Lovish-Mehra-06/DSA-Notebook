/*
 * Problem Link : https://leetcode.com/problems/excel-sheet-column-number/
 ! Problem Name : Excel Sheet Column Number
 * Problem No.  : 171
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// All code below have:
//? Time:  O(n)
//? Space: O(1)

// Mine approach — positional formula
// ans += (c - 'A' + 1) * pow(26, position);
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0, ctr = columnTitle.size(), i = 1;
        for (auto &c : columnTitle)
        {
            int num = c - 'A' + 1;
            // int num = c - '@';   // -- or --  @ have 64 asci no
            ans += num * pow(26, ctr - i);
            i++;
        }
        return ans;
    }
};

// Most common — running base-26 value
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (char c : columnTitle)
            ans = ans * 26 + (c - 'A' + 1);

        return ans;
    }
};