/*
 * Problem Info : 3. Longest Substring Without Repeating Characters
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
!  - - - Optimal Solution - - - Sliding Window
?  O(n) average time,
?  O(n) space.

* Algo:
Expand if all characters are Unique
Shrink if duplicate is Found
*/
//! 1.1 My code + some hints taken by ai
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> hashSet; // to store substring to check later for duplicates
        int ans = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) // expand if all chars are unique, else shrink
        {
            char r = s[right];

            if (!hashSet.count(r))
                hashSet.insert(r);

            else
            {
                while (hashSet.count(r))
                {
                    char l = s[left++];
                    hashSet.erase(l);
                }
                hashSet.insert(r);
            }
            int n = hashSet.size();
            ans = max(ans, n);
        }
        return ans;
    }
};
//! 1.2 -AI Cleaner Version
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hashSet;
        int ans = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char r = s[right];

            while (hashSet.count(r))
            {
                hashSet.erase(s[left++]);
            }

            hashSet.insert(r);

            ans = max(ans, (int)hashSet.size());
        }

        return ans;
    }
};

/*
!  - - - Approach 2: Sliding Window + Last Seen Index  - - -  * better - less space (static :) - Help

?  O(n) average time,
?  O(1) space.    ***** Improved


### Algorithm: Sliding Window + Last Seen Index

1. Create an array `last[256]` and initialize every value to `-1`.
2. Maintain two pointers: `left = 0` and `right`.
3. Move `right` through the string.
4. For each character:
   - Get its previous index from `last`.
   - Move `left` to `last[s[right]] + 1` if needed.
   - Update its latest index.
5. Calculate the current window length: right - left + 1
6. Keep updating the maximum length in `ans`.
7. Return `ans`.

*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> last(256, -1);
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++)
        {
            left = max(left, last[s[right]] + 1);
            last[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};