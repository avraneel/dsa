/*
Link: https://leetcode.com/problems/3sum/

1. Sort the list 
2. Traverse through each element
3. For each element, use the TwoSum2 approach of find the remaining pair
4. Traverse through the next element and repeat
5. Skip duplicate values of i, l and r
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            /* Skipping duplicate i */
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    vector<int> sol = {nums[i], nums[l], nums[r]};
                    res.push_back(sol);
                    l++;
                    r--;

                    /* Skipping duplicates, V.V.V.I.P!!! */
                    while(nums[l] == nums[l-1] && l < r) l++;
                    while(nums[r] == nums[r+1] && l < r) r--;
                } 
                else if (sum < 0) l++;
                else r--;
            }
        }

        return res;
    }
};