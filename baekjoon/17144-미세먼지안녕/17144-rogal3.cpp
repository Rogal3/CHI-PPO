// start 7:53 pm
// end   9:05 pm

#include <cstdio>

struct tuple {
    int r;
    int c;
    int dust;
};

inline bool inRange(const int &__r, const int &__c, const int &__R, const int &__C) {
    return 0 <= __r && __r < __R && 0 <= __c && __c < __C;
}

void expand(int __map[][50], const int &__R, const int &__C) {
    const int dr[] = {1, 0, -1, 0};
    const int dc[] = {0, 1, 0, -1};
    tuple s[2500];
    int top = 0;
    for (int r = 0; r < __R; ++r) for (int c = 0; c <__C; ++c) {
        if (0 < __map[r][c]) {
            s[top++] = {r, c, __map[r][c]};
        }
    }
    while (0 < top--) {
        int num_expand = 0;
        int val_expand = s[top].dust / 5;
        for (int d = 0; d < 4; ++d) {
            int nr = s[top].r + dr[d];
            int nc = s[top].c + dc[d];
            if (inRange(nr, nc, __R, __C) && __map[nr][nc] != -1) {
                __map[nr][nc] += val_expand;
                ++num_expand;
            }
        }
        __map[s[top].r][s[top].c] -= num_expand * val_expand;
    }
}

int circulate(int __map[][50], const int &__cleaner_top, const int &__cleaner_bottom, const int &__R, const int &__C) {
    int vaccum = __map[__cleaner_top - 1][0] + __map[__cleaner_bottom + 1][0];
    for (int r = __cleaner_top - 1; 0 < r; --r)
        __map[r][0] = __map[r - 1][0];
    for (int c = 0; c < __C - 1; ++c)
        __map[0][c] = __map[0][c + 1];
    for (int r = 0; r < __cleaner_top; ++r)
        __map[r][__C - 1] = __map[r + 1][__C - 1];
    for (int c = __C - 1; 1 < c; --c)
        __map[__cleaner_top][c] = __map[__cleaner_top][c - 1];
    __map[__cleaner_top][1] = 0;
    for (int r = __cleaner_bottom + 1; r < __R - 1; ++r)
        __map[r][0] = __map[r + 1][0];
    for (int c = 0; c < __C - 1; c++)
        __map[__R - 1][c] = __map[__R - 1][c + 1];
    for (int r = __R - 1; __cleaner_bottom < r; --r)
        __map[r][__C - 1] = __map[r - 1][__C - 1];
    for (int c = __C - 1; 1 < c; --c)
        __map[__cleaner_bottom][c] = __map[__cleaner_bottom][c - 1];
    __map[__cleaner_bottom][1] = 0;
    return vaccum;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int R, C, T;
    int map[50][50];
    int dust = 0;
    int cleaner_top = -1, cleaner_bottom = -1;
    scanf("%d %d %d", &R, &C, &T);
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        scanf("%d", &map[r][c]);
        if (map[r][c] == -1) {
            if (cleaner_top == -1) {
                cleaner_top = r;
            } else {
                cleaner_bottom = r;
            }
        } else {
            dust += map[r][c];
        }
    }
    while (T-- && 0 < dust) {
        expand(map, R, C);
        dust -= circulate(map, cleaner_top, cleaner_bottom, R, C);
    }
    printf("%d", dust);
    return 0;
}
