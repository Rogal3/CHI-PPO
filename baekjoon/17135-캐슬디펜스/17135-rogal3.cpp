// #define DEBUG_MODE
#include <cstdio>

const int MAX_SIZE = 15;
const int dr[] = {0, -1, 0};
const int dc[] = {-1, 0, 1};

template<class T>
class queue {
    public:
        queue() : head(0), tail(0) {}
        const T &front() {return con_[head];}
        void push(const T &t) {
            con_[tail++] = t;
        }
        void pop() {
            if (head < tail)
                ++head;
        }
        int size() {return tail - head;}
        void clear() {head = tail = 0;}
    private:
        T con_[MAX_SIZE * MAX_SIZE + 1];
        int head;
        int tail;
};

struct pii {
    int first, second;
    pii() : first(0), second(0) {}
    pii(int _first, int _second) : first(_first), second(_second) {}
};

int N, M, D;
int map[MAX_SIZE][MAX_SIZE];
int enemies;
int max_kill;

void readInput() {
    scanf("%d %d %d", &N, &M, &D);
    int input;
    for (int cr = 0; cr < N; ++cr) {
        for (int cc = 0; cc < M; ++cc) {
            scanf("%d", &input);
            if (input) {
                map[cr][cc] = 1;
                ++enemies;
            }
        }
    }
}

void copy(int dst[][MAX_SIZE], const int src[][MAX_SIZE]) {
    for (int cr = 0; cr < N; ++cr) {
        for (int cc = 0; cc < M; ++cc) {
            dst[cr][cc] = src[cr][cc];
        }
    }
}

int MoveEnemy(int map[][MAX_SIZE], const int r) {
    int through_enemies = 0;
    for (int cc = 0; cc < M; ++cc) {
        if (map[N - 1][cc] == 1) {
            ++through_enemies;
        }
    }
    for (int cr = N - 1; r < cr; --cr) {
        for (int cc = 0; cc < M; ++cc) {
            map[cr][cc] = map[cr - 1][cc];
        }
    }
    for (int cc = 0; cc < M; ++cc) {
        map[r][cc] = 0;
    }
    return through_enemies;
}

inline bool inRange(const pii &coord) {
    return 0 <= coord.first && coord.first < N && 0 <= coord.second && coord.second < M;
}

pii findEnemy(const pii &archer, const int map[][MAX_SIZE]) {
    int cd = 1;
    queue<pii> q;
    bool visited[MAX_SIZE][MAX_SIZE] = {};
    visited[archer.first][archer.second] = true;
    q.push(archer);
    while (q.size()) {
        for (int left_cd = q.size(); 0 < left_cd; --left_cd) {
            pii now(q.front());
            q.pop();
            if (map[now.first][now.second] == 1) {
                return now;
            }
            for (int dir = 0; dir < 3; ++dir) {
                pii next(now.first + dr[dir], now.second + dc[dir]);
                if (inRange(next) && !visited[next.first][next.second]) {
                    visited[next.first][next.second] = true;
                    q.push(next);
                }
            }
        }
        if (D < ++cd)
            break;
    }
    return pii(-1, -1);
}

int simulator(const int archers[], const int map[][MAX_SIZE], int enemies) {
    int killed_enemies = 0;
    int turn = 0;
    int n_map[MAX_SIZE][MAX_SIZE];
    pii found_enemies[3];
    copy(n_map, map);
    while (0 < enemies) {
        for (int ar = 0; ar < 3; ar++) {
            found_enemies[ar] = findEnemy(pii(N - 1, archers[ar]), n_map);
        }
        for (int ar = 0; ar < 3; ar++) {
            if (inRange(found_enemies[ar])) {
                if (n_map[found_enemies[ar].first][found_enemies[ar].second] == 1) {
                    ++killed_enemies;
                    --enemies;
                    n_map[found_enemies[ar].first][found_enemies[ar].second] = 0;
#ifdef DEBUG_MODE
                    n_map[found_enemies[ar].first][found_enemies[ar].second] = 2;
#endif
                }
            }
        }
#ifdef DEBUG_MODE
        printf("#%d\n", turn);
        for (int cr = turn; cr < N; ++cr) {
            for (int cc = 0; cc < M; ++cc) {
                printf("%d ", n_map[cr][cc]);
                if (n_map[cr][cc] == 2)
                    n_map[cr][cc] = 0;
            }
            putchar('\n');
        }
        for (int ar = 0; ar < N; ++ar) {
            printf("%c ", archers[0] == ar || archers[1] == ar || archers[2] == ar ? 'A' : ' ');
        }
        putchar('\n');
        printf("killed enemies == %d\n", killed_enemies);
        printf("left enemies == %d\n\n", enemies);
#endif
        int through_enemies = MoveEnemy(n_map, turn++);
        enemies -= through_enemies;
    }
    return killed_enemies;
}

void dfs(const int last_idx, const int depth, int archers[]) {
    if (3 <= depth) {
        int killed_enemies = simulator(archers, map, enemies);
#ifdef DEBUG_MODE
        printf("three heros killed %2d enemies == ", killed_enemies);
        for (int ar = 0; ar < 3; ++ar) {
            printf("%d, ", archers[ar]);
        }
        printf("\n\n=================================================\n\n");
#endif
        if (max_kill < killed_enemies) {
            max_kill = killed_enemies;
        }
    } else {
        for (int ar = last_idx + 1; ar < M; ++ar) {
            archers[depth] = ar;
            dfs(ar, depth + 1, archers);
        }
    }
}

int main () {
#ifdef DEBUG_MODE
    freopen("input.txt", "r", stdin);
#endif
    readInput();
    int archers[3];
    dfs(-1, 0, archers);
    printf("%d", max_kill);
    return 0;
}
