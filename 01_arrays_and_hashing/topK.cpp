/*
Link: https://leetcode.com/problems/top-k-frequent-elements/

Approach

First off, create a hash map with key is the number and value is it's count in the array.

Now comes the tricky part. You need a second array of vectors with the size of nums array (guess why). 
In this array, the index is the frequency and at that index, we put a list of all numbers which have that frequency. 

Example:
[4, 5, 4, 7, 3, 2, 1, 7, 5, 4,]

now the array will be:
[null, [1,3,2], [5,7], [4], null, null, null, null, null, null]

As you can see, index 1 has elements that occur only once, and index 3 has 4 which occurs thrice.
This was the tricky part.

Now we loop through this array of vectors *backwards* and store the list elements in our answer list (we skip empty indices here). Once we come across k non empty elements, our job is done and we can return the result.

This logic solves it in O(n) time.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> freq[nums.size()+1];
        vector<int> ans;
        // Create HT where key is number and val is frequency in array
        for(auto item:nums) {
            count[item]++;
        }

        // create an array of vectors where index of array is count
        // of that element
        for(auto item:count) {
            freq[item.second].push_back(item.first);
        }

        for(int i = nums.size(); i <= 0; i--) {
            if(!freq[i].empty()) {
                for (auto item:freq[i]) {
                    ans.push_back(item);
                    if(ans.size() == k) {
                        return ans;
                    }
                }
            }
        }

    }
};