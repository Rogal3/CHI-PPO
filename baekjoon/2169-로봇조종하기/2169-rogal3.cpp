// #define DEBUG_MODE
#include <cstdio>

int N, M;
int map[1000][1000];
int dp[1000][1000][2];

void readInput() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
}

inline int max(const int &a, const int &b) {
    return a > b ? a : b;
}

int main() {
    // freopen("input.txt", "r", stdin);
    readInput();
    dp[0][0][0] = map[0][0];
    for (int c = 1; c < M; ++c) {
        dp[0][c][0] = map[0][c] + dp[0][c - 1][0];
    }
    for (int r = 1; r < N; ++r) {
        dp[r][0][0] = map[r][0] + dp[r - 1][0][0];
        for (int c = 1; c < M; ++c) {
            dp[r][c][0] = map[r][c] + max(dp[r - 1][c][0], dp[r][c - 1][0]);
        }
        dp[r][M - 1][1] = map[r][M - 1] + dp[r - 1][M - 1][0];
        for (int c = M - 2; 0 <= c; --c) {
            dp[r][c][1] = map[r][c] + max(dp[r - 1][c][0], dp[r][c + 1][1]);
        }
        for (int c = 0; c < M; ++c) {
            dp[r][c][0] = max(dp[r][c][0], dp[r][c][1]);
        }
    }
    printf("%d", dp[N - 1][M - 1][0]);
    return 0;
}
