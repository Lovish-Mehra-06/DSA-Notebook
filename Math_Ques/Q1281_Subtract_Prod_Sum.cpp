/*
 * Problem Link : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
 ! Problem Name : subtract-the-product-and-sum-of-digits-of-an-integer
 * Problem No.  : 1281
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int prod = 1, sum = 0;

        while (n != 0)
        {
            int rem = n % 10;
            prod = (prod * rem);
            sum = (sum + rem);
            n = n / 10;
        }
        return (prod - sum);
    }
};