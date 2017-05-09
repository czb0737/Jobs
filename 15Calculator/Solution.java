import java.util.*;

public class Solution {
	// 1 + 2 * 2 ^ 3 * 2 + 4
	// 1 2 12 \
	
	// 1 + 2 ^ 3 * 2 
	
	// 1 12
	
	// 1 + 2 * 3 ^ 2 ^ 6
	
	// 1 6 / 3 * 9
	
	// 1  18
	//  1 2 3 9 
	
	// 1 + 2 ^ 3 ^ 4
	
	// 1   8 
	//  1 2 8 
	
	//1. previous sign is not multiplication: ^ 
	
	
	// 1 6     3   9
	// 1 12
	// 13
	public static int calculate(String s) {
		Stack<Integer> stack = new Stack<>();
		char sign = '+';
		int num = 0, base = 0;
		for (int i = 0; i <= s.length(); i++) {
			if (i == s.length() || s.charAt(i) == '+' || s.charAt(i) == '*' || s.charAt(i) == '^') {
				if (sign == '+') {
					stack.push(num);
					base = num;
				} else if (sign == '*') {
					stack.push(stack.pop() * num);
					base = num;
				} else if (sign == '^') {
					int prev = base;
					base = (int)Math.pow((double)base, num);
					stack.push(stack.pop() / prev * base);
				}
				if (i < s.length()) {
					sign = s.charAt(i);
					num = 0;
				}
			} else if (Character.isDigit(s.charAt(i))) {
				num = num * 10 + s.charAt(i) - '0';
			} else if (s.charAt(i) == '(') {
				int j = i + 1, count = 1;
				while (j < s.length()) {
					if (s.charAt(j) == '(') {
						count++;
					} else if(s.charAt(j) == ')') {
						count--;
					}
					if (count == 0) {
						break;
					}
					j++;
				}
				num = calculate(s.substring(i + 1, j));
				i = j;
			}
		}
		int sum = 0;
		while (!stack.isEmpty()) {
			sum += stack.pop();
		}
		return sum;
	}
	
//	public static int calculate(String s) {
//		Stack<Integer> stack = new Stack<>();
//		char sign = '+';
//		int num = 0;
//		for (int i = 0; i <= s.length(); i++) {
//			if (i == s.length() || s.charAt(i) == '+' || s.charAt(i) == '*') {
//				if (sign == '+') {
//					stack.push(num);
//				} else if (sign == '*') {
//					stack.push(stack.pop() * num);
//				}
//				if (i < s.length()) {
//					sign = s.charAt(i);
//					num = 0;
//				}
//			} else if (Character.isDigit(s.charAt(i))) {
//				num = num * 10 + s.charAt(i) - '0';
//			}
//		}
//		int sum = 0;
//		while (!stack.isEmpty()) {
//			sum += stack.pop();
//		}
//		return sum;
//	}
	public static void main(String[] args) {
		String s = "((2 + 2 * 3) ^ 2)";
		System.out.println(calculate(s));
	}
}