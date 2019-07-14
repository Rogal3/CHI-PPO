#include<stdio.h>

const int dr[] = {-1, 0, 0 , 1};
const int dc[] = {0, -1, 1, 0};
const int N_MAX = 20;
const int CANT_FOUND = 0x7FFFFFFF;
struct e {
    int r;
    int c;
    int t;
};

int N;
int map[N_MAX][N_MAX];
e q[N_MAX * N_MAX];
int front;
int back;
bool visited[N_MAX][N_MAX];
e baby;
int sharkSize = 2;
int sharkSatiety = 0;
e dst;

void readInput() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                map[i][j] = 0;
                baby.r = i;
                baby.c = j;
                baby.t = 0;
            }
        }
    }
}

inline bool inRange(int r, int c) {
    return 0 <= r && 0 <= c && r < N && c < N;
}

e& better(e& lhs, e& rhs) {
    if (lhs.t < rhs.t) return lhs;
    else if (lhs.t == rhs.t) {
        if (lhs.r < rhs.r) return lhs;
        else if (lhs.r == rhs.r) {
            if (lhs.c < rhs.c) return lhs;
        }
    }
    return rhs;
}

void bfs() {
    dst = {0, 0, CANT_FOUND};
    q[back++] = baby;
    visited[baby.r][baby.c] = true;
    e current;
    bool found = false;
    while (front != back) {
        current = q[front++];
        if (map[current.r][current.c] && map[current.r][current.c] < sharkSize) {
            found = true;
            dst = better(dst, current);
        }
        if (!found) {
            int nt = current.t + 1;
            for (int d = 0; d < 4; ++d) {
                int nr = current.r + dr[d];
                int nc = current.c + dc[d];
                if (inRange(nr, nc) && !visited[nr][nc] && map[nr][nc] <= sharkSize) {
                    q[back++] = {nr, nc, nt};
                    visited[nr][nc] = true;
                }
            } 
        }
    }
}

void initBfs() {
    front = back = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = false;
        }
    }
}
/*
int phase;
void printForDebug() {
    printf("\n#%d PHASE\n", ++phase);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (baby.r == i && baby.c == j) putchar('S');
            else if (dst.r == i && dst.c == j) putchar('F');
            else putchar(map[i][j] + '0');
            putchar(' ');
        }
        putchar('\n');
    }
    printf("(%2d, %2d, %2d) -> (%2d, %2d, %2d), moves: %2d, size: %2d, Sat: %2d\n", baby.r, baby.c, baby.t, dst.r, dst.c, dst.t, dst.t - baby.t, sharkSize, sharkSatiety); // for debug
}
*/
int main() {
    readInput();
    bfs();
    while (dst.t != CANT_FOUND) {
        if (map[dst.r][dst.c] < sharkSize) {
            map[dst.r][dst.c] = 0;
            if (++sharkSatiety == sharkSize) {
                ++sharkSize;
                sharkSatiety = 0;
            }
        }
        //printForDebug();
        baby = dst;
        initBfs();
        bfs();
    }
    printf("%d", baby.t);
    return 0;
}
