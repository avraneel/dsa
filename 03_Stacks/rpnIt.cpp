#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(string s:tokens) {
            if (s == "+") {
                int res = stack.back();
                stack.pop_back();
                res += stack.back();
                stack.pop_back();
                stack.push_back(res);
            }
            else if (s == "-") {
                int op1 = stack.back();
                stack.pop_back();
                int op2 = stack.back();
                stack.pop_back();
                int res = op2 - op1;
                stack.push_back(res);
            }
            else if (s == "*") {
                int res = stack.back();
                stack.pop_back();
                res *= stack.back();
                stack.pop_back();
                stack.push_back(res);
            }
            else if (s == "/") {
                int op1 = stack.back();
                stack.pop_back();
                int op2 = stack.back();
                stack.pop_back();
                int res = 0;
                if(op1 == 0 || op2 == 0) res = 0;
                else res = op2 / op1;
                stack.push_back(res);
            }
            else {
                stack.push_back(stoi(s));
            }
        }
        return stack.back();
    }
};