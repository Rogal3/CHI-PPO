import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static int[][] map;
	
	public static void main(String[] args) {
		readInput();
		// printMap();
		List<Integer> answer = new ArrayList<>();
		boolean[][] visited = new boolean[N][M];
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (map[y][x] == 0 && visited[y][x] == false) {
					answer.add(dfs(y, x, visited));
				}
			}
		}
		Collections.sort(answer);
		System.out.println(answer.size());
		for (int e : answer) {
			System.out.print(e + " ");
		}
	}
	
	public static void readInput() {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		int K = scanner.nextInt();
		map = new int[N][M];
		for (int k = 0; k < K; ++k) {
			int ax = scanner.nextInt();
			int ay = scanner.nextInt();
			int bx = scanner.nextInt();
			int by = scanner.nextInt();
			for (int y = ay; y < by; ++y) {
				for (int x = ax; x < bx; ++x) {
					map[y][x] = 1;
				}
			}
		}
	}
	
	public static int dfs(int y, int x, boolean[][] visited) {
		final int[] dy = {-1, 1, 0, 0};
		final int[] dx = {0, 0, -1, 1};
		int ret = 1;
		visited[y][x] = true;
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (inRange(ny, nx) && map[ny][nx] == 0 && visited[ny][nx] == false) {
				ret += dfs(ny, nx, visited);
			}
		}
		return ret;
	}
	
	public static boolean inRange(int y, int x) {
		return 0 <= y && y < N && 0 <= x && x < M;
	}
	
	public static void printMap() {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				System.out.print(map[y][x] + " ");
			}
			System.out.println();
		}
	}
}
