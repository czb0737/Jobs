import java.util.*;

class Entry {
	int num, index;
	Entry (int num, int index) {
		this.num = num;
		this.index = index;
	}
}

public class MaxArray {
	public static int[] maxArray(int[] A, int k) {
		Deque<Entry> dq = new LinkedList<>();
		int[] result = new int[A.length];
		for (int i = A.length - 1; i >= 0; i--) {
			while (!dq.isEmpty() && dq.peekFirst().index - k >= i) {
				dq.pollFirst();
			}
			while (!dq.isEmpty() && dq.peekLast().num <= A[i]) {
				dq.pollLast();
			}
			dq.offer(new Entry(A[i], i));
			result[i] = dq.peekFirst().num;
		}
		return result;
	}
	public static void main(String[] args) {
//		int[] A = {1, 3, 5, 7, 3, 4, 2, 9};
		int[] A = {1,2,3,3,6};
		System.out.println(Arrays.toString(maxArray(A, 3)));
	}
}