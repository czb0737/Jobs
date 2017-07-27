import java.util.*;

public class MultiplyString {
	public static String multiply(String num1, String num2) {
		int n = num1.length() , m = num2.length();
		int[] result = new int[n + m - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				result[i + j] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
			}
		}
		int carry = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = n + m - 2; i >= 0; i--) {
			int curr = carry + result[i];
			carry = curr / 10;
			sb.append(curr % 10);
		}
		if (carry != 0) {
			sb.append(carry);
		}
		if (sb.charAt(sb.length() - 1) == '0') {
			return "0";
		}
		return sb.reverse().toString();
	}
	public static void main(String[] args) {
		String num1 = "100", num2 = "0";
		System.out.println(multiply(num1, num2));
	}
}