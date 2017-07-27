public class LeftRightTarget {
	/*
	第一问是问给定一个数组，和一个 taget 值。最后要求给出一个 pivot，pivot 左边的 taget 值得个数要等于右边不等于 target 值数字的个数。
	一开始给了一个 O2的解法。要求 improve，然后给出了 On 的解法。然后就要求证明，用这个解法解出的答案是不是唯一解。
	
	input 一个array A一个数x，找出A里边的一个index k使a1 = A[0~k-1]里边等于x的元素个数 等于 a2=A[k ~ n-1]里不等于x的元素的个数，
	如果没有符合的返回-1。注意a1和a2不能为空，也就是0和n-1都不符合要求。
	好找。扫一遍数出一共x多少个xTotal。再扫一遍，边扫边数出已经遇到的x个数xMet。这样在每个index都能随时直接算出a2里不等于x的元素的个数了。
	然后让人工过一个test case。
	follow up ：可不可能有多个符合的index.。答曰：不能。追问：请证。
	
	之前没看见有人报这个followup，一开始虽然直觉觉得不能，但是还是没想清楚，只想到在第二遍扫的时候有四个相关的变量：
	xMet，nonXMet, xNotMet, nonXNotMet。其中xMet和nonXMet组成了扫过的部分，xNotMet和nonXNotMet组成了未扫过的部分。
	符合的条件则是：xMet = nonXNotMet。而这两个变量一个只能递增(xMet)，一个只能递减(nonXNotMet)，而且并不能同时不变，
	因为如果当前index值是x，index++之后xMet也+1；如果当前的index值不是x，index++之后nonXNotMet就-1。所以不能同时不变，就不能有多个符合的。
	
	*/
	
	public static int leftRightTarget(int[] nums, int target) {
		int T = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == target) {
				T++;
			}
		}
		if (n - T == 0 || n - T == n) {
			return -1;
		}
		return n - T;
	}
	public static void main(String[] args) {
		
	}
}