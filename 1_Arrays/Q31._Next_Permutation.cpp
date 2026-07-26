#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/next-permutation/

//! --------------------------------------------- Approch 1  Own -----------------------------------------
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

//! --------------------------------------------- Approch 2  NeetCode -----------------------------------------
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

//! --------------------------------------------- Approch 3  Ai -----------------------------------------
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();

        // Step 1: Find pivot
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found,
        // current permutation is the largest
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find smallest element greater than pivot
        // from right side
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