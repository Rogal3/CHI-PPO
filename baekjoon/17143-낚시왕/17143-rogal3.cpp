#include <cstdio>
#include <cstring>

struct Shark {
    bool exist;
    int s, d, z;
};

int main() {
    // freopen("input.txt", "r", stdin);
    const int dr[] = {0, -1, 1, 0, 0};
    const int dc[] = {0, 0, 0, 1, -1};
    const int rd[] = {0, 2, 1, 4, 3};
    int R, C, M;
    Shark map[101][101] = {};
    scanf("%d%d%d", &R, &C, &M);
    for (int m = 0; m < M; ++m) {
        int r, c;
        scanf("%d%d", &r, &c);
        map[r][c].exist = true;
        scanf("%d%d%d", &map[r][c].s, &map[r][c].d, &map[r][c].z);
        if (map[r][c].d <= 2) {
            map[r][c].s %= 2 * (R - 1);
        } else {
            map[r][c].s %= 2 * (C - 1);
        }
    }
    int capture = 0;
    for (int pos_king = 1; pos_king <= C; ++pos_king) {
        // capture
        for (int r = 1; r <= R; ++r) {
            if (map[r][pos_king].exist) {
                capture += map[r][pos_king].z;
                map[r][pos_king].exist = false;
                break;
            }
        }
        // shark move
        Shark tmp_map[101][101] = {};
        for (int cr = 1; cr <= R; ++cr) for (int cc = 1; cc <= C; ++cc) {
            if (map[cr][cc].exist) {
                int s = map[cr][cc].s;
                int d = map[cr][cc].d;
                int nr = cr, nc = cc;
                while (true) {
                    nr += s * dr[d];
                    nc += s * dc[d];
                    if (nr < 1 || R < nr || nc < 1 || C < nc) {
                        switch (d) {
                            case 1:
                                s = 1 - nr;
                                nr = 1;
                                break;
                            case 2:
                                s = nr - R;
                                nr = R;
                                break;
                            case 3:
                                s = nc - C;
                                nc = C;
                                break;
                            case 4:
                                s = 1 - nc;
                                nc = 1;
                                break;
                        }
                        d = rd[d];
                    } else {
                        break;
                    }
                }
                if (!tmp_map[nr][nc].exist || tmp_map[nr][nc].z < map[cr][cc].z) {
                    tmp_map[nr][nc].exist = true;
                    tmp_map[nr][nc].s = map[cr][cc].s;
                    tmp_map[nr][nc].d = d;
                    tmp_map[nr][nc].z = map[cr][cc].z;
                }

            }
        }
        memcpy(map, tmp_map, 101 * 101 * sizeof(Shark));
    }
    printf("%d", capture);
    return 0;
}
