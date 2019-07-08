#include<stdio.h>
#include<queue>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int R, C;
int map[1000][1000];
int unripe;
int days = -1;

void readInput() {
    scanf("%d %d", &C, &R);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int status;
            scanf("%d", &status);
            map[i][j] = status;
            if (status == 0)
                ++unripe;
        }
    }
}

bool inRange(int r, int c) {
    return 0 <= r && 0 <= c && r < R && c < C;
}

void solve() {
    queue<pair<int,int>> q1, q2;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (map[r][c] == 1) {
                q1.push(pair<int,int>(r, c));
            }
        }
    }
    while (1) {
        if (!q1.empty()) {
            ++days;
            while (!q1.empty()) {
                pair<int,int> coord = q1.front();
                q1.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = coord.first + dr[d];
                    int nc = coord.second + dc[d];
                    if (inRange(nr, nc) && map[nr][nc] == 0) {
                        --unripe;
                        map[nr][nc] = 1;
                        q2.push(pair<int,int>(nr, nc));
                    }
                }
            }
        } else {
            break;
        }
        if (!q2.empty()) {
            ++days;
            while (!q2.empty()) {
                pair<int,int> coord = q2.front();
                q2.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = coord.first + dr[d];
                    int nc = coord.second + dc[d];
                    if (inRange(nr, nc) && map[nr][nc] == 0) {
                        --unripe;
                        map[nr][nc] = 1;
                        q1.push(pair<int,int>(nr, nc));
                    }
                }
            }
        } else {
            break;
        }
    }
}

int main() {
    readInput();
    solve();
    if (unripe == 0) {
        printf("%d", days);
    } else {
        printf("-1");
    }
}
