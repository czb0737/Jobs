class Item {
	int max_stack_size;
	int value;
	int nums;
	Item (int max_stack_size, int value, int nums) {
		this.max_stack_size = max_stack_size;
		this.value = value;
		this.nums = nums;
	}
}


public class ArmorDiamondRuby {
	/*
	假设现在有三种item: armor, diamond, ruby，每种item有各自的value，你作为一个游戏中的一个角色，你的背包里有n个slots里。
	现在就是要求，比如输入是10个armor，5个diamond，3个ruby，你怎么拿使得最后背包中的value和最大。但是有两个限制，背包里的1个slot只能装同种的东西，
	比如你有两个slots，一个slot只能拿armor，另一个就只能拿ruby。另一个限制是每一个item有一个max_stack_size，就是比如armor的max_stack_size = 5，
	说明你最多拿5个armor在一个slot中。
	*/
	
	
	public getLargestValue(Item diamond, Item ruby, Item armor, int n) {
		int total = 0;
		PriorityQueue<Item> pq = new PriorityQueue<Item>(3, new Comparator<Item>(){
			public int compare(Item i1, Item i2) {
				int v1 = i1.nums >= i1.max_stack_size ? i1.max_stack_size * i1.value : i1.nums * i1.value;
				int v2 = i2.nums >= i2.max_stack_size ? i2.max_stack_size * i2.value : i2.nums * i2.value;
				return v2 - v1;
			}
		});
		pq.offer(diamond);
		pq.offer(ruby);
		pq.offer(armor);
		for (int i = 0; i < n; i++) {
			Item curr = pq.poll();
			int numOfItems = curr.nums >= curr.max_stack_size ? curr.max_stack_size : curr.nums;
			total += curr.value * numOfItems;
			curr.nums -= numOfItems;
			if (curr.nums > 0) {
				pq.offer(curr);
			}
		}
		return total;
	}
	
	public static void main(String[] args) {
		
	}
}