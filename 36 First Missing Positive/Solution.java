public class Solution {
	public int firstMissingPositive(int[] nums) {
		// nums[index] = index + 1
		// index = num - 1
		int n = nums.length;
		for (int i = 0; i < n; i++) {
			int index = nums[i] - 1;
			while (nums[i] >= 1 && nums[i] <= n && index + 1 != nums[index]) {
				swap(i, index, nums);
				index = nums[i] - 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i + 1 != nums[i]) {
				return i + 1;
			}
		}
		return n + 1;
	}
	private void swap(int i, int j, int[] nums) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}