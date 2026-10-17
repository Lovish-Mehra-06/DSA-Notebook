/*
 * Problem Info : 225. Implement Stack using Queues
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;

/*
! ----- Approach 1: --> "2 Queues" -------------------------------------------
? Time Complexity:
O(1)   time for initialization.
O( n ) time for each "push()" function call.
O(1)   time for each "pop()" function call.
? Space complexity:
O( n )

*/
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
! ----- Approach 2: --> "1 Queue" -------------------------------------------
? Time Complexity:
O(1)   time for initialization.
O( n ) time for each "push()" function call. DO CHANGE TITITITITITITIITIT IT
todo
O(1)   time for each "pop()" function call.
? Space complexity:
O( n )

*

*/

/*
todo
! ----- Approach 3: --> "abcd" -------------------------------------------
? Time Complexity:
O(1)   time for initialization.
O( n ) time for each "push()" function call.
O(1)   time for each "pop()" function call.
? Space complexity:
O( n )

*

*/