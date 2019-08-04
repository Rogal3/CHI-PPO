// solve begin 1:34 am
// end 3:18 am
#include <cstdio>
#include <algorithm>

enum {WEST = 1, NORTH = 2, EAST = 4, SOUTH = 8};
const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int N, M;
bool walls[50][50][4];
int map[50][50];
std::pair<int, int> rooms_size[2500];
int num_rooms;
bool connected[2500][2500];

void readInput() {
    scanf("%d %d", &M, &N);
    int input;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            scanf("%d", &input);
            for (int d = 0; d < 4; ++d) {
                if (input & 1 << d) {
                    walls[r][c][d] = true;
                }
            }
        }
    }
}

inline int inRange(const int &r, const int &c, const int &R, const int &C) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

int dfs(const int &r, const int &c, bool visited[][50], const int &idx, int map[][50]) {
    visited[r][c] = true;
    map[r][c] = idx;
    int sum = 1;
    for (int d = 0; d < 4; ++d) {
        if (walls[r][c][d] == false) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (inRange(nr, nc, N, M) && visited[nr][nc] == false) {
                visited[nr][nc] = true;
                sum += dfs(nr, nc, visited, idx, map);
            }
        }
    }
    return sum;
}

void mapping() {
    bool visited[50][50] = {};
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (visited[r][c] == false) {
                rooms_size[num_rooms].first = dfs(r, c, visited, num_rooms, map);
                rooms_size[num_rooms].second = num_rooms;
                ++num_rooms;
            }
        }
    }
}


void getConnect() {
    for (int r = 1; r < N; ++r) {
        connected[map[r][0]][map[r - 1][0]] = true;
        connected[map[r - 1][0]][map[r][0]] = true;
    }
    for (int c = 1; c < M; ++c) {
        connected[map[0][c]][map[0][c - 1]] = true;
        connected[map[0][c - 1]][map[0][c]] = true;
    }
    for (int r = 1; r < N; ++r) {
        for (int c = 1; c < M; ++c) {
            connected[map[r - 1][c]][map[r][c]] = true;
            connected[map[r][c]][map[r - 1][c]] = true;
            connected[map[r][c - 1]][map[r][c]] = true;
            connected[map[r][c]][map[r][c - 1]] = true;
        }
    }
}

int getMaxPair() {
    int max = 0;
    for (int i = num_rooms - 1; 1 <= i; --i) {
        for (int j = i - 1; 0 <= j; --j) {
            if (connected[rooms_size[i].second][rooms_size[j].second]) {
                max = std::max(max, rooms_size[i].first + rooms_size[j].first);
            }
        }
    }
    return max;
}

int main() {
    readInput();
    mapping();
    printf("%d\n", num_rooms);
    std::sort(rooms_size, rooms_size + num_rooms);
    printf("%d\n", rooms_size[num_rooms - 1].first);
    getConnect();
    printf("%d\n", getMaxPair());
    return 0;
}
