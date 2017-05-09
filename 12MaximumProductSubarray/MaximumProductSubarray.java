import java.util.*;

public class MaximumProductSubarray {
	// 1. there is no 0, 
	// 1.1 all positive, the largest would be the produt of all the numbers
	// 2, 3, 5 ,7
	// 1.2 if current is positive, next largest is previous positive product times current num, otherwise if current is negative, next largest is the previous negative product times current num
	
	// 2 , -3, 5, -7, 6, -8
	
	// 2   -6, -30, -35, -210, 
	
	// 2   -3, 5, 210, 1260,
	
	// 2. if there is a 0
	// small = largest = 0
	public static int maximumProduct(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		int min = nums[0], max = nums[0];
		int maxGlobal = max;
		for (int i = 1; i < nums.length; i++) {
			int temp = min;
			min = Math.min(Math.min(min * nums[i], max * nums[i]), nums[i]);
			max = Math.max(Math.max(temp * nums[i], max * nums[i]), nums[i]);
			maxGlobal = Math.max(maxGlobal, max)
		}
		return max;
	}
	public static void main(String[] args) {
//		int[] nums = {2 , -3, 5, 0, -7, 6, -8};
		int[] nums = {-4,-3,-2};
		System.out.println(maximumProduct(nums));
	}
}