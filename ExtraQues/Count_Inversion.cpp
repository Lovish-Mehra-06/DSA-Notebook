#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/data-structure/count-inversions-in-an-array

//! Brute Force:
int numberOfInversions(vector<int> &a, int n)
{
    int cnt = 0; // Initialize inversion count
    // Check all pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                cnt++; // Increment count if inversion found
        }
    }
    return cnt; // Return total inversions
}

//! Optimal Sol:
