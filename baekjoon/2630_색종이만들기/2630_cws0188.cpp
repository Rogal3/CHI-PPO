#include<cstdio>

const int N_MAX = 128;
enum COLOR { MIXED = -1, WHITE, BLUE };

int N;
int map[N_MAX][N_MAX];
int num_white;
int num_blue;

void ReadInput() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
}

int Recursion(int baseY, int baseX, int size) {
    if (size > 1) {
        int half = size / 2;
        int merge[4];
        merge[0] = Recursion(baseY       , baseX       , half);
        merge[1] = Recursion(baseY       , baseX + half, half);
        merge[2] = Recursion(baseY + half, baseX       , half);
        merge[3] = Recursion(baseY + half, baseX + half, half);
        if (merge[0] == merge[1] &&
            merge[0] == merge[2] &&
            merge[0] == merge[3]) {
            return merge[0];
        } else {
            for (auto color : merge) {
                color == WHITE ? ++num_white : NULL;
                color == BLUE ? ++num_blue : NULL;
            }
            return MIXED;
        }
    }
    return map[baseY][baseX];
}

int main() {
    ReadInput();
    Recursion(0, 0, N);
    printf("%d\n%d", num_white, num_blue);
    return 0;
}
