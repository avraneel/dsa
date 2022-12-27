import java.util.*;

// Inorder Traversal of a binary tree

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ord = new ArrayList<>();
        inorder(root, ord);
        return ord;
    }
    
    public void inorder(TreeNode root, List<Integer> ord) {
        if(root == null)
            return;
        inorder(root.left, ord);
        ord.add(root.val);
        inorder(root.right, ord);
    }
}
