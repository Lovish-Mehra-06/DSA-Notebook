/*
 * Problem Link : https://leetcode.com/problems/sort-colors/description/
 ! Problem Name : Sort Colors
 * Problem No.  : 75
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
TODO -------------------------- 75. Sort Colors --------------------------

https://leetcode.com/problems/sort-colors/description/
----> In Vector

Resources:
?https://neetcode.io/problems/sort-colors/solution

?https://www.geeksforgeeks.org/dsa/sort-an-array-of-0s-1s-and-2s/#naive-approach-sorting-on-logn-time-and-o1-space
Table of Content:
*[Naive Approach] Sorting - O(n × log(n)) Time and O(1) Space
*[Better Approach] Counting 0s, 1s and 2s - Two Pass
*[Expected Approach] Dutch National Flag Algorithm - One Pass - O(n) Time and O(1) Space


// (Previous Question)
// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937
// ----> In Linked List
Related to Lec 49
*/
#include <iostream>
#include <vector>
using namespace std;

/*
! ---------------------------- Approch 1 --- Brute Force -----------------------
*Time complexity  : O(nlogn)
*Space complexity : O(1) or (n) depending on the sorting algorithm
*/
class Solution1
{
public:
    void sortColors(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
    }
};

/*
! ---------------------------- Approch 2 --- Counting Sort -----------------------
*Time complexity  : O(n)
*Space complexity : O(1)
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> count(3);
        for (int &num : nums)
        {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            while (count[i]-- > 0)
            {
                nums[index++] = i;
            }
        }
    }
};

//*  Try (My Code)  Yes It Works :)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zeroCounter = 0;
        int oneCounter = 0;
        int twoCounter = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroCounter++;
            }
            else if (nums[i] == 1)
            {
                oneCounter++;
            }
            else if (nums[i] == 2)
            {
                twoCounter++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (zeroCounter > 0)
            {
                nums[i] = 0;
                zeroCounter--;
            }
            else if (oneCounter > 0)
            {
                nums[i] = 1;
                oneCounter--;
            }
            else if (twoCounter > 0)
            {
                nums[i] = 2;
                twoCounter--;
            }
        }
    }
};

/*
! ---------------------------- Approch 3 --- Three Pointers-I / Dutch National Flag Algorithm -----------------------
*Time complexity  : O(n)
*Space complexity : O(1)
*/
/*
! ---------------------------- Approch 4 --- Three Pointers-II -----------------------
*Time complexity  : O(n)
*Space complexity : O(1)
*/
/*
! ---------------------------- Approch 5 --- Three Pointers-III -----------------------
*Time complexity  : O(n)
*Space complexity : O(1)
*/

/*
EXTRA:
? -------------- ✅ Dutch National Flag Algorithm --------------

https://www.youtube.com/watch?v=Zr1h-YDrRHA
Used to sort an array of 0s, 1s, 2s in one pass, using constant space.

? Intuition (Very Simple)
We want all:
0s → left side
2s → right side
1s → middle

We use 3 pointers:
l → next position to place 0
r → next position to place 2
i → current index scanning the array

? Simplified C++ Code
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, i = 0, r = nums.size() - 1;

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            }
            else { // nums[i] == 1
                i++;
            }
        }
    }
};

?Why not increment i after swapping with r?
Because the swapped element might be:
 - 0 → should be moved to left
 - 2 → should go again to right
So we must recheck that element.
*/