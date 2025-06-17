#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        vector<pair<int,int>> monotonic_stack;
        for(int i = 0; i < temperatures.size(); i++) {
            while (!monotonic_stack.empty() && temperatures[i] > monotonic_stack.back().first) {
                pair<int,int> top = monotonic_stack.back();
                monotonic_stack.pop_back();
                ans[top.second] = i - top.second;
            }
            pair<int,int> item = {temperatures[i], i};
            monotonic_stack.push_back(item);
        }
        return ans;
    }
};