/*
Link:

Approach:

First, put all elements to a set for O(1) lookup
Then, check for nums[i], nums[i] - 1 exists or not. If does not exist, then
nums[i] is the starting element of a sequence, update length as 1. If it exists, skip nums[i].

Now for sequence checking, check if nums[i]+1 exists on the set. If it does, 
update len and then update nums[i] to next value and repeat.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans;
        for(auto item:nums) {
            ans.insert(item);
        }
        int maxlen = 0;
        for(auto item:ans) {
            int len = 0;
            if(ans.find(item-1) == ans.end()) {
                /* Previous number does not exist in set, so,
                It's the start of a sequence */
                len++;
                /* Checking if next element of the sequence exists in the set,
                updating length if that's the case. */
                while(ans.find(item+1) != ans.end()) {
                    len++;
                    item++;
                }
            }
            if(len > maxlen) maxlen = len;
            len = 0; // Reset the value for nnext seq
        }
        return maxlen;
    }
};