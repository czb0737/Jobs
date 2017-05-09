import java.util.*;

class Entry {
	int num;
	int index;
	Entry (int num, int index) {
		this.num = num;
		this.index = index;
	}
}

public class SlidingWindow {
	public static List<Integer> slidingWindow(int[] nums, int k) {
		List<Integer> result = new ArrayList<>();
		Deque<Entry> dq = new LinkedList<>();
		for (int i = 0; i < k; i++) {
			while (!dq.isEmpty() && dq.peekLast().num >= nums[i]) {
				dq.pollLast();
			}
			dq.offer(new Entry(nums[i], i));
		}
		result.add(dq.peekFirst().num);
		for (int i = k; i < nums.length; i++) {
			if (!dq.isEmpty() && dq.peekFirst().index + k <= i) {
				dq.pollFirst();
			}
			while (!dq.isEmpty() && dq.peekLast().num >= nums[i]) {
				dq.pollLast();
			}
			dq.offer(new Entry(nums[i], i));
			result.add(dq.peekFirst().num);
		}
		return result;
	}
	public static void main(String[] args) {
		int[] nums = {1,2,5,10,3,4};
		System.out.println(slidingWindow(nums, 3));
	}
}