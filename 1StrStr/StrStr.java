import java.util.*;

public class StrStr {
	public static int strStr(String haystack, String needle) {
		if (haystack == null || needle == null) {
			return -1;
		}
		if (haystack.length() < needle.length()) {
			return -1;
		}
		for (int i = 0; i <= haystack.length() - needle.length(); i++) {
			if (haystack.substring(i, i + needle.length()).equals(needle)) {
				return i;
			}
		}
		return -1;
	}
	
	public static int strStr1(String haystack, String needle) {
		int n = haystack.length(), m = needle.length();
		int[] key = new int[m]; 
		// key: contains the length of the prefix that is equal to the suffix, (actuall means the position of the element in the array that want to use to compare with the current element)
		//e.g.:abcabcx
		//     0001230
		//	   abcabcdef
		// the 3 for c means abc prefix is the same with suffix abc, and if x is not the same with the element in haystack. we will compare the elemnt in haystack with the element in needle with index 3, which is a
		for(int i = 1;i < m;i++) {
			int j = key[i-1];
			while(j != 0 && needle.charAt(j) != needle.charAt(i)) {
				j = key[j-1];
			}
			key[i] = j + (needle.charAt(j) == needle.charAt(i)?1:0);
		}
		int i = 0, j = 0;
		while(i < n && j < m) {
			if(j > 0 && haystack.charAt(i) != needle.charAt(j)) {
				j = key[j-1];
			} else {
				j += (haystack.charAt(i) == needle.charAt(j)?1:0);
				i++;
			}
		}
		return j == m?i-j:-1;
	}
	public static void main(String[] args) {
		System.out.println(strStr("abcdbcd","bcd"));
	}
}