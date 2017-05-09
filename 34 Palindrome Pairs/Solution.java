import java.util.*;

/*
这个题目 我没刷过 我一开始想的是暴利解法  O（n^2 ＊ l） （l是string的平均长度）
后来面试官提醒我要可以看str1 的首字母是不是等于str2的尾字母 然后我用hashmap根据所有string的尾char进行了分类 然后第二次遍历只遍历map[s[0]] 虽然是现实出来了 但是后来看了leetcode的讨论，竟然发现还有O(nl)这种吊炸天的算法 已哭瞎
。。。后来面试就结束了 。。。。感觉已经跪了 
http://www.1point3acres.com/bbs/thread-202703-1-1.html

test cases:
words = ["bat", "tab", "cat"]
[[0, 1], [1, 0]]
words = ["abcd", "dcba", "lls", "s", "sssll"]
[[0, 1], [1, 0], [3, 2], [2, 4]]
words = ["a", ""]
[[1, 0], [0, 1]]

Time complexity:
O(n * l^2)
*/

public class Solution {
	public static List<List<Integer>> palindromePairs(String[] words) {
		// hashmap : word, index
		// sort words by length decreasingly 
		// traverse words, 
		// sssll: prefix reverse -> find word append, vareify palindrome
		// suffix reverse-> find word and varify palindrome
		// remove curr word from map
		List<List<Integer>> result = new ArrayList<>();
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < words.length; i++) {
			map.put(words[i], i);
		}
//		Arrays.sort(words, new Comparator<String>(){
//			@Override
//			public int compare(String s1, String s2) {
//				return s2.length() - s1.length();
//			}
//		});
		for (String word : words) {
			int i = map.get(word);
//			map.remove(word);
			StringBuilder sb = new StringBuilder(word);
			sb = sb.reverse();
			for (int len = 0; len <= word.length(); len++) {
				// prefix
				String prefix = sb.substring(0, len);
				if (map.containsKey(prefix) && map.get(prefix) != i) {
					if (isPalindrome(prefix + word)) {
						List<Integer> list = new ArrayList<>();
						list.add(map.get(prefix));
						list.add(i);
						result.add(list);
					}
				}
				// suffix
				String suffix = sb.substring(len);
				if (map.containsKey(suffix) && len != 0) {
					if (isPalindrome(word + suffix)) {
						List<Integer> list = new ArrayList<>();
						list.add(i);
						list.add(map.get(suffix));
						result.add(list);
					}
				}
			}
		}
		return result;
	}
	private static boolean isPalindrome(String s) {
		int i = 0, j = s.length() - 1;
		while (i < j) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	public static void main(String[] args) {
		String[] words = {"abcd", "dcba", "lls", "s", "sssll"};
//		String[] words = {"a", ""};
		System.out.println(palindromePairs(words));
	}
}