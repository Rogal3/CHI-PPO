import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static int[][] map;
	static int countOfNormalTomato;
	
	public static void main(String[] args) {
		readInput();
		int answer = bfs();
		if (countOfNormalTomato == 0) {
			System.out.println(answer);
		} else {
			System.out.println(-1);
		}
	}
	
	public static void readInput() {
		Scanner scanner = new Scanner(System.in);
		M = scanner.nextInt();
		N = scanner.nextInt();
		map = new int[N][M];
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				int read = scanner.nextInt();
				map[r][c] = read;
				countOfNormalTomato += read == 0 ? 1 : 0;
			}
		}
	}
	
	public static int bfs() {
		Queue<int[]> q = new LinkedList<int[]>();
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				if (map[r][c] == 1) {
					int[] a = {r, c};
					q.add(a);
				}
			}
		}
		final int[] dr = {-1, 1, 0, 0};
		final int[] dc = {0, 0, -1, 1};
		int days = -1;
		while (!q.isEmpty()) {
			for (int rotten = q.size(); 0 < rotten; --rotten) {
				int[] current = q.poll();
				for (int d = 0; d < 4; ++d) {
					int nr = current[0] + dr[d];
					int nc = current[1] + dc[d];
					if (inRange(nr, nc) && map[nr][nc] == 0) {
						--countOfNormalTomato;
						map[nr][nc] = 1;
						int[] next = {nr, nc};
						q.add(next);
					}
				}
			}
			++days;
		}
		return days;
	}
	
	public static boolean inRange(int r, int c) {
		return 0 <= r && r < N && 0 <= c && c < M;
	}
}
