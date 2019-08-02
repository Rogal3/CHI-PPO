#include <cstdio>

enum {
    N_MAX = 16,
    HORI = 0,
    VERT = 1,
    DIAG = 2
};

int main() {
    int map[N_MAX][N_MAX];
    int dp[N_MAX][N_MAX][3] = {};
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &map[r][c]);
        }
    }
    dp[0][1][HORI] = 1;
    for (int c = 2; c < N; ++c) {
        if (map[0][c] == 0)
            dp[0][c][HORI] = dp[0][c - 1][HORI];
    }
    if (!(map[1][2] || map[0][2] || map[1][1]))
        dp[1][2][DIAG] = dp[0][1][HORI];
    for (int r = 1; r < N; ++r) {
        for (int c = 2; c < N; ++c) {
            if (map[r][c] == 0) {
                dp[r][c][HORI] = dp[r][c - 1][HORI] + dp[r][c - 1][DIAG];
                dp[r][c][VERT] = dp[r - 1][c][VERT] + dp[r - 1][c][DIAG];
                if (!(map[r - 1][c] || map[r][c - 1]))
                    dp[r][c][DIAG] = dp[r - 1][c - 1][HORI] + dp[r - 1][c - 1][VERT] + dp[r - 1][c - 1][DIAG];
            }
        }
    }
    printf("%d", dp[N - 1][N - 1][HORI] + dp[N - 1][N - 1][VERT] + dp[N - 1][N - 1][DIAG]);
    return 0;
}
