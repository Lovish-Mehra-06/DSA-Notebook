/*
 * Problem Info : 735. Asteroid Collision
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

#include <bits/stdc++.h>
using namespace std;

/*
! ------------------- With Stack ------------- n n -----------------------
Since a collision occurs only when a < 0 and stack.back() > 0:
- diff < 0: Current asteroid is larger → pop the previous asteroid.
- diff > 0: Previous asteroid is larger → set a = 0 to destroy the current asteroid.
- diff == 0: Both explode → pop the previous asteroid and set a = 0.
After the loop, if (a != 0) pushes the current asteroid only if it survives.


*ALGO
Initialize an empty stack.
For each asteroid, if it's positive or the stack is empty or the top is negative, push it.
If the asteroid is negative and the top is positive, compare sizes:
    If the top is smaller, pop it and continue checking.
    If they're equal, pop the top and discard the current asteroid.
    If the top is larger, discard the current asteroid.
After processing all asteroids, the stack contains the survivors.
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> stack;
        for (int &a : asteroids)
        {
            while (!stack.empty() && a < 0 && stack.back() > 0)
            {
                int diff = a + stack.back();
                if (diff < 0)
                    stack.pop_back();
                else if (diff > 0)
                    a = 0;
                else
                {
                    a = 0;
                    stack.pop_back();
                }
            }
            if (a != 0)
                stack.push_back(a);
        }
        return stack;
    }
};

/*
! --------------------- Without Stack ---------- n n -----------------------
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        int j = -1; // Top index of the stack

        for (int &a : asteroids)
        {
            // Collision occurs when previous moves right and current moves left
            while (j >= 0 && asteroids[j] > 0 && a < 0)
            {
                if (asteroids[j] > abs(a))
                {
                    a = 0; // Current asteroid explodes
                    break;
                }
                else if (asteroids[j] == abs(a))
                {
                    j--; // Both asteroids explode
                    a = 0;
                    break;
                }
                else
                {
                    j--; // Previous asteroid explodes; check for more collisions
                }
            }

            if (a != 0)
            {
                asteroids[++j] = a; // Keep the surviving asteroid
            }
        }

        asteroids.resize(j + 1); // Remove remaining elements beyond the stack
        return asteroids;
    }
};
// ----------------------- ROUGH -----------------------
/*   --- 1st try: ---
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;

        s.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++)
        {
            int n = asteroids[i];
            if (n * s.top() > 0) // same sign
                s.push(n);

            else // opp sign
            {
                bool flag = true;
                while (!s.empty() && flag)
                {
                    if (s.top() > n)
                        flag = false;
                    else
                    {
                        s.pop();
                        ///  then push,
                        /// i made it way to complicated
                    }
                }
            }
        }

        vector<int> ans;
        int i = 0;
        while (!s.empty())
        {
            ans[i++] = (s.top());
            s.pop();
        }
        return reverse(ans.begin(), ans.end());
    }
};

*/
/*
Fixed Code  --------------- n n ---------------

Things to care:
1. s.push(asteroids[0]) — unsafe if the input is empty. Start with an empty stack and process every asteroid from index 0.
2. n * s.top() > 0 — same-sign check is fine, but opposite signs do not always mean a collision. A collision occurs only when the stack's top is moving right (> 0) and the current asteroid is moving left (< 0).
3. if (s.top() > n) — incorrect collision comparison. Compare absolute sizes using abs(s.top()) and abs(n). If equal, both explode; if the top is larger, only the current asteroid explodes.
4. Missing push — if the current asteroid survives all collisions, push it onto the stack.
5. ans[i++] = s.top() — ans is empty, so indexing it causes undefined behavior. Use ans.push_back(s.top()).
6. return reverse(...) — reverse() returns void. Reverse the vector first, then return it.
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;

        for (int i = 0; i < asteroids.size(); i++)
        {
            int n = asteroids[i];
            bool alive = true;

            while (!s.empty() && s.top() > 0 && n < 0)
            {
                if (abs(s.top()) < abs(n))
                    s.pop();
                else if (abs(s.top()) == abs(n))
                {
                    s.pop();
                    alive = false;
                    break;
                }
                else
                {
                    alive = false;
                    break;
                }
            }

            if (alive)
                s.push(n);
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//  ---------------- More optimized solution:class Solution {
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;

        for (int a : asteroids)
        {
            while (!st.empty() && st.back() > 0 && a < 0)
            {
                if (st.back() < -a)
                {
                    st.pop_back(); // Previous asteroid explodes
                    continue;
                }
                else if (st.back() == -a)
                {
                    st.pop_back(); // Both explode
                }

                a = 0; // Current asteroid explodes
                break;
            }

            if (a != 0)
                st.push_back(a); // Asteroid survives
        }

        return st;
    }
};
;
// ---------------------- {Notes} ------------------------- would have been better to first think of when Collision can happens.. only 1 case is there
// ---------------------- {Practice} ----------------------
// With Stack
