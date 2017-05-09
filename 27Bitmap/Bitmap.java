import java.util.*;

public class Bitmap {
	/*第三轮问了一个bitmap，如何用4k的空间记录100k的int，用每一个int来表示32个int就好了*/
	
	public static List<Integer> findDuplicate(int[] nums) {
		byte[] bitmap = new byte[4000];
		List<Integer> result = new ArrayList<>();
		for (int i = 0; i < nums.length; i++) {
			int index = nums[i] /8;
			byte bit = (byte) (nums[i] % 8);
			if ((bitmap[index] & (1 << bit)) != 0) {
				result.add(nums[i]);
			}
			bitmap[index] |= (1 << bit);
		}
		return result;
	}
	
	public static List<Integer> findDuplicate1(int[] nums) {
		int[] bitmap = new int[1000];
		List<Integer> result = new ArrayList<>();
		for (int i = 0; i < nums.length; i++) {
			int index = nums[i] / 32;
			int bit = nums[i] % 32;
			if ((bitmap[index] & (1 << bit)) != 0) {
				result.add(nums[i]);
			}
			bitmap[index] |= (1 << bit);
		}
		return result;
	}
	
	
	public static void main(String[] args) {
		int[] nums = {1,9,4,2000,25000,6,2000,9};
		System.out.println(findDuplicate1(nums));
	}
}