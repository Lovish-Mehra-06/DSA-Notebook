/*
 * Problem Info : 150. Evaluate Reverse Polish Notation / POST-Fix
 * Platform     : LeetCode
 * Difficulty   : Medium

Reverse Polish notation (RPN)  or
Łukasiewicz notation           or
Polish Postfix notation        or
simply Postfix notation          , is a mathematical notation in which operators follow their operands (e.g. 3 4 +)

 */

#include <bits/stdc++.h>
using namespace std;

//! ------------ Code with Stack  ----- n n
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++)
        {
            string val = (tokens[i]);
            if (val == "+" || val == "-" || val == "*" || val == "/")
            { // Operator
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if (val == "+")
                    stk.push(b + a);
                else if (val == "-")
                    stk.push(b - a);
                else if (val == "*")
                    stk.push(b * a);
                else if (val == "/")
                    stk.push(int(b / a));
            }
            else
                stk.push(stoi(val));
        }
        return stk.top();
    }
};

// similar code
/*
class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& c : tokens) {
            if (c == "+") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b + a);
            } else if (c == "-") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b - a);
            } else if (c == "*") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b * a);
            } else if (c == "/") {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
*/

/*
! -------------------- Approach2: Recursion  --------- n n --------------------

* Intuition
Reverse Polish Notation works naturally with recursion because
every operator applies to the two most recent values that come before it.
If we process the expression from the end, every time we see:
  - a number → it is simply returned as a value
  - an operator → we recursively evaluate the two values that belong to it

This creates a natural evaluation tree:
  - Each operator becomes a recursive call,
  - Each number becomes a base case,
  - And the final return value is the fully evaluated expression.
This approach is clean, elegant, and mirrors the structure of RPN itself.

* Algorithm
1. Start from the end of the token list.
2. Recursively:
    -> Pop a token.
    -> If it is a number, return it.
    -> If it is an operator:
        - Recursively compute the right operand.
        - Recursively compute the left operand.
        - Apply the operator to both results.
        - Return the computed value.
3. The first completed call returns the final answer.
*/
class Solution
{
public:
    int dfs(vector<string> &tokens)
    {
        string token = tokens.back();
        tokens.pop_back();

        if (token != "+" && token != "-" && token != "*" && token != "/")
            return stoi(token);

        int right = dfs(tokens);
        int left = dfs(tokens);

        if (token == "+")
            return left + right;
        else if (token == "-")
            return left - right;
        else if (token == "*")
            return left * right;
        else
            return left / right;
    }

    int evalRPN(vector<string> &tokens)
    {
        return dfs(tokens);
    }
};

/*
! -------------------- Approach3: Doubly Linked List  --------- n n --------------------

*Intuition
In Reverse Polish Notation, every operator works on the two most recent numbers before it.
A doubly linked list lets us move both left and right easily, so when we find an operator, we can quickly reach the two numbers before it.

The idea is:
- Build a doubly linked list of all tokens (numbers and operators).
- Walk through the list:
    -> When we see an operator, we look at the previous two nodes (the two operands),
     compute the result, and replace those three nodes (left, right, operator) with a single node containing the result.
- We keep doing this until we've processed all operators and are left with just one value.

This behaves like the usual RPN evaluation but uses linked list navigation instead of a stack.

*Algorithm
1.Create a doubly linked list from the tokens in order.
2. Set a pointer curr to the head of the list.
3. While the list still needs evaluation:
    - If curr is an operator:
        - Let the two nodes before curr be the left and right operands.
        - Compute the result of left (op) right.
        - Replace the three nodes (left, right, operator) with a single node holding the result:
            - Relink the prev and next pointers around them.
            - Set curr to this result node.
    - Move curr to the next node and continue.
4. When only one node with a number remains, return its value as the final result.

*/

class DoublyLinkedList
{
public:
    string val;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;

    DoublyLinkedList(string val, DoublyLinkedList *next = nullptr, DoublyLinkedList *prev = nullptr)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        DoublyLinkedList *head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList *curr = head;

        for (int i = 1; i < tokens.size(); i++)
        {
            curr->next = new DoublyLinkedList(tokens[i], nullptr, curr);
            curr = curr->next;
        }

        int ans = 0;
        while (head != nullptr)
        {
            if (head->val == "+" || head->val == "-" || head->val == "*" || head->val == "/")
            {
                int l = stoi(head->prev->prev->val);
                int r = stoi(head->prev->val);
                int res = 0;
                if (head->val == "+")
                    res = l + r;
                else if (head->val == "-")
                    res = l - r;
                else if (head->val == "*")
                    res = l * r;
                else
                    res = l / r;

                head->val = to_string(res);
                head->prev = head->prev->prev->prev;
                if (head->prev != nullptr)
                    head->prev->next = head;
            }

            ans = stoi(head->val);
            head = head->next;
        }

        return ans;
    }
};