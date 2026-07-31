/*
 * Problem Link : https://leetcode.com/problems/maximum-subarray/description/
 * Problem Name : Maximum Subarray
 * Problem No.  : 53
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//! ------------------------------------- brute force approach -------------------------------------
// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

//! ------------------------------------- Kadane's Algorithm -------------------------------------
//? Time complexity: O(n)
//? Space complexity: O(1)
// HELP --> https://www.youtube.com/watch?v=NUWAXbSlsws

int maxSubArray(vector<int> &nums)
{
    // Initialize variables to track the current subarray sum and the maximum sum
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) // Iterate through the array, starting from the second element
    {
        currentSum = max(nums[i], currentSum + nums[i]); // Decide whether to extend the current subarray or start a new one
        maxSum = max(maxSum, currentSum);                // Update the global maximum sum if the current sum is larger
    }

    return maxSum; // Return the maximum sum found
}

// -------------------------------------

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = 0;
        for (int num : nums)
        {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    }
};

//! ------------------------------------- Follow Up Question 1: Solve using divide and conquer approach -------------------------------------
//! Follow up 1: If you have figured out the O(n) solution,
//! try coding another solution using the divide and conquer approach, which is more subtle.

// Time complexity: O(n log n)
// Space complexity: O(log n)

/*
? Pesudo code for divide and conquer approach


function maxSubArray(nums, left, right):
///? Base case
if left == right:
return nums[left]

mid = (left + right) / 2

///? Solve left half
leftMax = maxSubArray(nums, left, mid)

///? Solve right half
rightMax = maxSubArray(nums, mid + 1, right)

///? Find best crossing sum

///? Maximum suffix sum on left side
    sum = 0
leftBorderMax = -∞

for i from mid downto left:
    sum += nums[i]
    leftBorderMax = max(leftBorderMax, sum)

///? Maximum prefix sum on right side
sum = 0
rightBorderMax = -∞

for i from mid + 1 to right:
    sum += nums[i]
    rightBorderMax = max(rightBorderMax, sum)

crossMax = leftBorderMax + rightBorderMax

///? Final answer
return max(leftMax, rightMax, crossMax)

practice own with the help of above pesudo code: again when revising  also see comments one

!  - - - - - - DETAILED NOTES:  - - - - - -
*Intuition

The maximum subarray can lie in only one of three places:

1. Completely in the left half.
2. Completely in the right half.
3. Crossing the middle.
Find all three and return the maximum.

*Algorithm
1. Divide the array into two halves using `mid`.
2. Recursively find the maximum subarray in the left half.
3. Recursively find the maximum subarray in the right half.
4. Find the maximum subarray crossing the middle:
    - Find the maximum sum from `mid` towards the left.
    - Find the maximum sum from `mid+1` towards the right.
    - Add both sums.
5. Return the maximum of:
    - Left answer
    - Right answer
    - Crossing answer

?   Time Complexity  : O(N log N)
?   Space Complexity : O(log N), recursion stack
! - - - - - - Without comments - - - - - - Solve using Divide & Conquer
*/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        int mid = left + (right - left) / 2;

        int leftMax = maxSubArrayHelper(nums, left, mid);
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);

        int sum = 0;
        int leftBorderMax = INT_MIN;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftBorderMax = max(leftBorderMax, sum);
        }

        sum = 0;
        int rightBorderMax = INT_MIN;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightBorderMax = max(rightBorderMax, sum);
        }

        return max({leftMax, rightMax, leftBorderMax + rightBorderMax});
    }
};

//! - - - - - - With Comments - - - - - - Solve using Divide & Conquer
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    // Recursive function to find maximum subarray in range [left, right]
    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        // Base Case: Only one element
        if (left == right)
            return nums[left];

        // Find middle index
        int mid = left + (right - left) / 2;

        // Maximum subarray completely in left half
        int leftMax = maxSubArrayHelper(nums, left, mid);

        // Maximum subarray completely in right half
        int rightMax = maxSubArrayHelper(nums, mid + 1, right);

        // Find maximum sum crossing the middle (left side)
        int sum = 0;
        int leftBorderMax = INT_MIN;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftBorderMax = max(leftBorderMax, sum);
        }

        // Find maximum sum crossing the middle (right side)
        sum = 0;
        int rightBorderMax = INT_MIN;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightBorderMax = max(rightBorderMax, sum);
        }

        // Maximum subarray crossing the middle
        int crossMax = leftBorderMax + rightBorderMax;

        // Return the best among left, right and crossing subarrays
        return max({leftMax, rightMax, crossMax});
    }
};
/*
! ------------------------------------- Follow-up Question 2: -------------------------------------
TODO ---  Can you print the subarray that has the maximum sum?  ---

?   Time Complexity  :  O(n),            where n is the number of elements in the array. We traverse the array only once.

?   Space Complexity :  O(1).            We use a constant amount of space for variables.


* `sum` stores current subarray sum.
* `maxi` stores maximum sum found till now.
* `start` stores starting index of current subarray.
* `ansStart` and `ansEnd` store indices of best subarray.

---

Loop through array:

1. If `sum == 0`

   * current subarray starts from current index.

2. Add current element to `sum`.

3. If `sum > maxi`

   * update maximum sum.
   * save starting and ending indices.

4. If `sum < 0`

   * reset `sum = 0`
   * because negative sum is useless for future.

---

Finally:

* print elements from `ansStart` to `ansEnd`.

Technique used:

* Kadane’s Algorithm + index tracking.
*/
class Solution2
{
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int> &nums)
    {
        long long maxi = LLONG_MIN;     // maximum sum
        long long sum = 0;              // current sum of subarray
        int start = 0;                  // starting index of current subarray
        int ansStart = -1, ansEnd = -1; // indices of the maximum sum subarray

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // update starting index if sum is reset
            if (sum == 0)
                start = i;

            // add current element to the sum
            sum += nums[i];

            /* Update maxi and subarray indices if current sum is greater*/
            if (sum > maxi)
            {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
                sum = 0;
        }

        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        return maxi; // Return the maximum subarray sum found
    }
};

//
//
// - - - Driver Code - - -
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Create an instance of Solution class
    Solution2 sol;
    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
/*
* Intuition

While finding the maximum subarray using Kadane's Algorithm,
keep track of where the current subarray starts and where the
maximum subarray ends. Whenever a new maximum sum is found,
store its starting and ending indices.

* Algorithm

1. Initialize currentSum = 0 and maxSum = INT_MIN.
2. Keep three indices:
   - start      -> potential starting index.
   - ansStart   -> starting index of maximum subarray.
   - ansEnd     -> ending index of maximum subarray.
3. Traverse the array:
   - If currentSum becomes 0, mark the current index as the new start.
   - Add the current element to currentSum.
   - If currentSum > maxSum:
       - Update maxSum.
       - Store ansStart = start.
       - Store ansEnd = current index.
   - If currentSum < 0, reset currentSum = 0.
4. Print elements from ansStart to ansEnd.
! ----------------------- Optimal -----------------------
?   Approach         : Kadane's Algorithm
?   Time Complexity  : O(N)
?   Space Complexity : O(1)
*/
class Solution
{
public:
    vector<int> maxSubArray(vector<int> &nums)
    {
        int currentSum = 0, maxSum = INT_MIN;
        int start = 0, ansStart = 0, ansEnd = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            // Start a new subarray if current sum is 0
            if (currentSum == 0)
                start = i;

            currentSum += nums[i]; // add current element to the sum

            // Update maxi and subarray indices if current sum is greater
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                ansStart = start;
                ansEnd = i;
            }

            // Discard negative sum
            if (currentSum < 0)
                currentSum = 0; // Reset sum to 0 if it becomes negative
        }

        // Printing the subarray
        vector<int> ans;
        for (int i = ansStart; i <= ansEnd; i++)
            ans.push_back(nums[i]);

        return ans;
    }
};
/*
Input : [-2,1,-3,4,-1,2,1,-5,4]

Output Subarray : [4,-1,2,1]
Maximum Sum     : 6
*/

// Printing the subarray:

// cout << "The subarray is: [";
// for (int i = ansStart; i <= ansEnd; i++)
// {
//     cout << nums[i] << " ";
// }
// cout << "]" << endl;
