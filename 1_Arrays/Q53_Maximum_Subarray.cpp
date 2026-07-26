#include <vector>
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
// Time complexity: O(n)
// Space complexity: O(1)
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

//! ------------------------------------- divide and conquer approach -------------------------------------
//! Follow up: If you have figured out the O(n) solution,
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
*/

// TODO: practice own with the help of above pesudo code:

// Ai gen
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

////! ------------------------------------- Follow-up Question: -------------------------------------
// Can you print the subarray that has the maximum sum?
#include <bits/stdc++.h>
using namespace std;
/*
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

        // maximum sum
        long long maxi = LLONG_MIN;

        // current sum of subarray
        long long sum = 0;

        // starting index of current subarray
        int start = 0;

        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {

            // update starting index if sum is reset
            if (sum == 0)
            {
                start = i;
            }

            // add current element to the sum
            sum += nums[i];

            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi)
            {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            // Reset sum to 0 if it becomes negative
            if (sum < 0)
            {
                sum = 0;
            }
        }

        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        // Return the maximum subarray sum found
        return maxi;
    }
};

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
