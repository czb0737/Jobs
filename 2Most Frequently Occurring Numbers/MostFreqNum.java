import java.util.*;

/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=145889&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311


http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=207725&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

 top K frequent numbers 问了三种方法，bucket sort, min_heap, max_heap 以及min_heap  和max_heap的对比，二者在什么情况下用哪个？
*/



class Entry {
	int num;
	int freq;
	Entry (int num, int freq) {
		this.num = num;
		this.freq = freq;
	}
	public String toString() {
		return "[" + num + ", " + freq + "]";
	}
}

public class MostFreqNum {
	public static List<Integer> mostFreqNum22(int[] nums, int k) {
		List<Integer> result = new ArrayList<>();
		Map<Integer, Integer> counter = new HashMap<>();
		for (int num : nums) {
			if (!counter.containsKey(num)) {
				counter.put(num, 0);
			}
			counter.put(num, counter.get(num) + 1);
		}
		int max = 0;
		for (int num : counter.keySet()) {
			max = Math.max(max, counter.get(num));
		}
		List<List<Integer>> bucket = new ArrayList<>(max);
		for (int i = 0; i < max; i++) {
			bucket.add(new ArrayList<Integer>());
		}
		for (int num : counter.keySet()) {
			bucket.get(counter.get(num) - 1).add(num);
		}
		for (int i = max - 1; i >= 0; i--) {
			if (bucket.get(i) == null) {
				continue;
			}
			for (int num : bucket.get(i)) {
				result.add(num);
				if (result.size() == k) {
					return result;
				}
			}
		}
		return result;
	}
	
	public static List<Integer> mostFreqNum(int[] nums, int k) {
		if (nums == null) {
			return null;
		}
		Map<Integer, Integer> counter = new HashMap<>();
		for (int num : nums) {
			if (!counter.containsKey(num)) {
				counter.put(num, 0);
			}
			counter.put(num, counter.get(num) + 1);
		}
		List<Entry> list = new ArrayList<>();
		for (int key : counter.keySet()) {
			list.add(new Entry(key, counter.get(key)));
			System.out.println(key+ ": " + counter.get(key));
		}
		return getFirstKFreqNum(list, k);
	}
	
	private static List<Integer> getFirstKFreqNum(List<Entry> list, int k) {
		List<Integer> result = new ArrayList<>();
		
		//first method
//		Collections.sort(list, new Comparator<Entry>(){
//			public int compare(Entry e1, Entry e2) {
//				return e2.freq - e1.freq;
//			}
//		});

		//seoncd method
//		int start = 0, end = list.size() - 1;
//		while (start < end) {
//			int part = partition(list, start, end);
//			if (part == k) {
//				break;
//			} else if (part < k) {
//				start = part + 1;
//			} else {
//				end = part - 1;
//			}
//		}
//		System.out.println(list);
		
		
		// for 1 and 2 method
//		for (int i = 0; i < k && i < list.size(); i++) {
//			result.add(list.get(i).num);
//		}
		
		// third method
		PriorityQueue<Entry> pq = new PriorityQueue<>(100, new Comparator<Entry>() {
			public int compare(Entry e1, Entry e2) {
				return e1.freq - e2.freq;
			}
		});
		for (Entry entry : list) {
			pq.offer(entry);
			if (pq.size() > k) {
				pq.poll();
			}
		}
		
		while (!pq.isEmpty()) {
			result.add(pq.poll().num);
		}
		
		return result;
	}
	
	private static int partition(List<Entry> list, int start, int end) {
		int pivot = list.get(start).freq;
		int i = start + 1, j = end;
		while (i <= j) {
			while (i <= j && list.get(i).freq >= pivot) {
				i++;
			}
			while (i <= j && list.get(j).freq <= pivot) {
				j--;
			}
			if (i <= j) {
				swap(list, i, j);
			}
		}
		swap(list, start, j);
		return j;
	}
	
	private static void swap(List<Entry> list, int i, int j) {
		Entry temp = list.get(i);
		list.set(i, list.get(j));
		list.set(j, temp);
	}
	public static void main(String[] args) {
		int[] nums = {3,2,1,2,3,6,7,2,9,7,9,9,9,6	,5};
		System.out.println(mostFreqNum22(nums, 3));
	}
}