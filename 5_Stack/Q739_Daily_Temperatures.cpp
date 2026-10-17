/*
 * Problem Info : 739. Daily Temperatures
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
! ---------------------- 2. Stack -------------- n, n ----------------------

*Intuition
We want to know how long it takes until a warmer day for each temperature.
A stack helps because it keeps track of days that are still waiting for a warmer temperature.
As we scan forward, whenever we find a temperature higher than the one on top of the stack, it means we just discovered the “next warmer day” for that earlier day.
We pop it, compute the difference in days, and continue.
This way, each day is pushed and popped at most once, making the process efficient.

Explaination:
https://www.youtube.com/watch?v=8t168IHD_50
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first)
            {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};

/*
! ---------------------- 3. DP ------------------ n,  1 & n for output ----------------------

*Intution
Instead of checking every future day one by one, we can "reuse previously computed answers."
If day j is not warmer than day i, we don’t need to move forward step-by-step — we can simply jump ahead by using the result already stored for day j.
This lets us skip many unnecessary comparisons.
By working backward and using these jumps, we efficiently find the next warmer day for each position.

*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            int j = i + 1;

            // Skip days that are not warmer
            while (j < n && temperatures[j] <= temperatures[i])
            {
                if (res[j] == 0)
                {
                    j = n; // No warmer day exists after j
                    break;
                }
                j += res[j]; // Jump to the next warmer day for j
            }

            if (j < n)
                res[i] = j - i;
        }

        return res;
    }
};

//! ---------------------- 1. Brute Force --------- n^2,    1 & n for output ----------------------
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans;

        for (int i = 0; i < temperatures.size(); i++)
        {
            bool foundWarm = false;
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[i] < temperatures[j])
                {
                    ans.push_back(j - i);
                    foundWarm = true;
                    break;
                }
            }
            if (!foundWarm)
                ans.push_back(0);
        }
        return ans;
    }
};
// Small improvement: Preallocate "ans" with zeros instead of using "foundWarm":
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // int n = temperatures.size();
        // vector<int> ans(n, 0);

        // for (int i = 0; i < n; i++){
        //     for (int j = i + 1; j < n; j++){
        //         if (temperatures[j] > temperatures[i]){
        //             ans[i] = j - i;
        //             break;
        //         }
        //     }
        // }

        // return ans;
    }
};