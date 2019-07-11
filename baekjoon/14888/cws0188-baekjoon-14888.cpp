#include<stdio.h>

int N;
int numArr[11];
int operArr[4];
int depth;
int ans;
int ansMax = 0x80000000;
int ansMin = 0x7FFFFFFF;

void readInput() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &numArr[i]);
    }
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &operArr[i]);
    }
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a > b ? b : a;
}

int operate(int a, int b, int op) {
    switch (op) {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    }
}

void dfs() {
    if (depth == N) {
        ansMax = max(ansMax, ans);
        ansMin = min(ansMin, ans);
        return;
    }
    int tmp = ans;
    for (int op = 0; op < 4; ++op) {
        if (operArr[op]) {
            --operArr[op];
            ans = operate(ans, numArr[depth++], op);
            dfs();
            --depth;
            ans = tmp;
            ++operArr[op];
        }
    }
}

int main() {
    readInput();
    ans = numArr[0];
    depth = 1;
    dfs();
    printf("%d\n%d", ansMax, ansMin);
    return 0;
}
