import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static int[][] map;
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int t = 1; t <= T; ++t) {
			readInput(scanner);
			int countOfWorms = 0;
			boolean[][] visited = new boolean[N][M];
			for (int r = 0; r < N; ++r) {
				for (int c = 0; c < M; ++c) {
					if (map[r][c] == 1 && !visited[r][c]) {
						++countOfWorms;
						dfs(r, c, visited);
					}
				}
			}
			System.out.println(countOfWorms);
		}
	}
	
	public static void readInput(Scanner scanner) {
		N = scanner.nextInt();
		M = scanner.nextInt();
		int K = scanner.nextInt();
		map = new int[N][M];
		for (int k = 0; k < K; ++k) {
			map[scanner.nextInt()][scanner.nextInt()] = 1;
		}
	}
	
	public static void dfs(int r, int c, boolean[][] visited) {
		final int[] dr = {-1, 0, 1, 0};
		final int[] dc = {0, 1, 0, -1};
		visited[r][c] = true;
		for (int d = 0; d < 4; ++d) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (inRange(nr, nc) && map[nr][nc] == 1 && !visited[nr][nc]) {
				dfs(nr, nc, visited);
			}
		}
	}
	
	public static boolean inRange(int r, int c) {
		return 0 <= r && r < N && 0 <= c && c < M; 
	}
}
