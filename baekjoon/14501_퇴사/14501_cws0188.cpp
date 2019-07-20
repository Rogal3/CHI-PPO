#include<iostream>

int N;
int dp[17];
int ans;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t, p;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &t, &p);
        if (i + t <= N + 1) {
            dp[i + t] = max(dp[i + t], dp[i] + p);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    printf("%d", dp[N + 1]);
    return 0;
}
