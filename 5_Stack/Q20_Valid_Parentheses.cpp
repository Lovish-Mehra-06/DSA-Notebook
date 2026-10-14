/*
 * Problem Info : 20. Valid Parentheses
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

// TODO -------------------------------------Approach: Stack-based ---------- Own ---just took hints from Ai to find errors-----
//?   Time  complexity: O(n)
//?   Space complexity: O(n)
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (!stack.empty())
            {

                if (stack.top() == '(' && c == ')')
                {
                    stack.pop();
                    continue;
                }
                if (stack.top() == '[' && c == ']')
                {
                    stack.pop();
                    continue;
                }
                if (stack.top() == '{' && c == '}')
                {
                    stack.pop();
                    continue;
                }
            }
            stack.push(c);
        }

        if (stack.empty())
            return true;

        return false;
    }
};

// Optimal Code:  n n
class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (char c : s)
        {
            if (closeToOpen.count(c))
            {
                if (!stack.empty() && stack.top() == closeToOpen[c])
                    stack.pop();
                else
                    return false;
            }
            else
                stack.push(c);
        }
        return stack.empty();
    }
};