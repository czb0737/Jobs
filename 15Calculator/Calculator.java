import java.util.*;

/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=205063&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311


1. 给一个表达式，求值，表达式只有数字和'+', '*'. 比如："2+3*2" 返回8， 只考虑int 范围
2. 上面一个的扩展版，增加一个新的符号'^'表示求幂，比如"2+2^2*3" 返回14, ”2^2^3"返回64

2*2^3


给一个表达式 里面有+ - * 和数字 要你parse 然后算出值输出我记得leetcode有原题  不记得题号了
follow up是有括号 
*/

public class Calculator {
	//(1+3)*4/2
	// 5 * (3 + 1) / 2;
	// 1 + 3 * 4 + 2 / 1
	public static int calculate(String s) {
		int num = 0;
		char sign = '+';
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i <= s.length(); i++) {
			char c = i < s.length() ? s.charAt(i) : ' ';
			if (i == s.length() || c == '+' || c == '-' || c == '*' || c == '/'){
				if (sign == '+') {
					stack.push(num);
				} else if (sign == '-') {
					stack.push(-num);
				} else if (sign == '*') {
					stack.push(stack.pop() * num);
				} else if(sign == '/') {
					stack.push(stack.pop() / num);
				}
				num = 0;
				sign = c;
			} else if (Character.isDigit(c)) {
				num = num * 10 + c - '0';
			} else if (c == '(') {
				int j = i + 1, count = 1;
				while (count > 0) {
					if (s.charAt(j) == '(') {
						count++;
					} else if(s.charAt(j) == ')') {
						count--;
					}
					j++;
				}
				num = calculate(s.substring(i + 1, j - 1));
				i = j - 1;
			}
		}
		int result = 0;
		while (!stack.isEmpty()) {
			result += stack.pop();
		}
		return result;
	}
	
	/*
	上来先是跟lc 227差不多，但是只有‘＋’和‘＊’，其实就是一样的。我还写了一个小bug，就是每次见到sign之后，之前的number要清零，还调试了一会儿。嗯，这个确实赖我。。。
	然后又要支持‘－’，注意这不一样了，要考虑2+3*－4+5之类的情况。好不容易搞定了，又说要考虑括号
	*/
	
	// 1 + 2 * 3 + 5
	public static int calculate1(String s) {
		Stack<Integer> stack = new Stack<>();
		char sign = '+';
		int pn = 1;
		int num = 0;
		for (int i = 0; i <= s.length(); i++) {// i++ and i = j need be paid attention
			if (i == s.length() || s.charAt(i) == '+' || s.charAt(i) == '*') {
				if (sign == '+') {
					stack.push(pn * num);
				} else if (sign == '*') {
					stack.push(stack.pop() * pn * num);
				}
				sign = i == s.length() ? ' ' : s.charAt(i);
				num = 0;
				pn = 1;
			} else if (Character.isDigit(s.charAt(i))) {
				num = num * 10 + s.charAt(i) - '0';
			} else if (s.charAt(i) == '-') {
				pn = -1;
			} else if (s.charAt(i) == '(') {
				int j = i + 1, count = 1;
				while (j < s.length()) {
					if (s.charAt(j) == '(') {
						count++;
					} else if (s.charAt(j) == ')') {
						count--;
					}
					if (count == 0) {
						break;
					}
					j++;
				}
				num = calculate1(s.substring(i + 1, j));
				i = j;
			}
		}
		int result = 0;
		while (!stack.isEmpty()) {
			result += stack.pop();
		}
		return result;
	}
	
	public static void main(String[] args) {
		String s = "10 + -2 * (3 + 5 * -3)";
		System.out.println(calculate1(s));
	}
}