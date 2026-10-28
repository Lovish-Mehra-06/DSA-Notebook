/*
 * Problem Info : 71. Simplify Path
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

//? n n

/*
! Approach 1: STACK   -   Char by Char
*/

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack; // Stores valid directory names
        string cur;

        // Add '/' at the end to process the last directory
        for (char c : path + "/")
        {
            if (c == '/')
            {
                if ((cur == "..") && (!stack.empty())) // Move to parent directory
                    stack.pop_back();

                else if (!cur.empty() && cur != ".")
                {
                    stack.push_back(cur); // Ignore empty strings and ".", push valid directories
                }
                cur.clear(); // Reset for the next directory
            }
            else
            {
                cur += c; // Build the current directory name
            }
        }

        string result = "/";                   // Absolute path starts with '/'
        for (int i = 0; i < stack.size(); ++i) // Reconstruct the simplified path
        {
            if (i > 0)
                result += "/";
            result += stack[i];
        }

        return result;
    }
};

/*
! Approach 2: STACK II
*/

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack; // Stores valid directory names
        string cur;
        stringstream ss(path); // Converts path into an input stream

        // Extract directory components separated by '/'
        while (getline(ss, cur, '/'))
        {
            if (cur.empty()) // Ignore empty components caused by consecutive '/'
                continue;

            // ".." means move to the parent directory,  Pop the last directory if the stack is not empty
            if (cur == ".." && (!stack.empty()))
                stack.pop_back();

            // Ignore "." (current directory),           Push normal directory names into the stack
            else if (cur != "." && !cur.empty())
                stack.push_back(cur);
        }

        // Absolute paths always start with '/'0
        string ans = "/";
        for (int i = 0; i < stack.size(); i++)
        {
            if (i > 0)
                ans += "/";
            ans += stack[i];
        }

        return ans;
    }
};
