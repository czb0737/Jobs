import java.util.*;

public class BigInt {
	private int sign;
	private String num;
	public BigInt(String num) {
		sign = 1;
		if (!Character.isDigit(num.charAt(0))) {
			sign = num.charAt(0) == '-' ? -1 : 1;
			num = num.substring(1);
		}
		this.num = num;
	}
	public BigInt add(BigInt bigInt) {
		if (bigInt.sign * this.sign > 0) {
			String result = add(this.num, bigInt.num);
			if (this.sign == -1) {
				result = "-" + result;
			}
			return new BigInt(result);
		} else {
			if (absCompare(this.num, bigInt.num) >= 0) {
				String result = subtract(this.num, bigInt.num);
				if (this.sign == -1 && !result.equals("0")) {
					result = "-" + result;
				}
				return new BigInt(result);
			} else {
				String result = subtract(bigInt.num, this.num);
				if (bigInt.sign == -1) {
					result = "-" + result;
				}
				return new BigInt(result);
			}
		}
	}
	
	public int absCompare(String s1, String s2) {
		if (s1.length() > s2.length()) {
			return 1;
		} else if (s1.length() < s2.length()) {
			return -1;
		} else {
			return s1.compareTo(s2);
		}
	}
	
	private String add(String s1, String s2) {
		StringBuilder sb = new StringBuilder();
		int i = s1.length() - 1, j = s2.length() - 1;
		int carry = 0;
		while (i >= 0 || j >= 0) {
			int num1 = i >= 0 ? s1.charAt(i--) - '0' : 0;
			int num2 = j >= 0 ? s2.charAt(j--) - '0' : 0;
			int sum = num1 + num2 + carry;
			sb.append(sum % 10);
			carry = sum / 10;
		}
		if (carry != 0) {
			sb.append(carry);
		}
		return sb.reverse().toString();
	}
	private String subtract(String s1, String s2) {
		//1.len, 2.0
		if (s1.equals(s2)) {
			return "0";
		}
		StringBuilder sb = new StringBuilder();
		int i = s1.length() - 1, j = s2.length() - 1;
		int carry = 0;
		while (i >= 0) {
			int num1 = s1.charAt(i--) - '0';
			int num2 = j >= 0 ? s2.charAt(j--) - '0' : 0;
			int diff = num1 - num2 + carry;
			sb.append((diff + 10) % 10);
			carry = diff < 0 ? -1 : 0;
		}
		sb = sb.reverse();
		int k = 0;
		while (sb.charAt(k) == '0') {
			k++;
		}
		return sb.substring(k);
	}
	public String toString() {
		return (sign == -1 ? "-" : "") + num;
	}
	public static void main(String[] args) {
		BigInt bg1 = new BigInt("-90");
		BigInt bg2 = new BigInt("90");
		System.out.println(bg1.add(bg2));
	}
}