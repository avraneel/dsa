/*
Link: https://leetcode.com/problems/valid-anagram/

In anagrams, the letters and the frequency of each letter remains the same so I created the hashmap for each string
where <K,V> equals <letter, it's frequency>. Then I compare the two hashmaps to check if they are same or not.

Optimal: No need for two hashmaps. Get one. For string s, increase frequency by 1. For t, decrease frequency by 1.
If it's an anagram, all frequencies will be zero.

*/

// [NOT OPTIMAL] Two hm approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hm1;
        unordered_map<char, int> hm2;
        for (auto item : s) {
            if(hm1.find(item) == hm1.end())
                hm1[item] = 1;
            else 
                hm1[item]++;
        }
        for (auto item : t) {
            if(hm2.find(item) == hm2.end())
                hm2[item] = 1;
            else 
                hm2[item]++;
        }
        if(hm1 == hm2) 
            return true;
        else 
            return false;    
    }
};

/* [OPTIMAL] One hm approach
s = "anagram"
t = "nagaram"

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> hm;
        for(int i = 0; i < s.length(); i++) {
            hm[s[i]]++;
            hm[t[i]]--;
        }
        for(auto pair: hm) {
            if(pair.second != 0) 
                return false;
        }
        return true;   
    }
};