// Kadane's algorithm which finds out the maximum contiguous subarray with the largest sum

import java.util.*;

class Solution {
    public int maxSubArray(int[] nums) {
        int maxsum = Integer.MIN_VALUE;
        int cursum = 0;
        for(int i = 0; i < nums.length; i++) {
            cursum += nums[i];
            if(cursum > maxsum) maxsum = cursum;
            if(cursum < 0) cursum = 0;
        }
        return maxsum;
    }
}