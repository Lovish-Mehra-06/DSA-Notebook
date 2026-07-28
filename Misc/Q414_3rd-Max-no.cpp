/*
 * Problem Link : https://leetcode.com/problems/third-maximum-number/
 ! Problem Name : Third Max No
 * Problem No.  : 414
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
! ---------------- Approach 1: ------------- Sort + Skip Duplicates------------
my initial intuition: was this but quickly realized .... ques said 3rd Largest "Distinct" no.
ALSO:  If the third maximum does not exist, return the maximum number.
int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n-1];
}

! ---------------- Approach 1: ------------- Sort + Skip Duplicates------------ *Fixed* ---
?   Time  Complexity  :   O(N log N)
?   Space Complexity  :   O(1)           (ignoring sort)

1. Sort the array.
2. Traverse from the end.
3. Count distinct elements.
4. Return the 3rd distinct maximum.
5. If fewer than 3 distinct values exist, return the maximum.
*/
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int cnt = 1;
        int ans = nums.back();

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] != nums[i + 1])
            {
                cnt++;
                if (cnt == 3)
                    return nums[i];
            }
        }
        return nums.back();
    }
};

/*
! ---------------------------------- Approach 2 ------ Three Variables -------------------------
reference: Q628_maximum-product-of-three-numbers.cpp

*problem: INT_MIN and duplicates not handled

class Solution
{
    public:
    int thirdMax(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        int n = nums.size();

        if (n == 1)             // useless conditions checking :(
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        for (int x : nums)
        {
            if (x == max1 || x == max2 || x == max3)
                continue;

            if (x > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }
        }
        return max3;
    }
};
! ---------------------------------- Approach 2 ------ Three Variables -------------------- *Fixed* ----

?   Time  Complexity  :   O(N)
?   Space Complexity  :   O(1)
*/
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int x : nums)
        {

            // Skip duplicates  *** Imp --> (I' Forgot)
            if (x == first || x == second || x == third)
                continue;

            if (x > first)
            {
                third = second;
                second = first;
                first = x;
            }
            else if (x > second)
            {
                third = second;
                second = x;
            }
            else if (x > third)
            {
                third = x;
            }
        }

        return (third == LLONG_MIN) ? first : third;
    }
};