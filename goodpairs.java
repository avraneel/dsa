// Link: https://leetcode.com/problems/number-of-good-pairs/description/

// Given an array of integers nums, return the number of good pairs. A pair (i, j) is called good if nums[i] == nums[j] and i < j.

// Approach: I basically take each i and iterate through the corresponding elements through each i

class goodpairs {
    public int numIdenticalPairs(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
}