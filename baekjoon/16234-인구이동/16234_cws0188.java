import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static int N;
	static int L;
	static int R;
	static int[][] map;
	static int[][] unionMap;
	static int numOfUnions;
	static final int[] dr = {0, -1, 0, 1};
	static final int[] dc = {-1, 0, 1, 0};
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int answer = 0;
		readInput();
		while (findUnions()) {
			++answer;
			move();
		}
		System.out.println(answer);
	}

	public static void readInput() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		for (int r = 0; r < N; ++r) {
			st = new StringTokenizer(br.readLine());
			for (int c = 0; c < N; ++c) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	public static boolean findUnions() {
		numOfUnions = 0;
		unionMap = new int[N][N];
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				if (unionMap[r][c] == 0) {
					Queue<Integer> qr = new LinkedList<Integer>();
					Queue<Integer> qc = new LinkedList<Integer>();
					Queue<Integer> qu = new LinkedList<Integer>();
					qr.offer(r);
					qc.offer(c);
					qu.offer(++numOfUnions);
					unionMap[r][c] = numOfUnions;
					while (!qr.isEmpty()) {
						int cr = qr.poll();
						int cc = qc.poll();
						int cu = qu.poll();
						for (int d = 0; d < 4; ++d) {
							int nr = cr + dr[d];
							int nc = cc + dc[d];
							if (inRange(nr, nc) && unionMap[nr][nc] == 0 && L <= Math.abs(map[cr][cc] - map[nr][nc]) && Math.abs(map[cr][cc] - map[nr][nc]) <= R ) {
								qr.offer(nr);
								qc.offer(nc);
								qu.offer(cu);
								unionMap[nr][nc] = cu;
							}
						}
					}
				}
			}
		}
		return numOfUnions != N * N;
	}
	
	public static boolean inRange(int r, int c) {
		return 0 <= r && r < N && 0 <= c && c < N;
	}
	
	public static void move() {
		int[] nationsOfUnions = new int[numOfUnions + 1];
		int[] populationOfUnions = new int[numOfUnions + 1];
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				++nationsOfUnions[unionMap[r][c]];
				populationOfUnions[unionMap[r][c]] += map[r][c];
			}
		}
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				map[r][c] = populationOfUnions[unionMap[r][c]] / nationsOfUnions[unionMap[r][c]];
			}
		}
	}
}
