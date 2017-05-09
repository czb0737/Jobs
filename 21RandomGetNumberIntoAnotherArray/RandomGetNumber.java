import java.util.*;

public class RandomGetNumber {
	/*
	
	http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=205663&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
	
	最后是random从一个array里面选出来一个数放到另一个array里面去～ 然后问random函数如何写才能保证等概率的取到各个idx
	就是得到的random值超过range再从新random一次就好
	*/
	Random random = new Random();
	public static getNumRandomly(int len, int[] arr) {
		int index = random.nextInt(len);
		swap(arr, index, len - 1);
		return arr[len - 1];
	}
	private void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	public static void main(String[] args) {
		
	}
}