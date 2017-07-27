import java.util.*;

/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=199185&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

挺顺利的，准点来电话，一听是烙印马上开始用洪荒之力理解对方意思。上来啥也没问直接开始coding。
比较简单，就是lc28 strstr和lc366 find leaves of binary tree也没有follow up就问了一下时间复杂度。
两题写完都有很小的bug，提示之后马上改过来了，看来还是功底不行啊。
后面就问我有啥问题，然后聊天聊了5、6分钟。整个面试不到30分钟就结束了。
说明天会给回复。上来发个面经赞rp。PS 之前OA还是那两题，但是只给1小时15分钟。
*/

public class Solution {
	public List<List<Integer>> findLeaves(TreeNode root) {
		List<List<Integer>> result = new ArrayList<>();
		getDepth(root, result);
		return result;
	}
	private int getDepth(TreeNode root, List<List<Integer>> result) {
		if (root == null) {
			return -1;
		}
		int depth = Math.max(getDepth(root.left, result), getDepth(root.right, result)) + 1;
		if (result.size() == depth) {
			result.add(new ArrayList<Integer>());
		}
		result.get(depth).add(root.val);
		return depth;
	}
}