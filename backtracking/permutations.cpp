#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, unordered_set<int>& used) {

    // Debugging statements, uncomment to see the tree
    // for(auto i : cur) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // base case - all the items of nums are taken
    if(cur.size() == nums.size()) {
        res.push_back(cur);
    }

    for(int i = 0; i < nums.size(); i++) {

        // If nums[i] is not present in used
        if(!used.count(nums[i])) {

            cur.push_back(nums[i]);
            used.insert(nums[i]);

            backtrack(nums, cur, res, used);

            // These statements will be executed AFTER base case is reached
            cur.pop_back();
            used.erase(nums[i]);
        }
    }
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res;
    vector<int> cur;
    unordered_set<int> used;

    backtrack(nums, cur, res, used);

    for(auto i : res) {
        cout << "[ ";
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "]\n";
    }
}