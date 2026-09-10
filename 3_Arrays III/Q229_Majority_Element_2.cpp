/*
 * Problem Link : https://leetcode.com/problems/majority-element-ii/description
 ! Problem Name : Majority Element II
 * Problem No.  : 229
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
!  Brute Force Approach -------------------------------------------------------

? Time : O(n^2)
? Space: O(1)

Can have only Max 2 numbers Greater than 3*/
class Solution
{
public:
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result; // List of answers

        for (int i = 0; i < n; i++)
        {
            /*Checking if nums[i] is not already part of the answer*/
            if (result.size() == 0 || result[0] != nums[i])
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    // counting the frequency of nums[i]
                    if (nums[j] == nums[i])
                        cnt++;
                }
                // check if frequency is greater than n/3:
                if (cnt > (n / 3))
                    result.push_back(nums[i]);
            }
            // if result size is equal to 2 break out of loop, as max 2 are possible only mathematically
            if (result.size() == 2)
                break;
        }
        return result;
    }
};

/*
! Better Approach 2:  Using Hash Map  -------------------------------------------------------
store all elements in a hash map
and check in end which one's occurrence is > n/2 that is our answer.

? Time : O(n)
? Space: O(n)
*/
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result; // list of answers
    unordered_map<int, int> mpp;

    int mini = int(n / 3) + 1; // least occurrence of the majority element

    // storing the elements with its occurrence
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;

        // checking if nums[i] is the majority element
        if (mpp[nums[i]] == mini)
            result.push_back(nums[i]);

        // if result size is equal to 2 break out of loop
        if (result.size() == 2)
            break;
    }
    return result; // return the majority elements
}

//  Approach 2 ---> Mine, Max Element 1st one changed:, although not much optimal as above code
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> result;
        unordered_map<int, int> map1;

        for (int i : nums)
            map1[i]++;

        for (auto &pair : map1)
        {
            if (pair.second > n / 3)
            {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};

/*
! Approach 3: Sort, & then n/3th and 2*n /3 th element, count/verify >n then we get ans -----------------------
? Time : O(n log n)  for sorting
? Space: O(1)*

Sort the array.
Take possible candidates from positions:
n/3
2*n/3
For each candidate, count its occurrences.
Add it to the answer if count > n/3.
Make sure you don't add the same candidate twice.

? Complexity:
Sorting: O(n log n)
Counting: O(n)
Extra space: O(1) (apart from the output)
So you can absolutely solve it this way; you don't need the Boyer-Moore approach.
*/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans;

        int c1 = nums[n / 3];
        int c2 = nums[(2 * n) / 3];

        int count1 = 0, count2 = 0;

        for (int x : nums)
        {
            if (x == c1)
                count1++;
            if (x == c2)
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(c1);

        if (c2 != c1 && count2 > n / 3)
            ans.push_back(c2);

        return ans;
    }
};

/*
!  Optimal Solution:   - Boyer-Moore Voting Algorithm --------------------------------------------------------

?   Time Complexity:  O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
?   Space Complexity: O(1), as we are using only a constant amount of extra space.

Initialize four variables: cnt1 and cnt2 for tracking the counts of elements, and el1 and el2 for storing the potential majority elements.
Traverse through the given array:
If cnt1 is 0 and the current element is not equal to el2, set el1 to the current element and increment cnt1 by 1.
If cnt2 is 0 and the current element is not equal to el1, set el2 to the current element and increment cnt2 by 1.
If the current element is equal to el1, increment cnt1 by 1.
If the current element is equal to el2, increment cnt2 by 1.
In all other cases, decrease cnt1 and cnt2 by 1.
After processing all elements, el1 and el2 should be the candidate elements for majority. To confirm:
Use another loop to manually check the counts of el1 and el2 in the array.
If either el1 or el2's count is greater than floor(N/3), it is considered a valid majority element.

*/
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ctr1 = 0, ctr2 = 0, candidate1 = INT16_MIN, candidate2 = INT16_MIN;
        int n = nums.size();

        // Find possible candidates
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate1)
                ctr1++;
            else if (nums[i] == candidate2)
                ctr2++;
            else if (ctr1 == 0)
            {
                ctr1 = 1;
                candidate1 = nums[i];
            }
            else if (ctr2 == 0)
            {
                ctr2 = 1;
                candidate2 = nums[i];
            }
            else
            {
                ctr1--;
                ctr2--;
            }
        }

        // Verify candidates, 1st Count then check >n/3 or not
        ctr1 = ctr2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate1)
                ctr1++;
            else if (nums[i] == candidate2)
                ctr2++;
        }

        vector<int> ans;
        if (ctr1 > n / 3)
            ans.push_back(candidate1);
        if (ctr2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};

//? ------------ Optimal Code: ------------
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find majority elements in an array
    vector<int> majorityElementTwo(vector<int> &nums)
    {

        // Size of the array
        int n = nums.size();

        // Counts for elements el1 and el2
        int cnt1 = 0, cnt2 = 0;

        // Initialize Element 1 and Element 2 with INT_MIN value
        int el1 = INT_MIN, el2 = INT_MIN;

        // Find the potential candidates using Boyer Moore's Voting Algorithm
        for (int i = 0; i < n; i++)
        {

            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                // Initialize el1 as nums[i]
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                // Initialize el2 as nums[i]
                el2 = nums[i];
            }
            else if (nums[i] == el1)
            {
                // Increment count for el1
                cnt1++;
            }
            else if (nums[i] == el2)
            {
                // Increment count for el2
                cnt2++;
            }
            else
            {
                // Decrement count for el1
                cnt1--;
                // Decrement count for el2
                cnt2--;
            }
        }

        // Validate the candidates by counting occurrences in nums
        // Reset counts for el1 and el2
        cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
            {
                // Count occurrences of el1
                cnt1++;
            }
            if (nums[i] == el2)
            {
                // Count occurrences of el2
                cnt2++;
            }
        }

        // Determine the minimum count required for a majority element
        int mini = n / 3 + 1;

        // List of answers
        vector<int> result;

        /*Add elements to the result vector
        if they appear more than n/3 times*/
        if (cnt1 >= mini)
        {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2)
        {
            // Avoid adding duplicate if el1 == el2
            result.push_back(el2);
        }

        // Uncomment the following line if you want to sort the answer array
        // sort(result.begin(), result.end()); // TC --> O(2*log2) ~ O(1);

        // return the majority elements
        return result;
    }
};

// int main()  - - Driver Code - -
// {
//     vector<int> arr = {11, 33, 33, 11, 33, 11};

//     // Create an instance of Solution class
//     Solution sol;

//     vector<int> ans = sol.majorityElementTwo(arr);

//     // Print the majority elements found
//     cout << "The majority elements are: ";
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     cout << "\n";

//     return 0;
// }