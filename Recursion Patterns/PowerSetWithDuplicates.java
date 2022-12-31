import java.util.*;

class PowerSetWithDuplicates {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> al = new ArrayList<>();

        // SORTING IMPORTANT FOR DUPLICATE
        // Array contains duplicate, so 
        // in order to do our logic, we need to sort
        Arrays.sort(nums);

        solve(ans, al, nums, 0);

        return ans;
    }

    void solve(List<List<Integer>> ans, List<Integer> al, int[] nums, int ind) {
        // From the recursion tree, we have to capture a subset at every step
        ans.add(new ArrayList<>(al));
        for(int i = ind; i < nums.length; i++) {
            
            // Checking for duplicate
            if(i > ind && nums[i] == nums[i-1]) continue;

            // Picking ith element
            al.add(nums[i]);
            solve(ans, al, nums, i+1);
            al.remove(al.size()-1);
        }
    }
}
