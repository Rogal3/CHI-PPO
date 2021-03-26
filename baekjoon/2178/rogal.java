// https://www.acmicpc.net/problem/2178

import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;
    static char[][] map;
  
    public static void main(String[] args) throws IOException {
        readInput();
        int answer = bfs();
        System.out.println(answer);
    }

    public static void readInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            for (int j = 1; j <= m; j++) {
                map[i][j] = line.charAt(j - 1);
            }
        }
        br.close();
    }

    public static int bfs() {
        class Coord {
            int r;
            int c;
            int moves;
            Coord(int r, int c, int time) {
                this.r = r;
                this.c = c;
                this.moves = time;
            }
        }
        final int dr[] = {-1, 0, 1, 0};
        final int dc[] = {0, 1, 0, -1};
        Queue<Coord> queue = new LinkedList();
        boolean[][] visited = new boolean[n + 1][m + 1];
        queue.offer(new Coord(1, 1, 1));
        visited[1][1] = true;
        while (!queue.isEmpty()) {
            Coord current = queue.poll();
            // System.out.println(String.format("r = %d, c = %d, m = %d", current.r, current.c, current.moves));
            if (current.r == n && current.c == m) {
                return current.moves;
            }
            for (int d = 0; d < 4; d++) {
                Coord next = new Coord(current.r + dr[d], current.c + dc[d], current.moves + 1);
                if (inRange(next.r, next.c) && map[next.r][next.c] == '1' && !visited[next.r][next.c]) {
                    queue.offer(next);
                    visited[next.r][next.c] = true;
                }
            }
        }
        return -1;
    }

    public static boolean inRange(int r, int c) {
        return 0 < r && 0 < c && r <= n && c <= m;
    }
}
