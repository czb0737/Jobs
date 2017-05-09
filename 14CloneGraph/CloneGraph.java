import java.util.*;

public class CloneGraph {
	
/*
上周五电面的，今天就收到了据信，hr Jessica效率真是高。面试官是个英国小哥，还有个印度人，我接到电话，两个人都跟我打了招呼也是蒙蔽。。。
先问了5分钟的project，进了codepad环境发现真的是两个人。问了两道题，第一道strstr， 问了我不用substring的方法行不行，
还有for 循环为什么是到haystack.length()-needlge.length()+1的，然后写worst case。然后第二题是clone graph.用了dfs的方法写的，
英国小哥让我自己定义graph class,然后follow up 问了不用node.label怎么办。还有如果两个thread同时call 这个方法会怎么样？lz这里卡了半天，
最后经过英国小哥提点才发现是hashmap的问题，hashmap在多线程里就不安全。问我改进方法，说了改成concurrenthashmap,然后问了worst case。然后就结束了。
lz面完感觉就挂了，虽然代码都写出来了，run也没有错误，但是那个多线程的问题确实没答好。感觉找工作真的是心累，不断的面试不断的吃据信，可能真的实力还不够吧。
多多向地里的大神们学习，求大家加点大米

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=209567&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
*/	

	
//	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
//		if (node == null) {
//			return null;
//		}
//		Queue<UndirectedGraphNode> q = new LinkedList<>(); // waiting for add neighbors
//		Map<Integer, UndirectedGraphNode> map = new HashMap<>(); // all the nodes
//		q.offer(node);
//		map.put(node.label, new UndirectedGraphNode(node.label));
//		while (!q.isEmpty()) {
//			UndirectedGraphNode curr = q.poll();
//			for (UndirectedGraphNode neighbor : curr.neighbors) {
//				if (!map.containsKey(neighbor.label)) {
//					map.put(neighbor.label, new UndirectedGraphNode(neighbor.label));
//					q.offer(neighbor);
//				}
//				map.get(curr.label).neighbors.add(map.get(neighbor.label));
//			}
//		}
//		return map.get(node.label);
//	}
	public static void main(String[] args) {
		String s1 = "wrtjk", s2 = "wrt";
		System.out.println(s1.indexOf(s2));
	}
}