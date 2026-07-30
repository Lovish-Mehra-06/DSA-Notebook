/*
 * Problem Link : https://leetcode.com/problems/next-permutation/
 ! Problem Name : Next Permutation
 * Problem No.  : 31
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
✅ Time: O(N) (Optimal)
✅ Space: O(1) (Optimal)


* Intuition

Find the first position from the right where the sequence stops decreasing (pivot).
Swap it with the next greater element from the right to get a slightly larger permutation.
Finally, reverse the remaining suffix to make it the smallest possible.

* Algorithm

1. Traverse from right and find the pivot.  ...... by  (nums[i] < nums[i+1]).
(2. If no pivot exists, reverse the entire array and return.)
3. Traverse from the right and find the *first element greater* than the *pivot*.
4. Swap the pivot with that element.
5. Reverse the suffix (pivot + 1 to end).

* Explanation + Interview Questions in end

! ---------------------------------------------(Comments added with  Ai)-----------------------------------------
*/
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        // Step 1: Find pivot
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) //    0>= <------ n-2
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, current permutation is the largest, reverse it
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find smallest element greater than pivot from right side          pivot <----- n-1
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

// - ROUGH - Practice -
//! --------------------------------------------- Own -----------------------------------------
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pivot = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int min = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[pivot])
            {
                min = i;
                break;
            }
        }
        swap(nums[min], nums[pivot]);
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

//! ---------------------------------------------  NeetCode -----------------------------------------
// Solution class
class Solution
{
public:
    // Function to find next permutation
    void nextPermutation(vector<int> &nums)
    {
        // Set index to -1
        int index = -1;

        // Find the first decreasing element from end
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // If a smaller element found
            if (nums[i] < nums[i + 1])
            {
                // Store index
                index = i;
                break;
            }
        }

        // If no such index found
        if (index == -1)
        {
            // Reverse the entire array
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find element just greater than nums[index]
        for (int i = nums.size() - 1; i > index; i--)
        {
            // Swap the two
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Reverse the part after index
        reverse(nums.begin() + index + 1, nums.end());
    }
};

/*
! A simple explanation is:
"We need the next lexicographically greater permutation, so we want to make the smallest possible increase to the current array."

Then explain the four steps:
* 1. Find the pivot.
"I scan from the right and find the first element that is smaller than its next element. This is the position where I can make the number slightly larger."

* 2.Find the next greater element.
"From the right, I find the first element greater than the pivot. Since the suffix is in descending order, this is the smallest element greater than the pivot."

* 3.Swap them
"This makes the permutation just a little larger."

* 4.Reverse the suffix.
"The suffix is in descending order. After the swap, I reverse it to make it ascending, which gives the smallest possible suffix. That ensures I get the immediate next permutation, not a larger one."


Questions:

*If they ask *why* scan from the right, say:
"Changing a digit farther to the right causes the smallest possible increase. If I changed a digit on the left, the permutation would increase much more."

*If they ask why reverse, say:
"The suffix is descending, so reversing it makes it ascending—the smallest arrangement possible after the new prefix."

*A concise 30-second explanation could be:
"The idea is to make the smallest possible increase.
I find the rightmost position where the sequence can still be increased (the pivot).
Then I swap it with the smallest larger element on its right.
Finally, I reverse the remaining suffix so it becomes the smallest possible arrangement.
This gives the immediate next lexicographical permutation in O(N) time and O(1) space."
*/