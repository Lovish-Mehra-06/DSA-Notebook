/*
 * Problem Link : https://leetcode.com/problems/maximum-product-of-three-numbers/description
 ! Problem Name : maximum-product-of-three-numbers
 * Problem No.  : 628
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
! -------------------------- Try -- Kinda Brute force--------------------------
?  Time  :  O(N log N)   (due to sorting)
?  Space :  O(1)         (ignoring the sort's internal implementation)

Your solution is already optimal.
*/
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        // Case with 3 elements only
        if (n == 3)
            return nums[0] * nums[1] * nums[2];

        sort(nums.begin(), nums.end()); //* Sort

        int first_max = nums[n - 1], second_max = nums[n - 2], third_max = nums[n - 3], first_min = nums[0], second_min = nums[1];
        long ans;

        ans = max(first_max * second_max * third_max, first_min * second_min * first_max); //* Main Logic
        return ans;
    }
};

/*
! -------------------------- More Optimal Ans (Without Sorting)--------------------------
You don't actually need to sort the array. You only need:

Largest (max1)
Second largest (max2)
Third largest (max3)
Smallest (min1)
Second smallest (min2)

These can all be found in one traversal.

? Time  Complexity  :  O(N) ✅
? Space Complexity  :  O(1) ✅
*/
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums)
        {

            // Update three largest
            if (x >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x >= max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }

            // Update two smallest
            if (x <= min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
            {
                min2 = x;
            }
        }

        return max(max1 * max2 * max3,
                   max1 * min1 * min2);
    }
};

/*
! --------Doubts / Notes------------

* Access last element of vector

? Using back() - recommended
std::cout << v.back(); // Outputs: 40

? Or using index notation
std::cout << v[v.size() - 1]; // Outputs: 40
*/

/*
*Wrong:
// int first_max = nums[0], second_max = nums[0], third_max = nums[0], first_min = nums[0], second_min = nums[0];
// long ans;

// for (int i = 0; i < n; i++)
// {
//     if (nums[i] > first_max)
//     {
//         first_max = nums[i];
//     }

//     if (nums[i] >= second_max && nums[i] < first_max)
//         second_max = nums[i];
//     }

//     if (nums[i] >= third_max && nums[i] < second_max && nums[i] < first_max)
//     {
//         third_max = nums[i];
//     }

//     if (nums[i] < first_min)
//     {
//         first_min = nums[i];
//     }

//     if (nums[i] < second_min)
//     {
//         second_min = nums[i];
//     }
// }

*Also wrong way to Access last elements of vector   first_max = nums[-1]
// int first_max = nums[-1], second_max = nums[-2], third_max = nums[0], first_min = nums[0], second_min = nums[1];
*/

//? --------------- DRIVER CODE ---------------
int main()
{
    vector<int> numbers = {1, 2, 3, 4};

    cout << "Vector elements: ";
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    Solution sol;
    cout << sol.maximumProduct(numbers);

    return 0;
}