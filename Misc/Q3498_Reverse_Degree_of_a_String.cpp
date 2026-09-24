/*
 * Problem Info : 3498. Reverse Degree of a String
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.
*/

//! - - - - - App1: 2 POINTERS & Using swap  -- - -  T: n - - S: 1  - - - -
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int st = 0, e = s.size() - 1;
        while (st <= e)
            swap(s[st++], s[e--]);
    }
};

//! - - - - - App2: Inbuild Funcn  -- - -  T: n - - S: 1  - - - -
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

//! - - - - - App3: Stack  -- - -  T: n - - S: n  - - - -
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        stack<char> stk;
        for (char c : s)
            stk.push(c);
        int i = 0;
        while (!stk.empty())
        {
            s[i++] = stk.top();
            stk.pop();
        }
    }
};

// Some other approaches : using arr and using recursion