import java.util.*;

public class Solution {
	public static int strStr(String haystack, String needle) {
		//abc
		//bc
		// O(mn)
		// needle: aaaaaaaaa
		// haystack: aaaaaabaaaaaaabaaaaaaaaaaaa
		// ab
		// aaaaaaaaab
		for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
			int j;
			for (j = 0; j < needle.length(); j++) {
				if (haystack.charAt(i + j) != needle.charAt(i)) {
					break;
				}
			}
			if (j == needle.length()) {
				return i;
			}
		}
		return -1;
	}
	
	
	public static void main(String[] args) {
		
	}
}