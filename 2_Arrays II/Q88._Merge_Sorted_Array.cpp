/*
 * Problem Link : https://leetcode.com/problems/merge-sorted-array/description/
 ! Problem      : 88 Merge Sorted Array
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//? For Sol 1 and 2 Refer Lec 20 Code Help
/*
!--------------------------------- In 1st array itself (Original Ques)   Approach: Copy + Sort ------------------------------------
Why to copy and then Sort the Arrays..
We already had Sorted Arrays so Find some way to do in-place

Time:  O((m+n) log(m+n))
Space: O(1)
*/
//?
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Copy nums2 elements into nums1, starting at index m
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }
};

/*
! Merge Two Sorted Arrays Without Extra Space
! !---------------------- Optimal's Way!- with explanation----Three-pointer merge from end------
? Time  Complexity:   O(m + n)
? Space Complexity:   O(1)

?    ---------- Approach ---------- Three-pointer merge from end
- Since both arrays are already sorted, do not sort again.
- Use 3 pointers starting from the end:
      - `i = m - 1` → last valid element in `nums1`
      - `j = n - 1` → last element in `nums2`
      - `k = m + n` - 1 → last index of `nums1`
- Compare `nums1[i]` and `nums2[j]`.
- Place the larger element at `nums1[k]`.
- Move the corresponding pointer and decrement `k.`
- After one array is exhausted, copy any remaining elements from `nums2.`

?  ---------- Algorithm ----------
1. Initialize i = m - 1, j = n - 1, k = m + n - 1.
2. While i >= 0 and j >= 0:
    - If nums1[i] > nums2[j], place nums1[i] at nums1[k], decrement i.
    - Else, place nums2[j] at nums1[k], decrement j.
    - Decrement k.
3. Copy any remaining elements of nums2 into nums1.

*/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

//.
//.

/*
 !---------------- Changed ...new arr used ------------not for leetcode----------------EXTRA----- * ignore
void merge_(vector<int> &nums1, int m, vector<int> &nums2, int n, vector<int> &arr3)
{
    arr3.resize(m + n);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            arr3[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = nums2[j];
            k++;
            j++;
        }
    }
    // Copy Remaining
    while (i < m)
    {
        arr3[k] = nums1[i];
        k++;
        i++;
    }
    // Copy Remaining
    while (j < n)
    {
        arr3[k] = nums2[j]; // or BETTER METHOD arr3[k++] = nums2[j++];
        k++;
        j++;
    }
}
*/

/*
! !--------------------------------- Sir's Way!---------------------------------
? Time Complexity: O(N+M), we traverse both the arrays exactly once.
? Space Complexity: O(1), constant extra space is used to store pointers.
*/
class Solution
{
public:
    // Merges nums2 into nums1 in-place in sorted order.
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = m - 1; // i points to last valid element in nums1

        // j points to last element in nums2
        int j = n - 1;

        // k is the last index of nums1 (including 0 placeholders)
        int k = m + n - 1;

        // Fill nums1 from the end by comparing nums1[i] and nums2[j]
        while (i >= 0 && j >= 0)
        {
            // Place larger of the two at nums1[k]
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 has remaining elements, copy them
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }

        // No need to copy remaining nums1 elements, as they are already in place
    }
};
