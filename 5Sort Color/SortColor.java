import java.util.*;

/*
sort color, color  是object型的，自带一个enum的属性
第一问正常的排三种颜色，就是地里面经的方法，two pointers
第二问sort 4 colors，先排第一种和最后一种，再排中间两种
第三问：sort n colors，，重点来了。。。本来想直接用线排1，n-1; 再排2，n－2这样做，问了我一下时间复杂度，然后问我有没有更好的方法，我愣了一下，小哥继续提示，有没有好的sort alogrithm，我说有，quick sort, 然后问了我一下复杂度是多少，口误不小心把best case说成O(logn)了，应该是O(nlogn), 然后就让我描述下具体怎么实现，不用写代码，再选pivot value的时候有点磕巴，之前不知道选中间那个，小哥一直给我举例提示才会的，后来就说correct什么的，然后问了下问题，就byebye了。。
是的 object里面有个enum的field放了 RED，GREEN，BLUE，直接用object.Color直接取就好了～当是我不太明白怎么取 说不太熟悉enum，还是小哥告诉的，跟int没差哈～

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210629&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=147320&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

*/



public class SortColor {
	
//	public static void sortColor(int[] A) {
//		int i = 0, j = A.length - 1;
//		for (int k = 0; k <= j; k++) {
//			while (k < j && A[k] == 2) {
//				swap(A, k, j--);
//			}
//			while (i < k && A[k] == 0) {
//				swap(A, k, i++);
//			}
//		}
//	}
//	private static void swap(int[] A, int i , int j) {
//		int temp = A[i];
//		A[i] = A[j];
//		A[j] = temp;
//	}

//	public enum Object {
//		RED, GREEN, BLUE, YELLOW, BLACK, WHITE
//	}
	
	
//	public static void sortColor(Object[] colors) {
//		int i = 0, j = colors.length - 1;
//		for (int k = 0; k <= j; k++) {
//			while (k < j && colors[k] == Object.RED) {
//				swap(colors, k, j--);
//			}
//			while (i < k && colors[k] == Object.BLUE) {
//				swap(colors, k, i++);
//			}
//		}
//	}
//	
//	public static void sortFirstThree(Object[] colors) {
//		int r = 0, o = colors.length - 1;
//		for (int i = 0; i <= o; i++) {
//			while (i < o && isOthers(colors[i])) {
//				swap(colors, i, o--);
//			}
//			while (r < i && colors[i] == Object.RED) {
//				swap(colors, i, r++);
//			}
//		}
//		int g = r, b = o;
//		for (int i = r; i <= b; i++) {
//			while (i < b && colors[i] == Object.BLUE) {
//				swap(colors, i, b--);
//			}
//			while (g < i && colors[i] == Object.GREEN) {
//				swap(colors, i, g++);
//			}
//		}
//	}
//	
//	private static boolean isOthers(Object color) {
//		return !(color == Object.RED || color == Object.GREEN || color == Object.BLUE);
//	}
//	
//	private static void swap(Object[] A, int i , int j) {
//		Object temp = A[i];
//		A[i] = A[j];
//		A[j] = temp;
//	}

	public enum Color {
		RED, GREEN, BLUE, YELLOW, BLACK, WHITE
	}
	// quick sort when compare never be equal
	public static void sortColor(Color[] colors) {
		helper(colors, 0, colors.length - 1);
	}   
	private static void helper(Color[] colors, int start, int end) {
		if (start >= end) {
			return;
		}
		Color pivot = colors[start];
		int i = start + 1, j = end;
		// 0 0
		while (i <= j) {
			while (i <= j && colors[i].compareTo(pivot) < 0) {
				i++;
			}
			while (i <= j && colors[j].compareTo(pivot) > 0) {
				j--;
			}
			if (i <= j) {
				swap(i, j, colors);
				i++;
				j--;
			}
		}
		swap(start, j, colors);
		helper(colors, start, j);
		helper(colors, i, end);
	}
	private static void swap(int i, int j, Color[] colors) {
		Color temp = colors[i];
		colors[i] = colors[j];
		colors[j] = temp;
	}
	
	public static void main(String[] args) {
//		int[] A = {1, 0, 2};
//		sortColor(A);
//		System.out.println(Arrays.toString(A));
//		Object[] colors = {Object.BLACK, Object.BLUE, Object.YELLOW, Object.RED ,Object.RED, Object.GREEN, Object.RED, Object.BLACK, Object.WHITE};
//		sortFirstThree(colors);
//		System.out.println(Arrays.toString(colors));
//		System.out.println(Color.YELLOW.compareTo(Color.BLUE));
		Color[] colors = {Color.BLACK, Color.BLUE, Color.YELLOW, Color.RED ,Color.RED, Color.GREEN, Color.RED, Color.BLACK, Color.WHITE};
		sortColor(colors);
		System.out.println(Arrays.toString(colors));
	}
}

// quick sort test case : 0 0