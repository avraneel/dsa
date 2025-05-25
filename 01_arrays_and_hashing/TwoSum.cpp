/*
Link:

Brute force is O(n2), too slow.

Use hashmap. We need n + n' == target. 
Let us have [n1, n2, n3 ,n4]
Go through each element in array, for element n, if target - n = n', n' not in hashmap, store n in hashmap.
Now you reach n'. Check if target - n' = n present in hm. It is present! So output result. 

Imagine you are looking through the numbers one by one. One you see a number 
you note it down on a clipboard (lookup table/hashmap).
Now when you see the next number you check if it's complement exists in the clipboard (lookup table/hashmap).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(hm.find(complement) == hm.end()) {
                // not present in hm
                hm[nums[i]] = i;
            }
            else {
                result.push_back(hm[complement]);
                result.push_back(i);
            }
        }
        return result;
    }
};