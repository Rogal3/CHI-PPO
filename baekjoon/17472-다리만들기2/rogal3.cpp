#include <cstdio>
#include <queue>

using namespace std;

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int N, M;
int map[10][10];
int num_island;
int bridge_lengths[7][7];
int min_total = 0x7FFFFFFF;

void readInput() {
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 0) {
                map[r][c] = -1;     // ocean
            } else {
                map[r][c] = 0;      // island
            }
        }
    }
}

void queueing(int r, int c) {
    map[r][c] = num_island;
    queue<pair<int, int> > q;
    pair<int, int> pii = {r, c};
    q.push(pii);
    while (!q.empty()) {
        pii = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            pair<int, int> npii = {pii.first + dr[d], pii.second + dc[d]};
            if (0 <= npii.first && npii.first < N && 0 <= npii.second && npii.second < M) {
                if (map[npii.first][npii.second] == 0) {
                    map[npii.first][npii.second] = num_island;
                    q.push(npii);
                }
            }
        }
    }
}

void numberingIsland() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] == 0) {
                ++num_island;
                queueing(r, c);
            }
        }
    }
}

void findAllBridge() {
    for(int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] != -1) {
                int begin_island = map[r][c];
                for (int d = 0; d < 4; ++d) {
                    int length = 0;
                    int cr = r;
                    int cc = c;
                    while (true) {
                        int nr = cr + dr[d];
                        int nc = cc + dc[d];
                        if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                            if (map[nr][nc] == -1) {        // ocean
                                ++length;
                                cr = nr;
                                cc = nc;
                            } else {                        // island
                                int end_island = map[nr][nc];
                                if (2 <= length && begin_island != end_island) {
                                    if (bridge_lengths[begin_island][end_island] == 0 || length < bridge_lengths[begin_island][end_island]) {
                                        bridge_lengths[begin_island][end_island] = length;
                                        bridge_lengths[end_island][begin_island] = length;
                                    }
                                }
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}

void dfs(bool connected_islands[], int depth, int total_length) {
    if (num_island <= depth) {
        if (total_length < min_total) {
            min_total = total_length;
        }
    } else {
        for (int i = 2; i <= num_island; ++i) {
            if (connected_islands[i] == false) {
                for (int conn_i = 1; conn_i <= num_island; ++conn_i) {
                    if (connected_islands[conn_i] == true && bridge_lengths[i][conn_i] != 0) {
                        connected_islands[i] = true;
                        dfs(connected_islands, depth + 1, total_length + bridge_lengths[i][conn_i]);
                        connected_islands[i] = false;
                    }
                }
            }
        }
    }
}

void findShortcut() {
    for (int i = 1; i <= num_island; ++i) {
        int sum = 0;
        for (int ni = 1; ni <= num_island; ++ni) {
            sum += bridge_lengths[i][ni];
        }
        if (sum == 0) {
            return;
        }
    }
    bool connected_islands[7] = {false, true};
    dfs(connected_islands, 1, 0);
}

int main() {
    readInput();
    numberingIsland();
    findAllBridge();
    findShortcut();
    if (min_total == 0x7FFFFFFF)
        min_total = -1;
    printf("%d", min_total);
    return 0;
}
