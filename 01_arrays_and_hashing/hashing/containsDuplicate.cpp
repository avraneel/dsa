/* 
Link: https://leetcode.com/problems/contains-duplicate

Brute force: Two pointers, O(n2) time taken
2nd better: Use a hashmap, O(n) time taken

Optimal: Instead of a hashmap, use a hashset, as we are not bothered with
<K,V> pairs

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hs;
        for (auto item : nums) {
            if(hs.find(item) == hs.end()) {
                hs.insert(item);
            }
            else {
                return true;
            }
        }
        return false;
    }
};