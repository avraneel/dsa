#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.back() == "+") {
            tokens.pop_back();
            return evalRPN(tokens) + evalRPN(tokens);
        }
        else if(tokens.back() == "-") {
            tokens.pop_back();
            int op1 = evalRPN(tokens);
            int op2 = evalRPN(tokens);
            return op2 - op1;
        }
        else if(tokens.back() == "*") {
            tokens.pop_back();
            return evalRPN(tokens) * evalRPN(tokens);
        }
        else if(tokens.back() == "/") {
            tokens.pop_back();
            int op1 = evalRPN(tokens);
            int op2 = evalRPN(tokens);
            if(op1 == 0 || op2 == 0) return 0;
            else return op2 / op1;
        }
        else {
            int num = stoi(tokens.back());
            tokens.pop_back();
            return num;
        }
    }
};