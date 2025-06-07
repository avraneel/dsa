#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        // If odd length string then automatically invalid
        if(s.size() % 2 != 0) return false;

        for(auto ch : s) {
            if(ch == '(' || ch == '{' || ch ==  '[') {
                stack.push_back(ch);
            }
            /* Case: if the first bracket pushed in the stack is a closing
               bracket */
            else if(stack.empty() && (ch == ')' || ch == '}' || ch == ']')) {
                return false;
            }
            /* Only pop if we find closing bracket of same kind */
            else if(ch == ')' && stack.back() == '(') {
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

        /* Valid string should have all items emptied by now */
        if(stack.size() == 0) return true;
        else return false;
    }
};