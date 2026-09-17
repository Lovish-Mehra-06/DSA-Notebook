/*
 * Problem Info : 42. Trapping Rain Water
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
! - - - - - Approach 1: Brute Force  - - - - -  *Time Limit Exceeded

? Time:  O(n^2)
? Space: O(1)


trapped water =  min(maxRight, maxLeft) - currentHeight;

*/
// 1.1 Mine
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();

        for (int i = 1; i < n - 1; i++)
        {
            int maxRight = height[i + 1];
            int maxLeft = height[i - 1];

            for (int j = 0; j < i; j++)
                if (height[j] > maxLeft)
                    maxLeft = height[j];

            for (int j = i + 1; j < n; j++)
                if (height[j] > maxRight)
                    maxRight = height[j];

            int temp = min(maxRight, maxLeft) - height[i];

            if (temp >= 0)
                ans += temp;
        }

        return ans;
    }
};
// 1.2 Optimal
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int totalWater = 0;
        for (int i = 0; i < n; i++)
        {
            int maxLeft = 0;
            int maxRight = 0;
            for (int j = 0; j <= i; j++)
            {
                if (height[j] > maxLeft)
                {
                    maxLeft = height[j];
                }
            }
            for (int j = i; j < n; j++)
            {
                if (height[j] > maxRight)
                {
                    maxRight = height[j];
                }
            }
            totalWater += min(maxLeft, maxRight) - height[i]; // Directly added
        }
        return totalWater;
    }
};

/*
! - - - - - Approach 2: 2 Pointers  - - - - -

? Time:  O(n)  OMG
? Space: O(1)

* Algo:
1. Set left = 0, right = n-1.
2. Set leftMax = 0, rightMax = 0.
3. While left <= right:
    If height[left] <= height[right]:
        If height[left] >= leftMax, update leftMax.
        Otherwise, add leftMax - height[left].
        Move left++.
    Otherwise:
        If height[right] >= rightMax, update rightMax.
        Otherwise, add rightMax - height[right].
        Move right--.
4. Return total water.
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ptr1 = 0, ptr2 = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int totalwater = 0;

        while (ptr1 <= ptr2)
        {
            if (height[ptr1] < height[ptr2])
            {
                if (maxLeft <= height[ptr1])
                    maxLeft = height[ptr1];
                else
                    totalwater += maxLeft - height[ptr1];
                ptr1++;
            }
            else if (height[ptr1] >= height[ptr2])
            {
                if (maxRight <= height[ptr2])
                    maxRight = height[ptr2];
                else
                    totalwater += maxRight - height[ptr2];
                ptr2--;
            }
        }
        return totalwater;
    }
};

/*
my notes:
2 pointer ptr 1,2 or left right
and 2 extra variables maxleft and maxright


*/