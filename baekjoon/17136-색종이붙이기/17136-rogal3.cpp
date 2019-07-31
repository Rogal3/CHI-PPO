// #define DEBUG_MODE
#include <cstdio>

const int MAP_SIZE = 10;

int input_map[MAP_SIZE][MAP_SIZE];
int num_uncovered;
unsigned num_papers[6];  // [0] is total
unsigned ans = 0xFFFFFFFF;

void readInput() {
    int buf;
    for (int r = 0; r < MAP_SIZE; ++r) {
        for (int c = 0; c < MAP_SIZE; ++c) {
            scanf("%d", &buf);
            if (buf) {
                ++num_uncovered;
                input_map[r][c] = true;
            }
        }
    }
}

inline unsigned min(unsigned a, unsigned b) {
    return a > b ? b : a;
}

void checkSize(int map[][MAP_SIZE], int r) {
    int now;
    for (int cr = MAP_SIZE - 2; r <= cr; --cr) {
        for (int cc = MAP_SIZE - 2; 0 <= cc; --cc) {
            if (map[cr][cc]) {
                now = map[cr + 1][cc + 1];
                now = min(now, map[cr + 1][cc]);
                now = min(now, map[cr][cc + 1]);
                if (4 <= now) {
                    map[cr][cc] = 5;
                } else if (now) {
                    map[cr][cc] = now + 1;
                }
            }
        }
    }
}

void copy(int dst[][MAP_SIZE], const int src[][MAP_SIZE], int r) {
    for (; r < MAP_SIZE; ++r) {
        for (int c = 0; c < MAP_SIZE; ++c) {
            dst[r][c] = src[r][c] ? 1 : 0;
        }
    }
}

void flip(int map[][MAP_SIZE], const int r, const int c, const int size, const bool mode) {
    for (int r_off = 0; r_off < size; ++r_off) {
        for (int c_off = 0; c_off < size; ++c_off) {
            map[r + r_off][c + c_off] = mode;
        }
    }
    num_uncovered += mode ? size * size : -size * size;
}

void dfs(int r, int map[][MAP_SIZE]) {
    if (num_uncovered == 0) {
#ifdef DEBUG_MODE
        if (min(ans, num_papers[0]) == num_papers[0]) 
            printf("best answer == %d\n", num_papers[0]);
#endif
        ans = min(ans, num_papers[0]);
        return;
    }
    if (ans - 1 <= num_papers[0]) {
        return;
    }
    int c;
    bool isfound = false;
    for (; r < MAP_SIZE; ++r) {
        for (c = 0; c < MAP_SIZE; ++c) {
            if (map[r][c]) {
                isfound = true;
                break;
            }
        }
        if (isfound)
            break;
    }
    if (isfound) {
        int n_map[MAP_SIZE][MAP_SIZE];
        copy(n_map, map, r);
        checkSize(n_map, r);
        for (int size = n_map[r][c]; 1 <= size; --size) {
            if (num_papers[size] < 5) {
                ++num_papers[size];
                ++num_papers[0];
                flip(map, r, c, size, false);
                dfs(r, map);
                flip(map, r, c, size, true);
                --num_papers[size];
                --num_papers[0];
            }
        }
    }
#ifdef DEBUG_MODE
    printf("end branch\n");
    {int t = 0;}
#endif
}

int main () {
#ifdef DEBUG_MODE
    freopen("input.txt", "r", stdin);
#endif
    readInput();
    dfs(0, input_map);
    printf("%d", ans);
    return 0;
}
