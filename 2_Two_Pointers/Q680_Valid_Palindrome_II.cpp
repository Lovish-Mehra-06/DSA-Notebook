/*
 * Problem Info : Problem Link
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

// Brute Force - n^2 and n  -*Memory Limit Exceeded
class Solution
{
public:
    bool validPalindrome(string s)
    {
        if (isPalindrome(s))
            return true;

        for (int i = 0; i < s.length(); i++)
        {
            string newStr = s.substr(0, i) + s.substr(i + 1, s.length() - i - 1);
            // string str = s.substr(0, i) + s.substr(i + 1);                    - OR just this :)

            if (isPalindrome(newStr))
                return true;
        }

        return false;
    }

    // Palindrome - question
    bool isPalindrome(const string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

/*
! - - - Approach 2: 2 Pointer    n  n

* Intuition:
Instead of blindly trying every removal, we can be smarter.
Use two pointers starting from both ends of the string and move them inward. As long as characters match, keep going.
When we find a mismatch, we know exactly where the problem is.
At this point, we have only two choices: remove the left character or remove the right character.
We check if either choice results in a palindrome for the remaining substring.
*/
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r])
                return isPalindrome(s.substr(0, l) + s.substr(l + 1)) || isPalindrome(s.substr(0, r) + s.substr(r + 1));
            l++;
            r--;
        }

        return true;
    }

    // Palindrome - question
    bool isPalindrome(const string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

/*
! - - - Approach 3: 2 Pointer    n  1     *Optimal Solution

* Intuition:
The previous two-pointer solution creates new substrings, which costs O(n) space.
We can optimize this by passing index bounds to our palindrome check function instead of creating new strings.
This way, we check the same characters without allocating extra memory.
The logic remains identical: find the first mismatch, then verify if skipping either character leads to a valid palindrome.
*/
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r])
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            l++;
            r--;
        }
        return true;
    }

private:
    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};