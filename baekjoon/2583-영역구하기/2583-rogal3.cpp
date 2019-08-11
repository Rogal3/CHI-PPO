// #define DEBUG
#ifdef DEBUG

#endif

#include <cstdio>
#include <algorithm>

struct Pos {
    int r, c;
};

class queue {
    public:
        queue() : head(), tail() {}
        Pos front() { return con_[head]; }
        void push(const Pos &__e) { con_[tail++] = __e; }
        void pop() { ++head; }
        int size() { return tail - head; }
    private:
        Pos con_[101 * 101];
        int head;
        int tail;
};
#ifdef DEBUG
void print(const int __map[][101], int M, int N) {
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            printf("%d ", __map[r][c]);
        }
        putchar('\n');
    }
    putchar('\n');
}
#endif


int main() {
    int N, M, K;
    int map[101][101] = {};
    scanf("%d%d%d", &M, &N, &K);
    for (int k = 0; k < K; ++k) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &c1, &r1, &c2, &r2);
        for (int cr = r1; cr < r2; ++cr) {
            int t1 = 0;
            for (int cc = c2 - 1; c1 <= cc; --cc) {
                if (cc - 1 < N) {
                    t1 = map[cr][cc + 1];
                }
                map[cr][cc] = t1 + 1;
            }
        }
#ifdef DEBUG
        print(map, M, N);
#endif
    }
    int ans[101 * 101 / 2];
    int ans_size = 0;
    int count_size;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (map[r][c] == 0) {
                queue q;
                q.push({r, c});
                map[r][c] = -1;
                count_size = 1;
                while (q.size()) {
                    int cr = q.front().r;
                    int cc = q.front().c;
                    q.pop();
                    int nr = cr - 1;
                    int nc = cc;
                    if (0 <= nr && map[nr][nc] == 0) {
                        q.push({nr, nc});
                        map[nr][nc] = -1;
                        ++count_size;
                    }
                    nr = cr + 1;
                    if (nr < M && map[nr][nc] == 0) {
                        q.push({nr, nc});
                        map[nr][nc] = -1;
                        ++count_size;
                    }
                    nr = cr;
                    nc = cc - 1;
                    if (0 <= nc && map[nr][nc] == 0) {
                        q.push({nr, nc});
                        map[nr][nc] = -1;
                        ++count_size;
                    }
                    nc = cc + 1;
                    if (nc < N && map[nr][nc] == 0) {
                        q.push({nr, nc});
                        map[nr][nc] = -1;
                        ++count_size;
                    }
                }
                ans[ans_size++] = count_size;
            } else if (0 < map[r][c]) {
                c += map[r][c] - 1;
            }
        }
    }
#ifdef DEBUG
    print(map, M, N);
#endif
    std::sort(ans, ans + ans_size);
    printf("%d\n", ans_size);
    for (int i = 0; i < ans_size; ++i) {
        printf("%d", ans[i]);
        if (i < ans_size - 1) {
            putchar(' ');
        }
    }
    return 0;
}
