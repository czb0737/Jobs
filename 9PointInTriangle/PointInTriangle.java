class Point {
	int x, y;
	Point (int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class PointInTriganle {
	private boolean checkSide (int x1, int y1, int x2, int y2, int x, int y) {
		return ((y2 - y1) * (x - x1) + (x1 - x2) * (y - y1)) >= 0;
	}
	
	public boolean isPointInTriangle (Point p1, Point p2, Point p3, Point p) {
		return checkSide(p1.x, p1.y, p2.x, p2.y, p.x, p.y)
				&& checkSide(p2.x, p2.y, p3.x, p3.y, p.x, p.y)
				&& checkSide(p3.x, p3.y, p1.x, p1.y, p.x, p.y);
	}
	public static void main(String[] args) {
			
	}
}