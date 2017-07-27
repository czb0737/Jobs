import java.util.*;

/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210629&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
*/

class TreeNode {
	TreeNode left, right, parent;
	int val;
	TreeNode (int val) {
		this.val = val;
	}
}

public class Solution {
	
	//  2
	// 1  4
	//	 3 5
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		//1. if right substree of p is not empty, find the smallest node in right substree
		//2. find the closest ancestor whose left substree contains p
		if (p == null || root == null) {
			return null;
		}
		// p.val < root.val, root can be candidate, p.val > root.val root cannot be candidate
		//O(h)
		TreeNode candidate = null, curr = root;
		while (curr != null) {
			if (p.val < curr.val) {
				candidate = curr;
				curr = curr.left;
			} else {
				curr = curr.right;
			}
		}
		return candidate;
	}
	
	
	// if we are not allowed to compare the value of the node
	//O(n)
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		TreeNode curr = root;
		Stack<TreeNode> stack = new Stack<>();
		boolean find = false;
		while (curr != null || !stack.isEmpty()) {
			if (curr != null) {
				stack.push(curr);
				curr = curr.left;
			} else { 
				curr = stack.pop();
				if (curr == p) {
					find = true;
				} else if (find) {
					return curr;
				}
				curr = curr.right;
			}
		}
		return null;
	}
	// O(h)
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		if (p.right != null) {
			TreeNoe curr = p.right;
			while (curr.left != null) {
				curr = curr.left;
			}
			return curr;
		}
		TreeNode curr = p, parent = curr.parent;
		while (parent != null && parent.right == curr) {
			curr = parent;
			parent = curr.parent;
		}
		return parent;
	}
	public static void main(String[] args) {
		
	}
}