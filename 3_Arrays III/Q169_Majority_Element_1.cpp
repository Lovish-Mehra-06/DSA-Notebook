/*
 * Problem Link : https://leetcode.com/problems/majority-element/description/
 ! Problem Name : Majority Element
 * Problem No.  : 169
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
!  Brute Force Approach

? Time : O(n^2)
? Space: O(1)

Algo:
-Iterate through the array to select each element one by one.
-For each selected element, run another loop to count its occurrences in the given array.
-If the occurrence of any element is greater than the floor of (N/2), return that element immediately as the majority element.
*/

/*
! Better Approach 2:  Using Hash Map
store all elements in a hash map
and check in end which one's occurrence is > n/2 that is our answer.

? Time : O(n)
? Space: O(n)
*/

/*
! Approach 3: Sort, & then n/2th element will be our answer
? Time : O(n log n)  for sorting
? Space: O(1)*
*/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/*
!  Optimal Solution:   - Boyer-Moore Voting Algorithm -

?   Time Complexity:  O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
?   Space Complexity: O(1), as we are using only a constant amount of extra space.

1. Initialize two variables: count to track the count of elements,and element to keep track of the element being counted.
2. Traverse through the given array. If count is 0, store the current value of the array as element.
3. If the current element in the array is the same as element, increment the count by 1.
4. If the current element is different from element, decrement the count by 1.
5. At the end of the traversal, the integer stored in element will be the expected result (the majority element).
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ctr = 0;
        int element = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (ctr == 0)
            {
                element = nums[i];
                ctr += 1;
            }
            else if (nums[i] == element)
                ctr += 1;
            else
            {
                ctr--;
            }
        }
        return element;
    }
};

/*
My code doesn't verify whether the final candidate actually occurs more than n/2 times.

That's fine because LeetCode's Majority Element problem guarantees that a majority element exists.

If the problem does not guarantee this, you need a second pass to verify the candidate.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the majority element in an array
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int el;

        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i])
                cnt++;

            else
                cnt--;
        }

        //  Checking if the stored element is the majority element
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el)
                cnt1++;
        }
        if (cnt1 > (n / 2)) // return element if it is a majority element
            return el;

        // return -1 if no such element found
        return -1;
    }
};