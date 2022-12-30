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
        if(nums[ind] <= target) {       // To make sure target isn't negative
            al.add(nums[ind]);
            solve(ans, al, nums, ind, target - nums[ind]);    // Taken
            al.remove(al.size() - 1);
        }
        solve(ans, al, nums, ind+1, target);    // Not taken
    }
}
