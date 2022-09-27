// Program to remove duplicates from sorted array

class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int r = n-1;
        int l = 0;
        while(l < r) {
            if(nums[l+1] != nums[l])
                l++;
            else 
            {
                if(l+1 < r) 
                 {
                    for(int j = l+2; j <= r; j++)
                    {
                        nums[j-1] = nums[j];
                    }
                 }
                r--;
            }
        }
        return r+1;
    }
}
