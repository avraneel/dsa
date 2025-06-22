#include <bits/stdc++.h>
using namespace std;

/* 
Link: https://leetcode.com/problems/car-fleet/

Approach:
    let us have:
        pos     = [10,  8,  0,  5,  3]
        speed   = [2,   4,  1,  1,  3]

        now if we take a list of pairs of (pos, speed) and plot them on the line:

        ---------------------------------------------
        (0,0)   (3,3)   (5,1)   (8,4)   (10,2)      (target=12)


    When will 2 cars meet? 
    When the car behind reaches target faster than the car in front, they will be a car fleet.
    So,
    (10,2) car will reach at 1s. 
    (8,4)  car will reach at 1s.
    (5,1)  car will reach at 7s.
    (3,3)  car will reach at 3s.
    (0,1)  car will reach at 12s.

    So we take a variable for the slowest time starting from reverse sorted order of pos, and we
    see if the time taken for each car behind is lesser or greater than the current slowest time.

    If time taken is more than the car in front, it will never meet and so it will be its own
    fleet. So, increase counter of fleet by 1.

    IF time taken is less, then they will meet and join to become the same fleet. So, no
    need to update counter as no new fleet is formed.

    std::map<,,greater<int>> stores the keys in reverse sorted order.
    also be careful as time can be in double too.

*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        /* We put an array of <pos,speed> values sorted by pos, so we use
           the map which stores by sorted key order.
           Note: this is not unordered_map which does not store by any
           order */
        map<int, int, greater<int>> cars;
        for(int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i]; 
        }

        double slowestTime = 0.0;

        // Number of car fleets
        int counter = 0;

        for(auto& item : cars) {
            double time = double(target - item.first) / item.second;
            if(time > slowestTime) {
                slowestTime = time;
                counter++;
            }
        }
        return counter;
    }
};