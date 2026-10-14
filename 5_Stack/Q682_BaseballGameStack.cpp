/*
 * Problem Info : 682. Baseball Game
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

// ?  Time complexity: O(n)
// ? Space complexity: O(n)
// for both solutions

#include <bits/stdc++.h>
using namespace std;

// Sol, I came up with  Time taken: 9 mins  - error:
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> stk;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")
                stk.pop();
            else if (operations[i] == "D")
            {
                int num = stk.top();
                num *= 2;
                stk.pop();
                stk.push(num);
            }
            else if (operations[i] == "+")
            {
                int top = stk.top();
                stk.pop();
                int below = stk.top();
                stk.push(top);
                stk.push(top + below);
            }
            else
                stk.push(stoi(operations[i]));
        }

        long ans = 0;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

/*
! Errors and Fixes:

1. Uninitialized variable:
   Original: long ans;
   Fixed:    int ans = 0;
   Reason: ans was uninitialized, causing undefined behavior
   when adding scores.

2. Simplified "D" operation (optional):
   Original: Pop the top score, double it, and push it back.
   Simplified: stk.push(2 * stk.top());
   Reason: Both approaches work; the simplified version avoids
   unnecessary pop and push operations.

3. "+" operation:
   No error. Correctly retrieves the top two scores, restores
   the previous top score, and pushes their sum.

4. Final stack summation:
   No error. Summing all scores at the end is valid.
   Unlike the alternative approach, it does not maintain
   the running total during each operation.


! Mine Fixed Code:
*/
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> stk;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "C")
                stk.pop();

            else if (operations[i] == "D")
                stk.push(2 * stk.top());

            else if (operations[i] == "+")
            {
                int top = stk.top();
                stk.pop();
                int below = stk.top();
                stk.push(top);
                stk.push(top + below);
            }
            else
                stk.push(stoi(operations[i]));
        }

        int ans = 0; // Initialize to zero
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};

// SAme Code: bit different
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> stack;
        for (const string &op : operations)
        {
            if (op == "+")
            {
                int top = stack.back();
                stack.pop_back();
                int newTop = top + stack.back();
                stack.push_back(top);
                stack.push_back(newTop);
            }
            else if (op == "D")
                stack.push_back(2 * stack.back());
            else if (op == "C")
                stack.pop_back();
            else
                stack.push_back(stoi(op));
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};

/*
! STACK II

Intuition
This approach is similar to the first one, but we maintain a running total as we process operations
instead of computing the sum at the end. Whenever we add a score, we add it to our result.
When we remove a score with C, we subtract it. This gives us the same answer but avoids a final pass through the stack.*/
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> stack;
        int res = 0;
        for (const string &op : ops)
        {
            if (op == "+")
            {
                int top = stack.top();
                stack.pop();
                int newTop = top + stack.top();
                stack.push(top);
                stack.push(newTop);
                res += newTop;
            }
            else if (op == "D")
            {
                stack.push(2 * stack.top());
                res += stack.top();
            }
            else if (op == "C")
            {
                res -= stack.top();
                stack.pop();
            }
            else
            {
                stack.push(stoi(op));
                res += stack.top();
            }
        }
        return res;
    }
};