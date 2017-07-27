public class FindLeavesofBinaryTree {
	public List<List<Integer>> findLeaves(TreeNode root) {
		List<List<Integer>> result = new ArrayList<>();
		height(root, result);
		return result;
	}
	
	private int height(TreeNode root, List<List<Integer>> result) {
		if (root == null) {
			return -1;
		}
		int level = Math.max(height(root.left, result), height(root.right, result)) + 1;
		if (result.size() - 1 < level) {
			result.add(new ArrayList<>());
		}
		result.get(level).add(root.val);
		return level;
	}
}