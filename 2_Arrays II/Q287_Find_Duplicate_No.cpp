/*
 * Problem Link : https://leetcode.com/problems/find-the-duplicate-number
 ! Problem Name : Find the Duplicate Number
 * Problem No.  : 287
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
! --------------------- 3. Optimal Approach --------------------------

Time Complexity: O(N), where N is the size of the array. This is because we traverse the array at most twice (once to find the intersection and once to find the duplicate).

Space Complexity: O(1), as we are using only a constant amount of space for the slow and fast pointers, regardless of the input size.
*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

class Solution // Optimal 3.2
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
                return slow;
        }
    }
};

/*
! --------------------- 1. Brute Force Approach --------------------------
? Time Complexity:  O(N log N)
? Space Complexity: O(1)

First Sort
then check when `nums[i] == nums[i + 1]`

this is not in-place
*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

/*

! ----------------------- 2. Better Approach ---------------------
? Time Complexity:  O(N),
where N is the size of the array. This is because we are traversing the array once to build the frequency array.
? Space Complexity: O(N),
as we are using an additional frequency array of size N+1 to keep track of the occurrences of each element.


*Algorithm
- Create a frequency array of size N+1 and initialize all elements to 0. This will keep track of the occurrences of each element in the array.
- Traverse through the given array.
- For each element, check its frequency in the frequency array:
    - If the frequency is 0, increase it by 1, indicating that the element has been encountered for the first time.
    - If the frequency is not 0, this means the element has appeared before, and it is the required answer.
- Return or print the element as the first repeating element.
*/
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        // return current value if already seen
        if (freq[nums[i]] == 0)
            freq[nums[i]] += 1; // mark as seen
        else
            return nums[i]; // duplicate found
    }
    return 0;
}

// program entry
int main()
{
    // declare and initialize nums/ array
    vector<int> nums = {1, 3, 4, 2, 3};
    // print result
    cout << "The duplicate element is " << findDuplicate(nums) << endl;
    // exit
    return 0;
}
