import java.util.*;



public class MyVersion {
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
		//					String[] map = {
		//						"02a11",
		//						"0100A",
		//						"01003",
		//						"01001",
		//						"01111"
		//					};
							String[] map = {
								"21A13",
								"01000",
								"01000",
								"0a000"
							};
							           
							Node dest = shortestPath(map, 0,0);
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