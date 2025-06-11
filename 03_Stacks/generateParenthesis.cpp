#include <bits/stdc++.h>
using namespace std;

/* 
Link: https://leetcode.com/problems/generate-parentheses/

Approach:

- Draw the recursion tree diagram
- Keep separate counters for no. of open and closed parenthesis
- In order to make parenthesis valid, closed parenthesis will only be added if the open > closed.
- Base case, anyone can work:
    - open == n && close == n
    - s.size == n * 2
- Make sure to pass by reference
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        paren(ans, 0, 0, "", n);
        return ans;
    }

    /* Two condition are important:
        1. Closed bracket will only be added if open > closed.
        2. Base case: open = closed = n; */
    void paren(vector<string>& ans, int open, int closed, string s, int n) {
        /* This can also work as base case:
        if(open == n && closed == n) */
        if(s.size() == n*2) {
            ans.push_back(s);
            return;
        }
        if(open < n) {
            paren(ans, open+1, closed, s + "(", n);
        }
        if(open > closed) {
            paren(ans, open, closed+1, s + ")", n);
        } 
    }
};