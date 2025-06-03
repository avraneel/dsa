/*
Link: https://leetcode.com/problems/valid-parentheses/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        if(s.size() % 2 != 0) return false;

        for(auto ch : s) {
            if(ch == '(' || ch == '{' || ch ==  '[') {
                stack.push_back(ch);
            }
            else if(stack.empty() && (ch == ')' || ch == '}' || ch == ']')) {
                return false;
            }
            else if(ch == ')' && stack.back() == '(') {
                cout << "f";
                stack.pop_back();
            }
            else if(ch == '}' && stack.back() == '{') {
                stack.pop_back();
            }
            else if(ch == ']' && stack.back() == '[') {
                stack.pop_back();
            }
            else {
                return false;
            }
        }

        if(stack.size() == 0) return true;
        else return false;
    }
};
