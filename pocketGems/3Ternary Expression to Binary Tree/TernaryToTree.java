import java.util.*;

//class TreeNode {
//	String val;
//	TreeNode left, right;
//	TreeNode (String val) {
//		this.val = val;
//	}
//	public String toString() {
//		TreeNode curr = this;
//		String left = curr.left == null ? "" : curr.left.toString();
//		String right = curr.right == null ? "" : curr.right.toString();
//		return  left + " " + curr.val + " " + right;
//		
//	}
//}

class TreeNode {
	char val;
	TreeNode left, right;
	TreeNode (char val) {
		this.val = val;
	}
	public String toString() {
		TreeNode curr = this;
		String left = curr.left == null ? "" : curr.left.toString();
		String right = curr.right == null ? "" : curr.right.toString();
		return left + " " + curr.val + " " + right;
	}
}

public class TernaryToTree {
//	public static TreeNode tenaryExpressionToBinaryTree(String s) {
		//method 1
//		int i = 0;
//		while (i < s.length() && s.charAt(i) != '?') {
//			i++;
//		}
//		TreeNode root = new TreeNode(s.substring(0, i));
//		if (i == s.length()) {
//			return root;
//		}
//		int count = 1, j = i + 1;
//		while (j < s.length()) {
//			if (s.charAt(j) == ':') {
//				count--;
//			}
//			if (s.charAt(j) == '?') {
//				count++;
//			}
//			if (count == 0) {
//				break;
//			}
//			j++;
//		}
//		root.left = tenaryExpressionToBinaryTree(s.substring(i + 1, j));
//		root.right = tenaryExpressionToBinaryTree(s.substring(j + 1));
//		return root;

		//method 2
//		TreeNode root = new TreeNode(s.substring(0, 1));
//		Stack<TreeNode> stack = new Stack<>();//contains the node that does not have its right
//		TreeNode curr = root;
//		for (int i = 1; i < s.length(); i += 2) {
//			if (s.charAt(i) == '?') {
//				curr.left = new TreeNode(s.substring(i + 1, i + 2));
//				stack.push(curr);
//				curr = root.left;
//			} else if (s.charAt(i) == ':') {
//				curr = stack.pop();
//				curr.right = new TreeNode (s.substring(i + 1, i + 2));
//				curr = curr.right;
//			}
//		}
//		return root;
//	}
	
	public static TreeNode convert1(char[] expr) {
		TreeNode root = new TreeNode(expr[0]);
		TreeNode curr = root;
		Stack<TreeNode> stack = new Stack<>();
		for (int i = 1; i < expr.length; i += 2) {
			if (expr[i] == '?') {
				curr.left = new TreeNode(expr[i + 1]);
				stack.push(curr);
				curr = curr.left;
			} else if (expr[i] == ':') {
				parent = stack.pop();
				while (curr.right != null) {
					parent = stack.pop();
				}
				parent.right = new TreeNode(expr[i + 1]);
				stack.add(parent);
				parent = parent.right;r
			}
		}
		return root;
	}
	
	public static TreeNode convert(char[] expr) {
		TreeNode root = new TreeNode(expr[0]);
		TreeNode curr = root;
		Stack<TreeNode> stack = new Stack<>();
		for (int i = 1; i < expr.length; i += 2) {
			if (expr[i] == '?') {
				curr.left = new TreeNode(expr[i + 1]);
				stack.push(curr);
				curr = curr.left;
			} else if (expr[i] == ':') {
				curr = stack.pop();
				curr.right = new TreeNode(expr[i + 1]);
				curr = curr.right;
			}
		}
		return root;
	}
	
	public static void main(String[] args) {
//		TreeNode root = tenaryExpressionToBinaryTree("a?b?c:d:e");
//		TreeNode root = tenaryExpressionToBinaryTree("a?b?c:d?e:f:g?h:i");
		char[] expr = "a?b?c:d?e:f:g?h:i".toCharArray();
		System.out.println(convert(expr));
//		System.out.println(root);
	}
}