import java.util.*;

/*
给两个数组
一个数组A [5,5,5,8,8,4,4,1,1,1,1,2,2,2,2,2] 
一个数组B [3,5,1,2,4]
输出数组C [5,2,-1,8,1]
A里面存的是int，B里面存的是A里面某一个int的出现的次数。要输出一个数组C表示A里面的哪个元素出现了那么多次。
B[0] = 3，表示A里面5出现了三次，所以C[0]是5.
B[1] = 5，表示A里面2出现了五次，所以C[1]是2.
B[2] = 1，A里面没有元素出现了一次，所以C[2]是-1.
以此类推。

应该是新题。给一个Array a, 一个Array b。Array b中的元素可能是Array a中某个元素出现的次数，也可能不是。
让你返回一个Array c, c中的元素与b中的元素相对应，如果b中的元素是a中某个元素出现的次数，
那c中的对应的元素就是a中的那个元素(如果a中好几个元素都有相同的出现次数，则返回任意一个)，
如果b中的元素不是a中任意一个元素出现的次数，c中得对应元素就是-1。这题其实挺简单的，用map搞搞即可。
*/

public class TwoArrayParse {
	public static int[] parseArray(int[] A, int[] B) {
		Map<Integer, Integer> counter = new HashMap<>();
		for (int i = 0; i < A.length; i++) {
			if (!counter.containsKey(A[i])) {
				counter.put(A[i], 0);
			}
			counter.put(A[i], counter.get(A[i]) + 1);
		}
		Map<Integer, Integer> map = new HashMap<>();
		for (int key : counter.keySet()) {
			map.put(counter.get(key), key);
		}
		int[] result = new int[B.length];
		for (int i = 0; i < result.length; i++) {
			result[i] = map.get(B[i]) == null ? -1 : map.get(B[i]);
		}
		return result;
	}
	
	public static void main(String[] args) {
		int[] A = {5,5,5,8,8,4,4,1,1,1,1,2,2,2,2,2};
		int[] B = {3,5,1,2,4};
		System.out.println(Arrays.toString(parseArray(A, B)));
	}
}