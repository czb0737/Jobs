import java.util.*;


//Dijkstra: VlogV + ElogV, using binomial heap to simplify, insertion O(1), using fibonacci heap, decrease key O(1): we 

class Point {
		int x, y;
		Point parent;
		Set<Character> keys;
		Point(int x, int y, Point parent) {
			this.x = x;
			this.y = y;
			this.parent = parent;
			keys = new HashSet<>();
		}
		@Override 
		public int hashCode() {
			return keys.hashCode() + 31 * x + y;
 		}
		@Override
		public boolean equals(Object object) {
			Point p = (Point) object;
			return p.x == this.x && p.y == this.y && p.keys.equals(this.keys);
		}
		@Override
		public String toString() {
			return "[(" + x + "," + y + ")" + keys +"]";
		}
	}

public class FindShortestPath {
	/*
	先问了你知道哪些最短路方法呀?Dijkstra复杂度是多少,优化后是多少?提了句SPFA,BellmanFord的改进,然后聊了聊复杂度和怎么改进.
	啥时用SPFA啥时用Dijkstra,有啥Dijkstra做不到BellmanFord能做到的?
	然后问了地里面出现过的2D地图找到从起点到终点的最短路径,有的地方有钥匙和门还有障碍,最多26种门和钥匙.一把钥匙开完门后就会消失不能再开了.
	写完了跟小哥解释完好像还可以,然后QA了一会儿.
	
	
	
	Problem Statement
	Suppose you have a 2-D grid. Each point is either land or water. There is also a start point and a goal.

	There are now keys that open up doors. Each key corresponds to one door.

	Implement a function that returns the shortest path from the start to the goal using land tiles, keys and open doors.

	Data Representation
	The map will be passed as an array of strings.

	A map can have the following tiles.

	0 = Water
	1 = Land
	2 = Start
	3 = Goal

	uppercase = door
	lowercase = key
	
	A: door;  a: key to the door A
	B: door;  b: key to the door B
	....
	Z:..

	Example Maps (keys at each step are not required)
	`No doors`
	MAP_1 = 	['02111',
				'01001',
				'01003',
				'01001',
				'01111']

	Solution
	(1, 0) with keys ''
	(2, 0) with keys ''
	(3, 0) with keys ''
	(4, 0) with keys ''
	(4, 1) with keys ''
	(4, 2) with keys ''
	`One door`
	MAP_2 =    ['02a11',
				'0100A',
				'01003',
				'01001',
				'01111']

	Solution
	Keys needed:
	(1, 0) with keys ''
	(2, 0) with keys ''
	(3, 0) with keys 'a'
	(4, 0) with keys 'a'
	(4, 1) with keys 'a'
	(4, 2) with keys 'a'
	
	
	0a21A3
	*/
	
	
	
	public static List<Point> findShortestPath(String[] map) {
		List<Point> result = new ArrayList<>();
		if (map.length == 0 || map[0].length() == 0) {
			return result;
		}
		int m = map.length, n = map[0].length();
		Point start = null;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i].charAt(j) == '2') {
					start = new Point(i, j, null);
				}
			}
		}	
//		System.out.println(start);
		Queue<Point> q = new LinkedList<>();
		Set<Point> visited = new HashSet<>();
		int[] dx = {0,1,0,-1};
		int[] dy = {1,0,-1,0};
		q.offer(start);
		Point end = null;
		while (!q.isEmpty()) {
			Point curr = q.poll();
			if (map[curr.x].charAt(curr.y) == '3') {
				end = curr;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = curr.x + dx[i];
				int ny = curr.y + dy[i];
				if (isValid(nx, ny, m, n) && map[nx].charAt(ny) != '0') {
					char symbol = map[nx].charAt(ny);
					Point np = new Point(nx, ny, curr);
					np.keys.addAll(curr.keys);
					if (symbol >= 'a' && symbol <= 'z') {
						np.keys.add(symbol);
					} else if (symbol >= 'A' && symbol <= 'Z') {
						char key = (char)(symbol - 'A' + 'a');
						if (!curr.keys.contains(key)) {
							continue;
						} else {
							np.keys.remove(key);
						}
					}
					if (!visited.contains(np)) {
						visited.add(np);
						q.offer(np);
					}
				}
			}
		}
		List<Point> path = new ArrayList<>();
		if (end == null) {
			return path;
		}
//		System.out.println(end);
		Point curr = end;
		while (curr != null) {
			path.add(0, curr);
			curr = curr.parent;
		}
		return path;
	}
	private static boolean isValid(int i , int j, int m, int n) {
		if (i >= 0 && i < m && j >= 0 && j < n) {
			return true;
		}
		return false;
	}
	public static void main(String[] args) {
//		String[] map = {
//			"02111",
//			"01001",
//			"01003",
//			"01001",
//			"01111"
//		};
//		String[] map = {
//			"02a11",
//			"0100A",
//			"01003",
//			"01001",
//			"01111"
//		};
//		String[] map = {
//			"3Ba2Ab"
//		};
//		String[] map =  {
//			"2bAaB3"	
//		};
		String[] map = {"0a2bBA3"};
		List<Point> path = findShortestPath(map);
		if (path.isEmpty()) {
			System.out.println("No path");
		} else {
			for (Point p : path) {
				System.out.println(p);
			}
		}
		
	}
}