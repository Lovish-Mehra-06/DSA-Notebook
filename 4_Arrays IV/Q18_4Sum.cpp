/*
 * Problem Info : 18. 4Sum
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

//! - - - - - - - - Approach 2: (see below) Fixed- - - - - - - -
// class Solution{
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target){
//         int n = nums.size();
//         vector<vector<int>> set;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n - 3; i++){
//             for (int j = i + 1; j < n - 2; j++){
//                 long long newTarget = (long long)target - nums[i] - nums[j];
//                 int low = j + 1, high = n - 1;
//                 while (low < high)
//                 {
//                     if (nums[low] + nums[high] < newTarget)
//                         low++;
//                     else if (nums[low] + nums[high] > newTarget)
//                         high--;
//                     else
//                     {
//                         set.push_back({nums[i], nums[j], nums[low], nums[high]});
//                         low++, high--;
//                     }
//                 }
//             }
//         }
//         return set;
//     }
// };
//*Error
// Yes. The issue is duplicate quadruplets. With [2,2,2,2,2], your loops find the same [2,2,2,2] multiple times.
// Keeping your code almost exactly the same, just add duplicate checks:
/*
! - - - - - - - - Approach 2: Sorting + Two Nested Loops + Two Pointers - - - - - - - -


? Algo:
- Create a set to keep only unique groups of four numbers.
- Run the first loop from the start to the end of the array to pick the first number.
- Inside it, run the second loop from the next position to pick the second number.
- Before starting the third loop, make a HashSet to keep track of numbers between the second and third positions.
- Run the third loop from the next position after the second number to the end of the array to pick the third number.
- Find the fourth number by subtracting the total of the first three numbers from the target value.
- If this fourth number is already in the HashSet, arrange all four numbers in order and add them to the set.
- Add the current third number to the HashSet (only numbers between the second and third loops are stored).
- After all loops finish, return the set as a list of unique groups of four numbers.


? Time:  O(n³)
? Space: O(1) excluding the output.   O(no of unique quadruplets)

Your "vector<vector<int>> set" stores the answers.
If there are K unique quadruplets:
Space = O(K)
Apart from output, your algorithm uses only constant extra space:
Auxiliary Space = O(1)
So for your exact approach:
  -  Sorting: O(N log N)
  -  Three-pointer levels: O(N³)
  -  Overall: O(N³)
  -  Auxiliary space: O(1)
  -  Output space: O(K), where K = number of quadruplets.


  Extra: if set - insert() is used then time will be n^3 * logM approach 3
  */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> set;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;

                while (low < high)
                {
                    if (nums[low] + nums[high] < newTarget)
                        low++;
                    else if (nums[low] + nums[high] > newTarget)
                        high--;
                    else
                    {
                        set.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++, high--;

                        while (low < high && nums[low] == nums[low - 1])
                            low++;

                        while (low < high && nums[high] == nums[high + 1])
                            high--;
                    }
                }
            }
        }
        return set;
    }
};

/*
! - - - - - - - - Approach 3: Sorting + 2 nested loops + Hash Map. - - - - - - - -
Complexity
- Sorting: O(N log N)
- 3 nested loops effectively: O(N³)
- Hash-map lookup: O(1) average
- set insertion: O(log K)
So approximately:

?  Time:   O(N³ log K)    because of the set.
?  Space:  O(N + K)
- N → hash map
- K → unique quadruplets in set

* Your two-pointer approach(2nd one above) is better because it achieves O(N³) without needing the set.

*/
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                unordered_map<long long, int> mp;

                for (int k = j + 1; k < n; k++)
                {
                    long long required =
                        (long long)target - nums[i] - nums[j] - nums[k];

                    if (mp.count(required))
                    {
                        st.insert({nums[i], nums[j],
                                   (int)required, nums[k]});
                    }

                    mp[nums[k]]++;
                }
            }
        }

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};

//! - - - - - - - - Approach 1: Brute Force O(n^4) O(1) - - - - - - - -

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    // Get size of array
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}