/*
 * Problem Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 ! Problem Name : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 * Problem No.  : 1523
 * Platform     : LeetCode
 * Source       : Striver SDE Sheet
 * Difficulty   : Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
!           My Code
Yes, your code is **correct** for the given constraints (`low` and `high` are non-negative).
? Complexity: O(1) time and O(1) space.
It can be simplified, but there is no correctness issue with your current code.

*/
//  class Solution {
//  public:
//      int countOdds(int low, int high) {
//          if (low % 2 == 0 && high % 2 == 0) {
//              return ((high - low) / 2);
//          } else {
//              if (low % 2 != 0 && high % 2 != 0) {
//                  return ((high - low) / 2) + 1;
//              }
//              return ((high - low + 1) / 2);
//          }
//      }
//  };

/*
! Optimal code
? Time: O(1)
? Space: O(1)

Think of it as:
 *number of odd numbers from 0 to high − number of odd numbers before low.

 Formula: (high + 1) / 2 - low / 2

(high + 1) / 2 = count of odd numbers from 0 to high
low / 2 = count of odd numbers before low

Example: low=3, high=7
(7+1)/2 - 3/2 = 4 - 1 = 3
Odd numbers: 3, 5, 7

More Examples:
[3,7]  -> 4 - 1 = 3  (3,5,7)
[2,6]  -> 3 - 1 = 2  (3,5)
[1,4]  -> 2 - 0 = 2  (1,3)
[4,4]  -> 2 - 2 = 0
*/

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - low / 2;
    }
};