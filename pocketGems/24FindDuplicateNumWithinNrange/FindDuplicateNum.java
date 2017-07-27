import java.util.*;

/*
一组数范围在［0， n] 每个数都存在， 有的数出现一次， 有的数出现两次，输出所有出现两次的数 O(n) time, O(1) space
居然不是top K， 上来有点懵， 稳了一下问他说可不可以改变数组元素的位置， 说可以。 
就尝试扫一遍， 没到array[i] != i 的时候就交换 array[i] 和array[array[i]]
知道相等。 最后所有array[i] != i的数就是重复的数。因为每次交换都会使一个位置出现array[i] ＝= i 的情况， 最多n 次交换 time O(n)
*/

public class FindDuplicateNum {
	public static List<Integer> findDuplicate(int[] nums, int n) {
		//  1, 1, 0
		// 1, 0, 1
		// nums.length > n
		// put i at index i, then from index 0 to n, nums[index] == index, nums[index] where index > n will contain the duplicate number
		// 1. when nums[i] != i && nums[i] != nums[nums[i]]
		// O(n)
		for (int i = 0; i < nums.length; i++) {
			while (nums[i] != i && nums[i] != nums[nums[i]]) {
				swap(i, nums[i], nums);
			}
		}
		List<Integer> result = new ArrayList<>();
		for (int i = n + 1; i < nums.length; i++) {
			result.add(nums[i]);
		}
		return result;
	}
	
	private static void swap(int i , int j, int[] nums) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	
//	public static List<Integer> findDuplicate(int[] nums, int n) {
//		for (int i = 0; i < nums.length; i++) {
//			while (nums[i] != i && nums[nums[i]] != nums[i]) {
//				swap(nums, i, nums[i]);
//			}
//		}
//		List<Integer> result = new ArrayList<>();
//		for (int i = n + 1; i < nums.length; i++) {
//			result.add(nums[i]);
//		}
//		return result;
//	}
//	
//	private static void swap(int[] nums, int i , int j) {
//		int temp = nums[i];
//		nums[i] = nums[j];
//		nums[j] = temp;
//	}
	
	public static void main(String[] args) {
		int[] nums = {1, 3, 3, 4, 0, 2, 1};
		System.out.println(findDuplicate(nums, 4));
		System.out.println(Arrays.toString(nums));
	}
}