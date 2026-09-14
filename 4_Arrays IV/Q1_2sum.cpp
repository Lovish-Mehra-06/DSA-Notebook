/*
 * Problem Info : https://leetcode.com/problems/two-sum/description/
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/*
? 1. Brute Force Approach----------------------------------------------------------------------
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        int count = nums.size(); // fixed
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++){
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
? 2. Pointer Approach--------------------------------------------------------------------------
 - O(nlog n)
 - O(n)
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = A[i].first + A[j].first;
            if (cur == target) {
                return {min(A[i].second, A[j].second),
                max(A[i].second, A[j].second)};
            } else if (cur < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

 - -
https://neetcode.io/problems/two-integer-sum/solution
 - -

? 3. Hash Map (Two Pass)----------------------------------------------------------------------
Time complexity:  O(n)
Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;  // val -> index

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};

? 4. Hash Map (Two Pass)--------------------------------------------------------------------

*/