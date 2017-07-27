import java.util.*;

	public class Solution {
			public static class Node {
					int r;
					int c;
					Set<Character> keys = new HashSet<>();
					Node parent = null;
					Node(int r, int c) {
							this.r = r;
							this.c = c;
					}

					@Override
					public boolean equals(Object object) {
							Node o = (Node)object;
							return r == o.r && c == o.c && keys.containsAll(o.keys)
									&& o.keys.containsAll(keys);
					}

					@Override
					public int hashCode() {
							return keys.hashCode() + r + c;
					}

					@Override
					public String toString(){
							return String.format("[%d,%d], with keys:%s", 
											r, c, keys);
					}
			}
			public static Node shortestPath(String[] map, int sx, int sy) {

					
					Queue<Node> que = new LinkedList<>();
					que.offer(new Node(sx, sy));
					Set<Node> visited = new HashSet<>();

					while (!que.isEmpty()) {
							Node node = que.poll(); 

							if (map[node.r].charAt(node.c) == '3') {
									return node;
							}

							int[] arr = {-1,0,1,0,-1};
							for (int i = 0; i < 4; i++) {

									int r = node.r + arr[i];
									int c = node.c + arr[i+1];

									if (r < 0 || r >= map.length || c < 0 || c >= map[0].length()) {
											continue;
									}
									
									char letter = map[r].charAt(c);
									if (letter == '0') {
											continue;
									}

									if ('A' <= letter && letter <= 'Z') {
											// System.out.printf("DOOR:%c\n", letter);
											char key = (char)('a' + (letter - 'A'));
											if (!node.keys.contains(key)) {
													// System.out.printf("node:%s does NOT contains key\n", node);
													continue;
											} else {
													// System.out.printf("node:%s contains key\n", node);
													// node.keys.remove(key);
											}
									}
									Node neighbor = new Node(r, c);
									neighbor.parent = node;
									neighbor.keys.addAll(node.keys);
									if ('A' <= letter && letter <= 'Z') {
										neighbor.keys.remove((char)('a' + (letter - 'A')));
									}
									                                
									if ('a' <= letter && letter <= 'z') {
											neighbor.keys.add(letter);
									}
									if (visited.contains(neighbor)) {
											continue;
									}

									que.offer(neighbor);
									visited.add(neighbor);
									// System.out.println("Neighbor: " + neighbor);
							}

					}
					return null;

			}


			public static void main(String[] args) {
					/*
					String[] map = {"02a11", 
												"0100A", 
												"01003", 
												"01001", 
												"01111"};                                            
					Node dest = shortestPath(map, 0,1);
					if (dest == null) {
							System.out.println("no path");
					} else {
							while (dest != null) {
									System.out.println(dest);
									dest = dest.parent;
							}
					}*/

 
//					String[] map = {"0a2bBA3"};
					// String[] map = {"3Ba2Ab"};
					// String[] map = {
					// 	"02a11",
					// 	"0100A",
					// 	"01003",
					// 	"01001",
					// 	"01111"
					// };
					String[] map = {
						"1a100",
						"10100",
						"10100",
						"10100",
						"211A3"
					};
					// String[] map = {
					// 	"21A13",
					// 	"01000",
					// 	"01000",
					// 	"0a000"
					// };
					           
					Node dest = shortestPath(map, 4,0);
					if (dest == null) {
							System.out.println("no path");
					} else {
							while (dest != null) {
									System.out.println(dest);
									dest = dest.parent;
							}
					}
			}
			
	}