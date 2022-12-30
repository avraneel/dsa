import java.util.*;;

// Watch Striver video: https://www.youtube.com/watch?v=AxNNVECce8c

// Given an array print all possible subsets/subsequences (same ans for both)

class PowerSetRecursion {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> al = new ArrayList<>();
        all_subsequences(ans, al, nums, 0);
        return ans;
    }

    void all_subsequences(List<List<Integer>> ans, List<Integer> al, int nums[], int ind) {
        if(ind >= nums.length) {

            // new ArrayList<>(al) is used to create a NEW memory location and copy the values of al to it.
            // if we used only used ans.add(al) --> WRONG, as ans[i] and al will point to the same memory location 
            // which is constantly changing as recursion happens
            ans.add(new ArrayList<>(al));
            return;
        }
        
        // Take the element
        al.add(nums[ind]); 
        all_subsequences(ans, al, nums, ind+1);
        
        // Not take the element by removing the recently added element which will be at the last
        al.remove(al.size()-1);
        all_subsequences(ans, al, nums, ind+1);
    }
}