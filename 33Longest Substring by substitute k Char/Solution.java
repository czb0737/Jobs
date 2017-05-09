import java.util.*;

/*
新题，一个字符串，比如“AABBABA”，问最多做K次替换，A换B或B换A，相同字母所连最长的长度是多少。

比如最多一次替换，最长长度的结果是“AABBBBA”，长度为四个B所构成的4。

真是迷，虽然写的不顺，聊的顺啊。
*/
public class Solution {
	// substring: 1. max is as high as possible, 2. len - max <= k
	// max: freq of highest freq char (B)
	// len: length of substring 
//	public static int longestSubstringByKSubstitution(String s, int k) {
//		int j = 0, maxLen = 0;
//		int[] counter = new int[26];
//		for (int i = 0; i < s.length(); i++) {
//			counter[s.charAt(i) - 'A']++;
//			int max = getMax(counter);
//			while (i - j + 1 - max > k) {
//				counter[s.charAt(j++) - 'A']--;
//				max = getMax(counter);
//			}
//			maxLen = Math.max(maxLen, i - j + 1);
//		}
//		return maxLen;
//	}
	public static int longestSubstringByKSubstitution(String s, int k) {
		int j = 0, maxCount = 0, maxLen = 0;
		int[] counter = new int[26];
		for (int i = 0; i < s.length(); i++) {
			counter[s.charAt(i) - 'A']++;
			maxCount = Math.max(maxCount, counter[s.charAt(i) - 'A']);
			while (i - j + 1 - maxCount > k) {
				counter[s.charAt(j++) - 'A']--;
			}
			maxLen = Math.max(i - j + 1, maxLen);
		}
		return maxLen;
	}
	
	private static int getMax(int[] counter) {
		int max = 0;
		for (int i = 0; i < counter.length; i++) {
			max = Math.max(max, counter[i]);
		}
		return max;
	}
	public static void main(String[] args) {
		System.out.println(longestSubstringByKSubstitution("AABBABA" ,1));
	}
}