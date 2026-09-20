/*
 * Problem Info : 242. Valid Anagram
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

// Hash Set
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int count[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            count[tolower(s[i]) - 'a']++;
            count[tolower(t[i]) - 'a']--;
        }

        // Check if all counts are zero
        for (int i = 0; i < 26; i++)
            if (count[i] != 0)
                return false;

        return true;
    }
};

// Sorting:
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        if (n != m)
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t)
            return true;

        return false;
    }
};

//!!! FOLLOW UP : What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> count;

        if (s.size() != t.size())
            return false;

        for (char c : s)
            count[c]++;

        for (char c : t)
        {
            count[c]--;

            if (count[c] < 0)
                return false;
        }

        return true;
    }
};