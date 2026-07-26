/*
 * Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 ! Problem Name : Best Time to Buy and Sell Stock
 * Problem No.  : 121
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
?   Time  complexity:  O(n)
?   Space complexity:  O(1)
Approach name: ✅ Dynamic Programming (Greedy variant)

❌ Not Two Pointers (we’re not moving two indices independently)

✅ DP idea:

Keep the minimum price so far

Compute best profit up to current day

Also commonly called Single-pass Greedy in interviews

👉 Short answer to say: Greedy / Dynamic Programming (optimized DP)
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                int justProfit = prices[i] - min;
                if (justProfit > maxProfit)
                {
                    maxProfit = justProfit;
                }
            }
        }
        return maxProfit;
    }
};

// https://neetcode.io/problems/buy-and-sell-crypto/solution
// TODO -------------------------------- NeetCODE -------------- 1. Brute Force ------------------
//?   Time  complexity:  O(n^2)
//?   Space complexity:  O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                int sell = prices[j];
                res = max(res, sell - buy);
            }
        }
        return res;
    }
};

// TODO -------------------------------- NeetCODE -------------- 2. Two Pointers ------------------
//?   Time  complexity:  O(n)
//?   Space complexity:  O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

// TODO -------------------------------- NeetCODE -------------- 3. Dynamic Programming ------------------
//?   Time  complexity:  O(n)
//?   Space complexity:  O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;
        int minBuy = prices[0];

        for (int &sell : prices)
        {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};
// added comments
/*
! Logic in one line 🧠:

Track the lowest buy price so far and keep updating the best profit if sold today.
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;           // stores maximum profit so far
        int minBuy = prices[0]; // minimum price seen so far (best buy)

        // iterate through each day's selling price
        for (int &sell : prices)
        {
            // profit if we sell today after buying at minBuy
            maxP = max(maxP, sell - minBuy);

            // update minimum buying price
            minBuy = min(minBuy, sell);
        }

        return maxP; // final maximum profit
    }
};
