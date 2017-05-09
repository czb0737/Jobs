import java.util.*;

public class FirstOccurenceInBST {
	private int firstOccurrenceBinarySearch(int[] A, int target)) {
		if (A == null || A.length == 0) {
			return result;
		}
		int low = 0, high = A.length - 1;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (target <= A[mid]) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
	public static void main(String[] args) {
		
	}
}