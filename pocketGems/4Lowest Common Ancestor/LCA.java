import java.util.*;

class TreeNode {
	TreeNode left, right;
	int val;
	TreeNode (int val) {
		this.val = val;
	}
}

public class LCA {
	public static TreeNode lowestCommonAncestor (TreeNode root, TreeNode p, TreeNode q) {
		if (root == null || root == p || root == q) {
			return root;
		}
		TreeNode leftR = lowestCommonAncestor(root.left, p, q);
		TreeNode rightR = lowestCommonAncestor(root.right, p, q);
		if (leftR != null && rightR != null) {
			return root;
		}
		if (leftR == null && rightR == null) {
			return null;
		}
		return leftR == null ? rightR : leftR;
	}
	public static TreeNode lowestCommonAncestorBST (TreeNode root, TreeNode p, TreeNode q) { 
		if ((root.val - p.val) * (root.val - q.val) <= 0) {
			return root;
		}
		return p.val > root.val ? lowestCommonAncestorBST(root.right, p, q) : lowestCommonAncestorBST(root.left, p, q);
	}
	
	public static void main(String[] args) {
		
	}
}