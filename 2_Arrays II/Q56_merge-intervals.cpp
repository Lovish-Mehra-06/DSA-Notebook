/*
 * Problem Link : https://leetcode.com/problems/merge-intervals/
 ! Problem Name : Merge Overlapping Subintervals
 * Problem No.  : 56
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
!------------------------- Optimized 1 ------------------ (i thought it was brute force, but not it's not)
XXXX Time  Complexity  :  O(N^2),    for every interval we check all future intervals. XXXX
Sorting = O(N log N)
Merging = O(N)
Overall = O(N log N)
?   Time  Complexity  :  O(N log N)  therefore
?   Space Complexity  :  O(N),      additional space used to store the non-overlapping intervals.

*### Algorithm

1. Sort all intervals based on their starting points.
2. Traverse the intervals starting from the first interval.
3. Consider the current interval as the beginning of a new merged interval.
4. Compare it with the following intervals.
5. While the next interval overlaps (next.start ≤ current.end):
   - Update current.end = max(current.end, next.end).
   - Move to the next interval.
6. Store the merged interval in the answer.
7. Continue from the first non-overlapping interval.
8. Repeat until all intervals are processed.
9. Return the merged intervals.
*/
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end()); // Sort intervals (based on start term)
        vector<vector<int>> ans;                  // Result array to store merged intervals
        int n = intervals.size();
        for (int i = 0; i < n;) // Loop through each interval
        {
            // Start of current merged interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge with all overlapping intervals
            int j = i + 1;
            while (j < n && intervals[j][0] <= end)
            {
                // Update end to the maximum of current end and overlapping interval's end
                end = max(end, intervals[j][1]);
                j++;
            }
            // Add the merged interval to result
            ans.push_back({start, end});

            // Move to the next non-overlapping interval
            i = j;
        }
        return ans;
    }
};
//! in short
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n;)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({start, end});
            i = j;
        }
        return ans;
    }
};

/*
!------------------------- Optimized 2 --------------------------
?   Time Complexity  :  O(N log N),   sorting takes O(N log N) and merging takes O(N).
?   Space Complexity :  O(N),         additional space used to store the merged intervals.

*### Algorithm

1. **Sort** all intervals based on their starting point.
2. **Traverse** each interval one by one.
3. If the answer list is **empty** or the current interval does **not overlap** with the last merged interval:
   - Add the current interval to the answer.
4. Otherwise, the intervals overlap:
   - Update the end of the last merged interval as:
     `last.end = max(last.end, current.end)`.
5. Continue until all intervals are processed.
6. Return the merged intervals.

I removed {} to make it short :)
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto &interval : intervals)
        {
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }

        return ans;
    }
};
//!  ------------- Sir-----------
class Solution
{
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        // Vector to store final merged intervals
        vector<vector<int>> merged;

        // Traverse each interval
        for (auto interval : intervals)
        {
            // If merged is empty or current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                // Add current interval as a new non-overlapping block
                merged.push_back(interval);
            }
            else
            {
                // Overlapping: merge by extending the end time
                merged.back()[1] = max(
                    merged.back()[1],
                    interval[1]);
            }
        }
        return merged;
    }
};

/*
!------------ Doubts: -----------
The key difference is how **merging** is performed.

*/