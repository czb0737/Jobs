import java.util.*;
/*
input: int[] arr, int k 
output: boolean
给一个 int 矩阵，一个数 k。判断这个矩阵里的数是否能组成长度不低于 k 的连续数字串。要求时间复杂度 O(n)，n 是矩阵长度。
*/

public class LongestConsecutiveSequence {
	public static boolean longestConsecutive(int[] nums, int k) {
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			if (!map.containsKey(nums[i])) {
				int left = map.containsKey(nums[i] - 1) ? map.get(nums[i] - 1) : 0;
				int right = map.containsKey(nums[i] + 1) ? map.get(nums[i] + 1) : 0;
				int len = left + 1 + right;
				if (len >= k) {
					return true;
				}
				map.put(nums[i], 0);
				map.put(nums[i] - left, len);
				map.put(nums[i] + right, len);
			}
		}
		return false;
	}
	public static void main(String[] args) {
		int[] nums = {100, 4, 200, 1, 3, 2};
		System.out.println(longestConsecutive(nums, 4));
	}
}