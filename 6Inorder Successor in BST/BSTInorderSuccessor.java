import java.util.*;

class TreeNode {
	TreeNode left, right, parent;
	int val;
	TreeNode (int val) {
		this.val = val;
	}
}

public class BSTInorderSuccessor {
	/*
	第二问就是经典的给一个BST，给一个节点，找出比这个节点数字小的最大值得节点
	*/
	public TreeNode findMaxSmaller(TreeNode root, TreeNode p) {
		TreeNode curr = root, candidate = null;
		while (curr != null) {
			if (curr.val >= p.val) {
				curr = curr.left;
			} else {
				candidate = curr;
				curr = curr.right;
			}
		}
		return candidate;
	}
	
	//method1: iterative inorder traverse
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		Stack<TreeNode> stack = new Stack<>();
		TreeNode curr = root;
		while (curr != null || !stack.isEmpty()) {
			if (curr != null) {
				stack.push(curr);
				curr = curr.left;
			} else {
				curr = stack.pop();
				if (curr.val > p.val) {
					return curr;
				}
				curr = curr.right;
			}
		}
		return null;
	}
	
	// method2: 
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		TreeNode candidate = null, curr = root;
		while (curr != null) {
			if (curr.val <= p.val) {
				curr = curr.right;
			} else if (curr.val > p.val) {
				candidate = curr;
				curr = curr.left;
			} 
		}
		return candidate;
	}
	// method3:
	public TreeNode inorderSuccessor(TreeNode p) {
		if (p.right != null) {
			TreeNode curr = p.right;
			while (curr.left != null) {
				curr = curr.left;
			}
			return curr;
		}
		TreeNode parent = p.parent;
		while (parent != null) {
			if (parent.val < p.val) {
				parent = parent.parent;
			} else {
				break;
			}
		}
		return parent;
	}
	
	/*if we are not allowed to compare the value of two nodes*/
	
	public TreeNode inorderSuccessor(TreeNode p) {
		if (p.right != null) {
			TreeNode curr = p.right;
			while (curr.left != null) {
				curr = curr.left;
			}
			return curr;
		}
		TreeNode parent = p.parent, curr = p;
		while (parent != null && parent.right == curr) {
			curr = parent;
			parent = parent.parent;
		}
		return parent;
	}
	
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		Stack<TreeNode> stack = new Stack<>();
		TreeNode curr = root;
		boolean findP = false;
		while (curr != null || !stack.isEmpty()) {
			if (curr != null) {
				stack.push(curr);
				curr = curr.left;
			} else {
				curr = stack.pop();
				if (findP) {
					return curr;
				}
				if (curr == p) {
					findP = true;
				}
				curr = curr.right;
			}
		}
		return null;
	}
	
	public static void main(String[] args) {
		
	}
}