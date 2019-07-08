#include<stdio.h>

int N;
int M;
bool path[101][101];
bool visited[101];
int ans = -1;

void readInput() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        path[begin][end] = true;
        path[end][begin] = true;
    }
}

void dfs(int index) {
    visited[index] = true;
    ++ans;
    for (int i = 1; i <= N; ++i) {
        if (path[index][i] == true && visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    readInput();
    dfs(1);
    printf("%d", ans);
}
