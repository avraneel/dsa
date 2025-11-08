#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {

    int l = 0;
    int r = height.size() - 1;
    int maxArea = 0;

    while (l < r) {

        int area = min(height[l], height[r]) * (r - l);

        if(area > maxArea) {
            maxArea = area;
        }

        if(height[l] < height[r]) {
            l++;
        }
        else if(height[r] < height[l]) {
            r--;
        }
    }
    
    return maxArea;

}