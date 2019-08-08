// start 4:48 pm
// end   7:37 pm

#include <cstdio>
#include <queue>
#include <algorithm>

enum {kINT_MAX = 0x7FFFFFFF};
typedef std::pair<int, int> Pos;
const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
int M;
int map[50][50];
int num_virus;
int virus[10][50][50];
int ans = kINT_MAX;

void readInput() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        scanf("%d", &map[i][j]);
    }
}

inline bool inRange(const Pos &__pos, const int &__N) {
    return 0 <= __pos.first && __pos.first < __N && 0 <= __pos.second && __pos.second < __N;
}

void bfs() {
    std::queue<Pos> q;
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
        if (map[r][c] == 2) {
            for (int cr = 0; cr < N; ++cr) for (int cc = 0; cc < N; ++cc) {
                virus[num_virus][cr][cc] = kINT_MAX;
            }
            int time = 0;
            q.push(Pos(r, c));
            virus[num_virus][r][c] = time;
            while (!q.empty()) {
                ++time;
                for (int left_elem = q.size(); 0 < left_elem; --left_elem) {
                    Pos now(q.front());
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        Pos next(now.first + dr[d], now.second + dc[d]);
                        if (inRange(next, N) && virus[num_virus][next.first][next.second] == kINT_MAX && map[next.first][next.second] != 1) {
                            q.push(next);
                            virus[num_virus][next.first][next.second] = time;
                        }
                    }
                }
            }
            ++num_virus;
        }
    }
}

void dfs(const int &__last_idx, const int &__depth, int __virus[]) {
    if (M <= __depth) {
        int max_time = 0;
        for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
            if (map[r][c] == 0) {
                int min_dist = kINT_MAX;
                for (int v = 0; v < M; ++v) {
                    min_dist = std::min(min_dist, virus[__virus[v]][r][c]);
                }
                if (min_dist == kINT_MAX) {
                    int t = 0;
                    return;
                }
                max_time = std::max(max_time, min_dist);
            }
        }
        ans = std::min(ans, max_time);
    } else {
        for (int i = __last_idx; i <= num_virus - (M - __depth); ++i) {
            __virus[__depth] = i;
            dfs(i + 1, __depth + 1, __virus);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    readInput();
    bfs();
    int virus_idx[10];
    dfs(0, 0, virus_idx);
    printf("%d", ans != kINT_MAX ? ans : -1);
    return 0;
}
