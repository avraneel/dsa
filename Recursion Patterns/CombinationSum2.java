// View Striver video

// IMP!!! See the recursion tree there

import java.util.*;
class CombinationSum2 {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> al = new ArrayList<>();
        Arrays.sort(candidates);
        solve(ans, al, candidates, target, 0);
        return ans;

    }

    void solve(List<List<Integer>> ans, List<Integer> al, int nums[], int target, int ind) {
        if(target == 0) {
            ans.add(new ArrayList<>(al));
            return;
        }
        for(int i = ind; i < nums.length; i++) {
            // For loop means we are **attempting** to pick from ind to n-1 th index.
            // Each i corresponds to 1 branch of the tree

            // If duplicate then go to next branch
            if(i > ind && nums[i] == nums[i-1]) continue;

            // If target is negative, don't pick and also don't move to other branches
            // as array is sorted. Jump back to previous level.
            if(nums[i] > target) break;

            // Picking
            al.add(nums[i]);
            solve(ans, al, nums, target-nums[i], i+1);
            al.remove(al.size()-1);
        }
    }
}
