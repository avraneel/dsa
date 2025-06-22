#include <bits/stdc++.h>
using namespace std;

/*
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

Approach:
- Use monotonic increasing stack to store the index of a height.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> stack;
        stack.push_back(0);
        int maxArea = 0;

        for(int i = 1; i <= heights.size(); i++) {
            int ch = (i == heights.size()) ? 0 : heights[i];
            while(!stack.empty() && ch < heights[stack.back()]) {
                int h = heights[stack.back()];
                stack.pop_back();
                int w = stack.empty() ? i : i - stack.back() - 1;
                maxArea = max(maxArea, h * w);
            }
            stack.push_back(i);
        }

       return maxArea; 
    }
};