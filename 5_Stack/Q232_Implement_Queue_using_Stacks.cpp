/*
 * Problem Info : 232. Implement Queue using Stacks
 * Platform     : LeetCode
 * Difficulty   : Easy
 */

#include <bits/stdc++.h>
using namespace std;
/*
! -------------------- Using 2 Stacks (Brute Force Approach) --------------------

? Time Complexity:
O(1)   time for initialization.
O(1)   time for each "push()" and "empty()" function calls.
O( n ) time for each "pop()" and "peek()" function calls.

? Space complexity: O(n)
*/
// -------------------- 1st try  --> Submitted -------------------- 5-10 mins
class MyQueue
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {}

    void push(int x) { stack1.push(x); }

    int pop()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int removedVal = stack2.top();
        stack2.pop();

        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return removedVal;
    }

    int peek()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int removedVal = stack2.top();

        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return removedVal;
    }

    bool empty() { return stack1.empty(); }
};

/*
! -------------------- Using 2 Stacks (amortized-complexity Approach) --------------------

? Time Complexity:
O(1)            time for initialization.
O(1)            time for each "push()" and "empty()" function calls.
O(1)  amortized time for each "pop()" and "peek()" function calls.

? Space complexity: O(n)

*Intuition:
Instead of moving elements back after each pop, we can keep them in the second stack.
stack1 handles incoming elements (push), while stack2 holds elements in reversed order for popping.
When stack2 is empty and we need to pop, we transfer all elements from stack1 to stack2 at once.
Each element is moved at most twice (once to stack2, once when popped), giving amortized O(1) per operation.

todo...
*/
class MyQueue
{
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }
};