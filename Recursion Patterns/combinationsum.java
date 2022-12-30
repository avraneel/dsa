import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> al = new ArrayList<>();

        solve(ans, al, candidates, 0, target);
        return ans;
    }

    void solve(List<List<Integer>> ans, List<Integer> al, int[] nums, int ind, int target) {
        // Same structure as power set recursion
        if(ind >= nums.length) {
            if(target == 0) {
                ans.add(new ArrayList<>(al));
            }
            return;
        }
        if(nums[ind] <= target) {  
        
        // Element can only be picked if the resultant target - nums[i]
        // is >= 0
            
        // To make sure target isn't negative
        // If condition is satisfied then we:
        // 1. pick the element and add it to our bucket
        // 2. subtract the element from the target 
        // 3. After element is picked so many times that sum of all of them exceeds
        // target, we remove it
            al.add(nums[ind]);
            solve(ans, al, nums, ind, target - nums[ind]);    // Taken
            al.remove(al.size() - 1);
        }
        // This is outside the bracket because we haven't changed target 
        // and 
        solve(ans, al, nums, ind+1, target);    // Not taken
    }
}
