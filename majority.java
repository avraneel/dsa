// Link: https://leetcode.com/problems/majority-element/description/ 
// Use Boyer Moore Voting Algorithm
// Visualise the algorithm here: https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html

public class majority {
    public int majorityElement(int[] nums) {
        int c = 0;  // count
        int cur = nums[0];

        for(int i = 0; i < nums.length; i++) {
            
            // if count == 0, then current element will be the one in the current index
            //                and set count to 1
            if(c == 0) {
                cur = nums[i];
                c = 1;
            }
            else {
                // else, inc. or dec. count by checking if the current element is equal to nums[i]
                if(nums[i] == cur)
                    c++;
                else
                    c--;
            }
        }
        // final element is our answer
        return cur;
    }
}
