import java.util.*;

// Think like subset 1, at each index we can choose ( or )

class generateparantheses {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        List<String> tmp = new ArrayList<>();
        solve(ans, 0, tmp, n);
        return ans;
    }

    void solve(List<String> ans, int depth, List<String> tmp, int n) {
        if(depth < 0) return;
        if(tmp.size() == n*2) {
            if(depth == 0)
                ans.add(String.join("", tmp));
            return;
        }
        tmp.add("(");
        System.out.println(depth);
        solve(ans,depth+1,tmp,n);
        tmp.remove(tmp.size()-1);
        System.out.println(depth);
        tmp.add(")");
        solve(ans,depth-1,tmp,n);
        tmp.remove(tmp.size()-1);

    }
}