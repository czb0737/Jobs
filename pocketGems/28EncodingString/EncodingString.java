import java.util.*;

public class EncodingString {
	public static String encode(String s) {
		if (s == null || s.length() == 0) {
			return "";
		}
		StringBuilder sb = new StringBuilder();
		char curr = s.charAt(0);
		int num = 1;
		for (int i = 1; i <= s.length(); i++) {
			if (i == s.length() || s.charAt(i) != curr) {
				sb.append(num).append(curr);
				curr = i == s.length() ? ' ' : s.charAt(i);
				num = 1;
			} else {
				num++;
			}
		}
		return sb.toString();
	}
	
	public static void encode (char[] arr) {
		char curr = arr[0];
		int num = 1, j = 0;
		for (int i = 1; i <= arr.length; i++) {
			
			if (i == arr.length || arr[i] != curr) {
				if (num > 1) {
					arr[j++] = (char)(num + '0');
				}
				arr[j++] = curr;
				curr = i == arr.length ? ' ' : arr[i];
				num = 1;
 			} else {
				num++;
			}  
		}
		while (j < arr.length) {
			arr[j++] = '\0';
		}
	}
	public static void main(String[] args) {
//		String s = "aaacbbcc";
//		System.out.println(encode(s));
		char[] arr = "BCD".toCharArray();
		System.out.println(Arrays.toString(arr));
		encode(arr);
		System.out.println(Arrays.toString(arr));
	}
}