import java.util.Scanner;

public class Main {
	static final int[] directionR = {-1, 0, 1, 0};
	static final int[] directionC = {0, 1, 0, -1};
	static final int[] rotateDirection = {1, 2, 3, 0};
	
	static int T;
	static int N;
	static int M;
	static int[][] map;
	static boolean[][] visited;
	static int rOfRat;
	static int cOfRat;
	static int dOfRat;
	static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			readInput();
			int countOfMovements = 0;
			visited = new boolean[N + 1][M + 1];
			visited[rOfRat][cOfRat] = true;
			while (move()) {
				++countOfMovements;
			}
			System.out.println("#" + t + " " + countOfMovements);
		}
	}
	
	public static void readInput() {
		N = sc.nextInt();
		M = sc.nextInt();
		rOfRat = sc.nextInt();
		cOfRat = sc.nextInt();
		dOfRat = sc.nextInt();
		map = new int[N + 1][M + 1];
		for (int r = 1; r <= N; ++r) {
			for (int c = 1; c <= M; ++c) {
				map[r][c] = sc.nextInt();
			}
		}
	}
	
	public static boolean move() {
		boolean canMove = false;
		int nextR = 0;
		int nextC = 0;
		for (int i = 0; i < 4; ++i) {			// find direction
			nextR = rOfRat + directionR[dOfRat];
			nextC = cOfRat + directionC[dOfRat];
			if (1 <= nextR && nextR <= N && 1 <= nextC && nextC <= M && 
					map[nextR][nextC] == 0 && visited[nextR][nextC] == false) {
				canMove = true;
				break;
			}
			dOfRat = rotateDirection[dOfRat];
		}
		if (canMove) {							// found direction
			rOfRat = nextR;
			cOfRat = nextC;
			visited[nextR][nextC] = true;
		} else {								// can't move in any direction
			nextR = rOfRat - directionR[dOfRat];
			nextC = cOfRat - directionC[dOfRat];
			if (1 <= nextR && nextR <= N && 1 <= nextC && nextC <= M && 
					map[nextR][nextC] == 0) {	// back step
				rOfRat = nextR;
				cOfRat = nextC;
				visited[nextR][nextC] = true;
			} else {							// robot stop
				return false;
			}
		}
		return true;
	}
}

/*

input example

3
4 4
2 2 2
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1
3 4
2 3 0
1 1 1 1
1 0 0 1
1 1 1 1
8 7
4 5 0
1 1 1 1 1 1 1
1 0 0 0 0 0 1
1 0 0 0 0 1 1
1 1 0 1 0 1 1
1 0 0 0 0 0 1
1 0 1 1 0 0 1
1 0 0 0 0 0 1
1 1 1 1 1 1 1

*/

/*

output example

#1 4
#2 2
#3 30

*/
