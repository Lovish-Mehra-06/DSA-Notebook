/*
 * Problem Info : 853. Car Fleet
 * Platform     : LeetCode
 * Difficulty   : Medium
 */

/*
*Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

/*
! ---------------------- Using Stack ----------------------
? Time complexity:   O(n log n)
? Space complexity:  O(n)

*Intuition
Cars that start closer to the target are processed first.
For each car, we compute the time it will take to reach the target.
If a car behind reaches the target no faster than the car in front, it will eventually catch up and join the same fleet.
So we only keep the car’s time if it forms a new fleet; otherwise, it merges with the previous one.
Using a stack helps us easily compare each car’s time with the fleet ahead of it.

*/
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> cars; // {position, speed}

        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend()); // Sort cars by position in descending order (closest to target first)

        vector<double> st; // Arrival times of separate fleets

        for (auto &p : cars)
        {
            double time = (double)(target - p.first) / p.second; // Time = distance / speed
            st.push_back(time);

            if (st.size() >= 2 && st.back() <= st[st.size() - 2]) // If this car catches the fleet ahead, merge them
                st.pop_back();
        }
        return st.size(); // Number of fleets
    }
};

/*
------------------------ Notes: --------------------------
*rbegin() and rend() are used to sort the cars by position in descending order (closest to the target first).
sort(pair.rbegin(), pair.rend());


- begin()  → points to the first element.
- end()    → points just after the last element.
- rbegin() → points to the last element.
- rend()   → points just before the first element.

Example
pair = {{10, 2}, {3, 3}, {7, 1}};
sort(pair.rbegin(), pair.rend());

Result:
{{10, 2}, {7, 1}, {3, 3}}

The cars are sorted from nearest to the target to farthest.
This is important because we calculate arrival times starting with the car closest to the target. If a car behind reaches the target sooner than or at the same time as the fleet ahead, it joins that fleet.
Alternative: You could use sort(pair.begin(), pair.end(), greater<>()); to get the same descending order.

--- --- --- --- --- --- --- --- --- --- --- ---
*What does the if statement do?
if (st.size() >= 2 && st.back() <= st[st.size() - 2])
st.pop_back();


- st.back() → arrival time of the current car.
- st[st.size() - 2] → arrival time of the fleet ahead.
- If the current car's time is less than or equal to the fleet ahead's time, it catches up and joins that fleet.
- pop_back() removes its time because it doesn't form a separate fleet.
--- --- --- --- --- --- --- --- --- --- --- ---
*Example walkthrough
target = 12
position = [10, 8, 0]
speed    = [ 2, 4, 1]


Cars are sorted closest to the target first:
Position	Speed	       Arrival time
10	            2	    (12−10)/2 = 1
8	            4	    (12−8)/4  = 1
0	            1	    (12−0)/1  = 12
1. Car at position 10: time = 1. Stack: [1]
2. Car at position 8: time = 1. Since 1 <= 1, it joins the fleet ahead. Stack: [1]
3. Car at position 0: time = 12. Since 12 > 1, it cannot catch the fleet ahead before the target. Stack: [1, 12]
Answer: 2 fleets.


Short notes for future reference
--> Sort cars by position, closest to target first.
--> Calculate each car's time to reach the target.
--> If its time <= the fleet ahead's time, it catches up and joins it.
--> Otherwise, it forms a new fleet.
--> Stack size = total number of fleets.

*/

/*
! ---------------------- Iteration ----------------------
? Time complexity:   O(n log n)
? Space complexity:  O(n)

*Intuition:
After sorting cars from closest to the target to farthest, we calculate how long each one needs to reach the target.
A car forms a new fleet only if it takes longer than the fleet in front of it.
If it takes the same time or less, it will eventually catch up and merge into that fleet.
So instead of using a stack, we just keep track of the most recent fleet time.

*Algo:
1. Pair each car’s position with its speed and sort descending by position.
2. Start with the first car forming the first fleet.
3. Keep track of the fleet's time (prevTime) - the time of the car closest to the target.
4. For each remaining car:
    - Compute its time to reach the target.
    - If this time is greater than prevTime, it cannot catch up and forms a new fleet.
        - Increase fleet count.
        - Update prevTime to this new time.
    - Otherwise, it merges with the existing fleet and do nothing.
5. Return the number of fleets.

*/
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars; // {position, speed}
        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend()); // Sort cars by position in descending order, Cars closest to the target come first

        int fleets = 1; // Initially, the car closest to target forms one fleet

        double prevTime = (double)(target - cars[0].first) / cars[0].second; // Time taken by the first car to reach the target

        for (int i = 1; i < n; i++) // Process the remaining cars from front to back
        {
            double currTime = (double)(target - cars[i].first) / cars[i].second; // Calculate the current car's time to reach target

            if (currTime > prevTime) // If this car takes longer, it cannot catch the fleet ahead.  So, it forms a new fleet
            {
                fleets++;
                prevTime = currTime; // Update the time of the fleet now ahead
            }
            // Otherwise, this car catches the fleet ahead. It joins that fleet, so NO new fleet is counted
        }
        return fleets; // Return the total number of fleets
    }
};

/*

--- --- --- --- --- --- Common pitfalls: --- --- --- --- --- ---

Wrong: integer division truncates
*    int time = (target - position) / speed;
Correct: cast to double for precise time
*    double time = (double)(target - position) / speed;

*/