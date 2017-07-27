import java.util.*;

public class GetOrderOfChar {
	// abb, cabd
	// 
	public static String getOrderOfChar(String[] strs) {
		Map<Character, List<Character>> map = new HashMap<>();
		Map<Character, Integer> indegrees = new HashMap<>();
		for (String str : strs) {
			for (int i = 0; i < str.length() - 1; i++) {
				char prev = str.charAt(i), next = str.charAt(i + 1);
				if (prev == next) {
					continue;	
				}
				if (!map.containsKey(prev)) {
					map.put(prev, new ArrayList<Character>());
				}
				map.get(prev).add(next);
				if (!indegrees.containsKey(next)) {
					indegrees.put(next, 0);
				}
				indegrees.put(next, indegrees.get(next) + 1);
			}
		}
		Queue<Character> q = new LinkedList<>();
		StringBuilder sb = new StringBuilder();
		for (char c : map.keySet()) {
			if (!indegrees.containsKey(c)) {
				q.offer(c);
			}
		}
		while (!q.isEmpty()) {
			char curr = q.poll();
			sb.append(curr);
			if (!map.containsKey(curr)) {
				continue;
			}
			List<Character> list = map.get(curr);
			for (char c : list) {
				indegrees.put(c, indegrees.get(c) - 1);
				if (indegrees.get(c) == 0) {
					q.offer(c);
				}
			}
		}
		return sb.toString();
	}
	public static void main(String[] args) {
//		String[] strs = {"cba", "bd", "ce", "ed"};
//		String[] strs = {"gcd", "jd", "fcj"};
		String[] strs = {"abb", "cabd", "bg"};
		System.out.println(getOrderOfChar(strs));
	}
}