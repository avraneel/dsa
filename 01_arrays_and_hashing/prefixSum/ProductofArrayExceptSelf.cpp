/*
Link: https://leetcode.com/problems/product-of-array-except-self/

Approach:

Use prefix sum logic.
ans[i] = pre[i] * suf[i] 
We need to STORE these elements in other arrays.

Example = [1,2,3,4]
Initialize pre[0] = 1 and suf[nums.size()-1] = 1, so,
pre = [1,1,2,6]
suf = [24,12,4,1]

Be careful about suffix sum, this is like prefix sum but we should iterate
from the back. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), suf(nums.size()), ans(nums.size());

        pre[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            pre[i] = pre[i-1] * nums[i-1];  // nums[i-1] because ith element isn't included
        }

        suf[nums.size()-1] = 1;
        for(int i = nums.size()-2; i >= 0; i--) {
            suf[i] = suf[i+1] * nums[i+1]; // nums[i+1] because ith element isn't included
        } 

        for(int i = 0; i < nums.size(); i++) {
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }
};