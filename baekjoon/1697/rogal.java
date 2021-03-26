// https://www.acmicpc.net/problem/1697

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n;
    static int k;
  
    public static void main(String[] args) {
        readInput();
        int answer = bfs();
        System.out.println(answer);
    }

    public static void readInput() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
    }

    public static int bfs() {
        class Coord {
            int x;
            int time;
            Coord(int x, int time) {
                this.x = x;
                this.time = time;
            }
        }
        Queue<Coord> queue = new LinkedList();
        boolean[] visited = new boolean[200001];
        queue.offer(new Coord(n, 0));
        visited[n] = true;
        while (!queue.isEmpty()) {
            Coord current = queue.poll();
            if (current.x == k) {
                return current.time;
            }
            for (int method = 0; method < 3; method++) {
                Coord next = new Coord(move(current.x, method), current.time + 1);
                if (inRange(next.x) && !visited[next.x]) {
                    queue.offer(next);
                    visited[next.x] = true;
                }
            }
        }
        return -1;
    }

    public static int move(int x, int method) {
        switch(method) {
            case 0:
                return x - 1;
            case 1:
                return x + 1;
            case 2:
                return x * 2;
        }
        return -1;
    }

    public static boolean inRange(int x) {
        return 0 <= x && x < 200000;
    }
}
