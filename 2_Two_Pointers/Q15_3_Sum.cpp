
/*
 * Problem Info : 15. 3Sum
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

*Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

*Example 2:
Input: nums = [0,1,1]    Output: []           Explanation: The only possible triplet does not sum up to 0.

*Example 3:
Input: nums = [0,0,0]    Output: [[0,0,0]]    Explanation: The only possible triplet sums up to 0.
*/

/*
!  - - - - - - - -  Approach 1: Brute Force +sorting - - - - - - - -
?    n^3
?    m + for sorting algo;
Where m is the number of unique triplets and  n is the length of the given array.
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                for (int k = j + 1; k < nums.size(); k++)
                    if (nums[i] + nums[j] + nums[k] == 0)
                        res.insert({nums[i], nums[j], nums[k]});

        return vector<vector<int>>(res.begin(), res.end());
    }
};

/*
!  - - - - - - - -  Approach 2: Hash Map - - - - - - - -
?    n^2
?    n
 - This excludes the space used for the output list.
 - O(n) is used for the frequency map.
 - If the output list is included, the space is O(n+m), which is O(n^2) in the worst case.
Where 'm' is the number of unique triplets and 'n' is the length of the given array.
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        for (int num : nums)
            count[num]++;

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                count[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int target = -(nums[i] + nums[j]);
                if (count[target] > 0)
                    res.push_back({nums[i], nums[j], target});
            }

            for (int j = i + 1; j < nums.size(); j++)
                count[nums[j]]++;
        }

        return res;
    }
};
/*
!  - - - - - - - - Approach 2: 2 Pointer + sorting - - - - - - - - *Optimal Solution
?    n^2
?     1   + Space used for sorting algo
If the output list is included, the space is O(m), which is O(n^2) in the worst case.
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r] + nums[i];

                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                }
            }
        }
        return res;
    }
};