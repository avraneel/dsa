// Link: https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxleft = height[left];
    int maxright = height[right];
    int water = 0;

    while (left < right)
    {
        if (maxleft <= maxright)
        {
            left++;
            maxleft = max(maxleft, height[left]);
            // Water at position i is min(maximum left height, maximum right height). But as we are in,
            // maxleft <= maxright we dc about right height is left is the bottle next
            water += maxleft - height[left];
        }
        else
        {
            right--;
            maxright = max(maxright, height[right]);
            // Water at position i is min(maximum left height, maximum right height). But as we are in,
            // maxleft > maxright we dc about left height is right is the bottle next
            water += maxright - height[right];
        }
    }
    return water;
}

int main()
{
    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    cout << trap(h1);
    cout << trap(h2);
}