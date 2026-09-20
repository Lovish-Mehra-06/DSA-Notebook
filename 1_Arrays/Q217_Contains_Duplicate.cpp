/*
 * Problem Info : 217. Contains Duplicate`
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

//! - - - - - - - - - - Approach 1: Brute force -TLE
//! - - - - - - - - - - Approach 2: Sort and then check logn and 1
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

//! - - - - - - - - - - Approach 3: Hash Set n n
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        unordered_set<int> st; // Create an unordered_set to store the unique elements

        // Iterate through each element
        for (int i = 0; i < n; i++)
        {
            // If the element is already present, return true
            // Else insert the element into the set
            if (st.find(nums[i]) != st.end())
                return true;
            else
                st.insert(nums[i]);
        }
        return false; // If no duplicates are found, return false
    }
};
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen; //       stores elements already visited

        for (int num : nums) //           iterate through each number
        {
            if (seen.count(num)) //       if number already exists in set
            {
                return true; //           duplicate found
            }
            seen.insert(num); //          store number in set
        }
        return false; //                  no duplicates found
    }
};
//! - - - - - - - - - - Approach 4: Hash Set LENGTH n n
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Create an unordered_set using all elements of nums, Set stores only unique elements (duplicates are ignored)
        unordered_set<int> unique(nums.begin(), nums.end());

        // If size of set is smaller than size of vector, it means duplicates were present
        return unique.size() < nums.size();
    }
};
