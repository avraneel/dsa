import java.util.*;

// Binary tree level order traversal

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> result = new ArrayList<>();
        q.offer(root);
        if(root == null) return result;
        while(!q.isEmpty()) {
            int s = q.size();
            System.out.println(s);
            List<Integer> sub = new ArrayList<>();
            for(int i=0; i<s; i++) {
                if(q.peek().left != null) 
                    q.offer(q.peek().left);
                if(q.peek().right != null)
                    q.offer(q.peek().right);
                sub.add(q.poll().val);
            }
            result.add(sub);     
        }
        return result;
    }
}
