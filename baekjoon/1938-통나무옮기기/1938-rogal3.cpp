#include <cstdio>
#include <queue>

enum {
    HORI, VERT
};

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct Pos {
    int r;
    int c;
    int s;
    Pos() : r(-1), c(-1), s(-1) {}
    Pos(const int &_r, const int &_c, const int &_s) : r(_r), c(_c), s(_s) {}
};

int N;
char map[50][50];
Pos B;
Pos E;
bool visited[50][50][2];
int ans;

void readInput() {
    scanf("%d", &N);
    Pos first_B;
    Pos first_E;
    for (int i = 0; i < N; ++i) {
        getchar();
        for (int j = 0; j < N; ++j) {
            char &now = map[i][j];
            scanf("%c", &now);
            if (now == 'B') {
                if (first_B.r == -1) {
                    first_B.r = i;
                    first_B.c = j;
                } else if (B.s == -1) {
                    B.r = i;
                    B.c = j;
                    B.s = i == first_B.r + 1 ? VERT : HORI;
                }
                now = '0';
            }
            if (now == 'E') {
                if (first_E.r == -1) {
                    first_E.r = i;
                    first_E.c = j;
                } else if (E.s == -1) {
                    E.r = i;
                    E.c = j;
                    E.s = i == first_E.r + 1 ? VERT : HORI;
                }
                now = '0';
            }
        }
    }
}

inline bool inRange(const Pos &pos, const int &N) {
    if(pos.s) {
        return 0 <= pos.r - 1 && pos.r + 1 < N && 0 <= pos.c && pos.c < N;
    } else {
        return 0 <= pos.r && pos.r < N && 0 <= pos.c - 1 && pos.c + 1 < N;
    }
}

inline bool canPlaced(const Pos &pos, const char map[][50]) {
    return pos.s ?
        map[pos.r - 1][pos.c] == '0' && map[pos.r][pos.c] == '0' && map[pos.r + 1][pos.c] == '0' : 
        map[pos.r][pos.c - 1] == '0' && map[pos.r][pos.c] == '0' && map[pos.r][pos.c + 1] == '0';
}

inline bool canRotate(const Pos &pos, const char map[][50], const int &N) {
    if (0 == pos.r || pos.r == N - 1 || 0 == pos.c || pos.c == N - 1)
        return false;
    for (int r_off = -1; r_off <= 1; ++r_off) {
        for (int c_off = -1; c_off <= 1; ++c_off) {
            if (map[pos.r + r_off][pos.c + c_off] == '1')
                return false;
        }
    }
    return true;
}

inline Pos getNext(const Pos &current, const int &dir) {
    return Pos(current.r + dr[dir], current.c + dc[dir], current.s);
}

void bfs() {
    int time = 0;
    std::queue<Pos> q;
    visited[B.r][B.c][B.s] = true;
    q.push(B);
    while (!q.empty()) {
        for (int count_time = q.size(); 0 < count_time; --count_time) {
            Pos now(q.front());
            q.pop();
            if (now.r == E.r && now.c == E.c && now.s == E.s) {
                ans = time;
                return;
            }
            for (int d = 0; d < 4; ++d) {
                Pos next(getNext(now, d));
                if (inRange(next, N) && visited[next.r][next.c][next.s] == false && canPlaced(next, map)) {
                    visited[next.r][next.c][next.s] = true;
                    q.push(next);
                }
            }
            Pos next(now);
            next.s = !now.s;
            if (visited[next.r][next.c][next.s] == false && canRotate(next, map, N)) {
                visited[next.r][next.c][next.s] = true;
                q.push(next);
            }
        }
        ++time;
    }
}

int main() {
    readInput();
    bfs();
    printf("%d", ans);
    return 0;
}
