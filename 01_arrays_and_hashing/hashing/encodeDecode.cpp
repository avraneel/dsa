/*
Link: https://neetcode.io/problems/string-encode-and-decode?list=blind75

Approach:

If s = ["sky","is","blue"]
then encoded = "3#sky2#is4#blue"

is we only make "sky#is#blue" then what if we have the string "bl#ue" in array?
adding the length in the encoded string tells how many characters to read.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto str:strs) {
            int l = str.size();
            ans += to_string(l) + "#";
            ans += str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int l = stoi(s.substr(i, j-i));
            i = j+1;
            ans.push_back(s.substr(i, l));
            i += l;
        }
        return ans;
    }
};
