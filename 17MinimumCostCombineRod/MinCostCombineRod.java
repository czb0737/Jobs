import java.util.*;

public class MinCostCombineRod {
	public static int minCostCombineRod(int[] rods) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i = 0; i < rods.length; i++) {
			pq.offer(rods[i]);
		}
		int total = 0;
		while (pq.size() > 1) {
			int sum = pq.poll() + pq.poll();
			total += sum;
			pq.offer(sum);
		}
		return total;
	}
	public static void main(String[] args) {
		int[] rods = {5,2,3,1,4};
		System.out.println(minCostCombineRod(rods));
	}
}