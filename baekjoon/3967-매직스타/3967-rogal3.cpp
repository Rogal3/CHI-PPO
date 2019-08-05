#include <cstdio>

const int LINES[][4] = {
    {0, 2, 5, 7},
    {7, 8, 9, 10},
    {10, 6, 3, 0},
    {1, 5, 8, 11},
    {11, 9, 6, 4},
    {4, 3, 2, 1}
};
const char ANS[] = 
    "....c....\n"
    ".c.c.c.c.\n"
    "..c...c..\n"
    ".c.c.c.c.\n"
    "....c....\n";
int stars[12];

void readInput() {
    int iter = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c = getchar();
            if (c == 'x') {
                ++iter;
            } else if (c != '.') {
                stars[iter++] = c - 'A' + 1;
            }
        }
        getchar();
    }
}

void writeOutput() {
    int idx = 0;
    for (int i = 0; i < sizeof(ANS) - 1; ++i) {
        if (ANS[i] == 'c')
            putchar(stars[idx++] + 'A' - 1);
        else
            putchar(ANS[i]);
    }
}

bool dfs(int idx, int stars[], bool chk_stars[]) {
    while (stars[idx] != 0 && idx < 12) {
        ++idx;
    }
    if (12 <= idx) {
        int sum = 0;
        for (int j = 0; j < 4; ++j)
            sum += stars[LINES[0][j]];
        for (int i = 1; i < 6; ++i) {
            int n_sum = 0;
            for (int j = 0; j < 4; ++j) {
                n_sum += stars[LINES[i][j]];
            }
            if (sum != n_sum)
                return false;
        }
        return true;
    }
    for (int i = 1; i <= 12; ++i) {
        if (chk_stars[i] == false) {
            chk_stars[i] = true;
            stars[idx] = i;
            if (dfs(idx + 1, stars, chk_stars)) {
                return true;
            }
            chk_stars[i] = false;
            stars[idx] = 0;
        }
    }
    return false;
}

void solve() {
    bool chk_stars[13] = {};
    for (int i = 0; i < 12; ++i) {
        chk_stars[stars[i]] = true;
    }
    dfs(0, stars, chk_stars);
}



int main() {
    readInput();
    solve();
    writeOutput();
    return 0;
}
