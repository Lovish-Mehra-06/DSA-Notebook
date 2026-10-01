/*
 * Problem Info : 11. Container With Most Water
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution    T:n    S:1
int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1, res = 0;

    while (l < r)
    {
        int area = min(height[l], height[r]) * (r - l);
        res = max(res, area);

        if (height[l] <= height[r])
            l++;
        else
            r--;
    }
    return res;
}

// Brute Force n^2 1
int maxArea(vector<int> &heights)
{
    int res = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = i + 1; j < heights.size(); j++)
            res = max(res, min(heights[i], heights[j]) * (j - i));
    }
    return res;
}