/*
 * Problem Info : 189. Rotate Array
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
! - - - - - - - - - - - - - - - - Approach 1: Brute Force - - - - - - - - - - - - - - - -
? Time:  n * k
? Space: 1
*/
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    while (k > 0)
    {
        int temp = nums[n - 1];
        for (int i = n - 1; i > 0; i--)
            nums[i] = nums[i - 1];

        nums[0] = temp;
        k--;
    }
}

/*
! - - - - - - - - - - - - - - - - Approach 2: Extra Space - - - - - - - - - - - - - - - -
? Time:  n
? Space: n
*/
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> tmp(n);
    for (int i = 0; i < n; i++)
        tmp[(i + k) % n] = nums[i];
    for (int i = 0; i < n; i++)
        nums[i] = tmp[i];
    // nums = tmp;  or just this
}
/*
! - - - - - - - - - - - - - - - - Approach 3: Cyclic Traversal - - - - - - - - - - - - - - - -
? Time:  n
? Space: 1

*Intuition
We can rotate in-place by following cycles. Starting from any position, we move the element to its destination,
then move the displaced element to its destination, and so on until we return to the starting position.
If the cycle doesn't cover all elements (which happens when n and k share a common divisor)
we start a new cycle from the next position. This ensures every element is moved exactly once.

*Algorithm
1. Compute k = k % n and initialize a counter for how many elements have been placed.
2. Start from index 0. For each starting index:
    - Save the element at the current position.
    - Move to the next position (current + k) % n, swap the saved element with the element there, and repeat.
    - Stop when we return to the starting index.
3. If not all elements are placed, increment the starting index and repeat.
4. Continue until all n elements have been moved.
*/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        int count = 0;

        for (int start = 0; count < n; start++)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int nextIdx = (current + k) % n;
                int temp = nums[nextIdx];
                nums[nextIdx] = prev;
                prev = temp;
                current = nextIdx;
                count++;
            } while (start != current);
        }
    }
};

/*
! - - - - - - - - - - - - - - - - Approach 4: Using Reverse - - - - - - - - - - - - - - - -
? Time:  n
? Space: 1

*/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

private:
    void reverse(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};

//  - - - - - - - - -  or 4.2  - - - - - - - - -
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
/*
! - - - - - - - - - - - - - - - - Approach 5: One Liner - - - - - - - - - - - - - - - -
? Time:  n
? Space: 1

*/
void rotate(vector<int> &nums, int k)
{
    std::rotate(nums.begin(), nums.end() - (k % nums.size()), nums.end());
}

// - - - - - - - - -  or 5.2 - - - - - - - - -
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return;

    k %= n;
    rotate(nums.begin(), nums.end() - k, nums.end());
}