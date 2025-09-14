/*
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;

        while(l < r) {
            int n1 = numbers[l];
            int n2 = numbers[r];
            if(n1+n2 == target) {
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
            else if(n1+n2 < target) {
                l++;
            }
            else {
                r--;
            }
        }
        return res;
    }
};