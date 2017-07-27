import java.util.*;

/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=207866&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

You’re playing your favorite RPG, and your character has just found a room full of treasure. You have n inventory slots. Luckily, objects of the same type stack together, with the maximum size of the stack depending on the type (e.g. coins might stack to 10, diamonds to 5, armor to 1, etc.). Each stack (or partial stack) takes up 1 inventory slot. Each item has a selling value (e.g. a single diamond might be worth 10, so a stack of 5 diamonds would be worth 50). You want to maximize the total selling value of the items in your inventory.
. from: 1point3acres.com/bbs 

Write a function to find the set of things to bring home that maximizes the total value.


Input:
n: The number of inventory slots
items: Array of item types, one for each item in the room
item_infos: Array of structs, one for each unique item type
struct ItemInfo {. From 1point 3acres bbs
	String name;
	int value;
	int maximum_stack_size;
}. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴


Output:
The maximum total value


Example input


n: 3
items: [“diamond”, “ruby”, “armor”, “diamond”, “diamond”, “ruby”, “diamond”, “diamond”, “diamond”, “diamond”, “diamond” “armor”]
item_infos:[. 鐣欏鐢宠璁哄潧-涓€浜╀笁鍒嗗湴
{
	name=”diamond”
	value=10
	maximum_stack_size=5
},-google 1point3acres
{
	name=”ruby”. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴
	value=5
	maximum_stack_size=5
},
{
	name=”armor”
	value=25. visit 1point3acres.com for more.
	maximum_stack_size=1
}. 鍥磋鎴戜滑@1point 3 acres
]


Example output
105 (1 stack of 5 diamonds worth 50, 1 partial stack of 3 diamonds worth 30, 1 stack of 1 armor worth 25).鏈枃鍘熷垱鑷�1point3acres璁哄潧

*/


class ItemInfo {
	String name;
	int value;
	int maximum_stack_size;
	ItemInfo(String name, int value, int maximum_stack_size) {
		this.name = name;
		this.value = value;
		this.maximum_stack_size = maximum_stack_size;
	}
}

class Item {
	String name;
	int value;
	int maximum_stack_size;
	int count;
	Item (String name, int value, int maximum_stack_size, int count) {
		this.name = name;
		this.value = value;
		this.maximum_stack_size = maximum_stack_size;
		this.count = count;
	}
}

public class Solution {
	public static int getMaximumTotalValue(int n, String[] items, ItemInfo[] item_infos) {
		Map<String, Integer> counter = new HashMap<>();
		for (String item : items) {
			if (!counter.containsKey(item)) {
				counter.put(item, 0);
			}
			counter.put(item, counter.get(item) + 1);
		}
		PriorityQueue<Item> pq = new PriorityQueue<Item>(100, new Comparator<Item>(){
			@Override
			public int compare(Item i1, Item i2) {
				return i2.value * Math.min(i2.maximum_stack_size, i2.count) - 
						i1.value * Math.min(i1.maximum_stack_size, i1.count);
			}
		});
		for (ItemInfo item_info : item_infos) {
			Item item = new Item(item_info.name, item_info.value, item_info.maximum_stack_size, counter.get(item_info.name));
			pq.offer(item);
		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			if (pq.isEmpty()) {
				break;
			}
			Item item = pq.poll();
			int num = Math.min(item.maximum_stack_size, item.count);
			item.count -= num;
			result += num * item.value;
			if (item.count > 0) {
				pq.offer(item);
			}
		}
		return result;
	}
	public static void main(String[] args) {
		String[] items = {"diamond", "ruby", "armor", "diamond", "diamond", "ruby", "diamond", "diamond", "diamond", "diamond", "diamond", "armor"};
		ItemInfo[] item_infos = {new ItemInfo("diamond", 10, 5), new ItemInfo("ruby", 5, 5), new ItemInfo("armor", 25, 1)};
		System.out.println(getMaximumTotalValue(3, items, item_infos)); 
	}
}