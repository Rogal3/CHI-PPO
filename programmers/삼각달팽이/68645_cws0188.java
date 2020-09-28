/*

https://programmers.co.kr/learn/courses/30/lessons/68645

author : cws0188

date : 200928

 */


class Solution {
    public int[] solution(int n) {
        final int[] dr = {1, 0, -1};
        final int[] dc = {0, 1, -1};
        final int[] rd = {1, 2, 0};
        int[][] shell = new int[n + 1][n + 1];
        shell[n][0] = -1;
        shell[n - 1][n] = -1;
        int r = -1, c = 0, d = 0;
        int v = 1;
        int size = n * (n + 1) / 2;
        while (v <= size) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (shell[nr][nc] == 0) {
                r = nr;
                c = nc;
                shell[r][c] = v++;
            } else {
                d = rd[d];
            }
        }
        int[] answer = new int[size];
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                answer[index++] = shell[i][j];
            }
        }
        return answer;
    }
}
