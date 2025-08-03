#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        /* Formatting string */
        for(char ch : s) {
            if(ch >= 65 && ch <= 90) {
                ch = ch + 32;
                s2 += static_cast<char>(ch);
            }
            else if((ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)) {
                s2 += ch;
            }
            else {
                continue;
            }
        }

        for(char ch : s2) {
            cout << ch;
        }

        
        int l = 0;
        int r = s2.length() - 1;

        if(s2=="")
            return true;

        while(l < r) {
            if(s2[l] != s2[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;

    }
};