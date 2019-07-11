#include <stdio.h>
#define eachCoord(V) for (int V = 1; V <= N; ++V)
#define foreach(V, MAX, ADD) for (int V = 1; V <= MAX; v += ADD)

const int N_MAX = 10;
const int AGE_MAX = 200;
const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N;
int M;
int K;
int feedMap[N_MAX + 1][N_MAX + 1];
int feedBufferMap[N_MAX + 1][N_MAX + 1];
int feedingMap[N_MAX + 1][N_MAX + 1];
int treeMap[N_MAX + 1][N_MAX + 1][AGE_MAX + 1];
int treeBufferMap[N_MAX + 1][N_MAX + 1][AGE_MAX + 1];
int trees;

int birth, die;

void readInput() {
    scanf("%d %d %d", &N, &M, &K);
    eachCoord(r) {
        eachCoord(c) {
            scanf("%d", &feedingMap[r][c]);
        }
    }
    int x, y, z;
    while (M--) {
        scanf("%d %d %d", &x, &y, &z);
        ++treeMap[x][y][z];
        ++trees;
    }
    eachCoord(r) {
        eachCoord(c) {
            feedMap[r][c] = 5;
        }
    }
}

void spring() {
    eachCoord(r) {
        eachCoord(c) {
            for (int z = 1; z <= AGE_MAX; ++z) {
                int& tree = treeMap[r][c][z];
                int& feed = feedMap[r][c];
                while (tree) {
                    if (feed >= z) {
                        ++treeBufferMap[r][c][z + 1];
                        feed -= z;
                    } else {
                        feedBufferMap[r][c] += z / 2;
                        --trees;
                        ++die;  // for debug
                    }
                    --tree;
                }
            }
        }
    }
    eachCoord(r) {
        eachCoord(c) {
            for (int z = 1; z <= AGE_MAX; ++z) {
                treeMap[r][c][z] += treeBufferMap[r][c][z];
                treeBufferMap[r][c][z] = 0;
            }
        }
    }
}

void summer() {
    eachCoord(r) {
        eachCoord(c) {
            feedMap[r][c] += feedBufferMap[r][c];
            feedBufferMap[r][c] = 0;
        }
    }
}

inline bool inRange(int r, int c) {
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

void fall() {
    eachCoord(r) {
        eachCoord(c) {
            for (int z = 5; z <= AGE_MAX; z += 5) {
                for (int d = 0; d < 8; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (inRange(nr, nc)) {
                        treeMap[nr][nc][1] += treeMap[r][c][z];
                        trees += treeMap[r][c][z];
                        birth += treeMap[r][c][z];  // for debug
                    }
                }
            }
        }
    }
}

void winter() {
    eachCoord(r) {
        eachCoord(c) {
            feedMap[r][c] += feedingMap[r][c];
        }
    }
}

int main() {
    readInput();
    while (K-- && trees) {
        spring();
        summer();
        fall();
        winter();
        //printf("Left %d years, %d - %d = %d and trees is %d\n", K, birth, die, birth - die, trees);
        birth = die = 0;
    }
    printf("%d", trees);
    return 0;
}

/*

10 1 1000
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
1 1 1


5443

 */
