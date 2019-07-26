//  https://www.acmicpc.net/problem/16637
//  author : Rogal3

#include<cstdio>

int N;
int num_arr[10];
char op_arr[9];
int now;
int ans = 0x80000000;

void readInput() {
    scanf("%d", &N);
    for (int i = 0; i < N / 2; ++i) {
        scanf("%d %c", &num_arr[i], &op_arr[i]);
    }
    scanf("%d", &num_arr[N / 2]);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int oper(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

void dfs(int last_idx) {
    if (last_idx == N / 2) {
        ans = max(ans, now);
        return;
    }
    int tmp = now;
    now = oper(now, num_arr[last_idx + 1], op_arr[last_idx]);
    dfs(last_idx + 1);
    now = tmp;
    if (last_idx + 2 <= N / 2) {
        now = oper(now, oper(num_arr[last_idx + 1], num_arr[last_idx + 2], op_arr[last_idx + 1]), op_arr[last_idx]);
        dfs(last_idx + 2);
        now = tmp;
    }
}

int main() {
    readInput();
    now = num_arr[0];
    dfs(0);
    printf("%d", ans);
    return 0;
}
