#include <cstdio>

struct pii {
    int r;
    int c;
    pii() : r(0), c(0) {}
    pii(const int &__r, const int &__c) : r(__r), c(__c) {}
};
typedef pii Pos;

const int dr[] = {1, 0};
const int dc[] = {0, 1};

int used_tiles;
int map[10][10];
bool tile[10][10];
int TC;
int max_tile;

void init() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            map[i][j] = 0;
            tile[i][j] = 0;
        }
    }
}

bool readInput() {
    scanf("%d", &used_tiles);
    if (used_tiles == 0)
        return true;
    int a, b;
    char ar, ac, br, bc;
    for (int i = 0; i < used_tiles; ++i) {
        scanf("%d %c%c %d %c%c", &a, &ar, &ac, &b, &br, &bc);
        tile[a][b] = true;
        tile[b][a] = true;
        map[ar - 'A' + 1][ac - '0'] = a;
        map[br - 'A' + 1][bc - '0'] = b;
    }
    getchar();
    for (int i = 1; i <= 9; ++i) {
        scanf("%c%c", &ar, &ac);
        map[ar - 'A' + 1][ac - '0'] = i;
        getchar();
    }
    return false;
}

void writeOutput(const int &__tc, const int __map[][10]) {
    printf("Puzzle %d\n", __tc);
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            putchar(__map[i][j] + '0');
        }
        putchar('\n');
    }
}

/* return possible numbers at __pos by bitmasking */
int canExist(const Pos &__pos, const int __map[][10]) {
    int ret = 0x000003FE;
    for (int cr = 1; cr <= 9; ++cr) {
        ret &= ~(1 << __map[cr][__pos.c]);
    }
    for (int cc = 1; cc <= 9; ++cc) {
        ret &= ~(1 << __map[__pos.r][cc]);
    }
    // __pos           == 123 456 789
    // __pos - 1       == 012 345 678
    // (__pos - 1) / 3 == 000 111 222
    Pos district((__pos.r - 1) / 3 * 3, (__pos.c - 1) / 3 * 3);
    for (int r_off = 1; r_off <= 3; ++r_off) {
        for (int c_off = 1; c_off <= 3; ++c_off) {
            ret &= ~(1 << __map[district.r + r_off][district.c + c_off]);
        }
    }
    return ret;
}

inline Pos nextPos(const Pos &__pos, const int __map[][10]) {
    int c = __pos.c + 1;
    for (int r = __pos.r; r <= 9; ++r) {
        for (; c <= 9; ++c) {
            if (__map[r][c] == 0)
                return Pos(r, c);
        }
        c = 1;
    }
    return Pos();
}

bool dfs(const Pos &__pos, const bool __tile[][10], int _map[][10]) {
    if (36 <= used_tiles)
        return true;
    int first = canExist(__pos, _map);
    for (int f = 1; f <= 9; ++f) {
        if (first & 1 << f) {
            for (int d = 0; d < 2; ++d) {
                Pos side(__pos.r + dr[d], __pos.c + dc[d]);
                if (side.r <= 9 && side.c <= 9 && map[side.r][side.c] == 0) {
                    int second = canExist(side, _map);
                    for (int s = 1; s <= 9; ++s) {
                        if (f != s && second & 1 << s && tile[f][s] == false) {
                            tile[f][s] = true;
                            tile[s][f] = true;
                            ++used_tiles;
                            _map[__pos.r][__pos.c] = f;
                            _map[side.r][side.c] = s;
                            if (dfs(nextPos(__pos, _map), __tile, _map)) {
                                return true;
                            }
                            tile[f][s] = false;
                            tile[s][f] = false;
                            --used_tiles;
                            _map[__pos.r][__pos.c] = 0;
                            _map[side.r][side.c] = 0;
                        }
                    }
                }
            }
        }
    }
    return false;
}



int main() {
    // freopen("input.txt", "r", stdin);
    while (!readInput()) {
        dfs(nextPos(Pos(1, 0), map), tile, map);
        writeOutput(++TC, map);
        init();
    }
    return 0;
}
