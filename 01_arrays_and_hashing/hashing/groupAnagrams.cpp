/* 
Link: https://leetcode.com/problems/group-anagrams/

Approach:

This was a tough nut to crack. Let's go through with it.

The logic is to use either of the following as key for the hash map:
- character count gives $O(m * n)$ runtime - **Optimal**
	- for this we use a `count` array; example `[0,1,0,1,2]` for `"bdee"`
	- $m$ is the length of `strs` array
	- $n$ is the length of each string in `strs` array
- sorted string

In C++, there isn't any hash function for `array<int,26>` so we convert the `count` array to string format.
*/ 

#include <bits/stdc++.h>
using namespace std;

// Using character count as key approach
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		/* In C++, array<int, 26> or C style array isn't hashable
	       so we take string form of count to store the key */
        unordered_map<string, vector<string>> hm;
        for(auto str : strs) {
            int count[26] = {0};
            
            for(char c : str) {
	            /* Ascii of [a-z] is from 65-90, so we need to subtract it by
	               'a' (65) to get 0, 1, 2,.., frequency values */
                count[c - 'a']++; 
            }

			string key; // stores values in "1#0#0#2#0#1#2#5#0#" format
            for(int i = 0; i < 26; i++) {
		        /* count[i] + "#" -> is an arithmetic operation
		           so to_string() is needed */
                key += to_string(count[i]) + "#"; 
            }
            hm[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto item : hm) {
	        /* item.second gives the values of hm which are in vector<string>
	           format */
            ans.push_back(item.second);
        }
        return ans;
    }
};
