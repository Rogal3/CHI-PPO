#include <iostream>
#include <cstring>

struct Tweak {
    int r, c, l;
};

int N, K;
int map[15][15];
Tweak t[5];
int ans;

/*
@param  __map 변경할 맵. 미리 memcpy해놓은 copy_map
@param  __r   왜곡이 일어날 중심의 행수
@param  __c   왜곡이 일어날 중심의 열수
@param  __l   왜곡의 범위
*/
inline void tweaks(int __map[][15], const int &__r, const int &__c, const int &__l) {
    // 방향은 아래, 오른쪽, 위, 왼쪽으로 반시계로 가면서 당겨줌 == 시계로 밀림.
    const int dr[] = {1, 0, -1, 0};
    const int dc[] = {0, 1, 0, -1};
    // nd[0]  거리 0짜리 시계회전은 없음.
    // nd[1]  거리 1짜리 시계회전시 8개중에 7번은 포문으로 밀고 마지막은 수동으로.
    // nd[2]  거리 2짜리 시계회전시 16개중에 15번은...
    // nd[3]  거리 3짜리 시계회전시 24개...
    const int nd[4][4] = {{}, {2, 2, 2, 1}, {4, 4, 4, 3}, {6, 6, 6, 5}};
    for (int l = __l; 0 < l; --l) {
        int cr = __r - l;
        int cc = __c - l;
        // 최초의 하나는 tmp로 옮겨야함
        int tmp = __map[cr][cc];
        int nr, nc;
        // 네 방향 반복.
        for (int d = 0; d < 4; ++d) {
            // 각 방향마다 반복 횟수는 nd만큼.
            for (int n = nd[l][d]; 0 < n; --n) {
                nr = cr + dr[d];
                nc = cc + dc[d];
                __map[cr][cc] = __map[nc][nc];
                cr = nr;
                cc = nc;
            }
        }
        __map[nr][nc] = tmp;
    }
}

inline int min(const int &__a, const int &__b) {
    return __a < __b ? __a : __b;
}

inline int findMin(const int __map[][15], const int &__N) {
    int ret = 0x7FFFFFFF;
    for (int r = 0; r < __N; ++r) {
        int sum_r = 0;
        for (int c = 0; c < __N; ++c) {
            sum_r += __map[r][c];
        }
        ret = min(ret, sum_r);
    }
    return ret;
}

/*
@param __depth   현재까지 고른 갯수.
@param __p       고른 번호를 저장.
@param __check_p 고른 번호를 중복 체크함.
*/
void permutate(const int &__depth, int __p[], bool __check_p[]) {
    if (K <= __depth) {
        int n_map[15][15];
        // 시험에서는 memcpy를 생각못하고 이중 포문 썼음.
        memcpy(n_map, map, 15 * 15 * sizeof(int));
        for (int k = 0; k < K; ++k) {
            if (__p[k] != -1) {
                tweaks(n_map, t[__p[k]].r, t[__p[k]].c, t[__p[k]].l);
            }
        }
        ans = min(ans, findMin(n_map, N));
    } else {
        for (int i = 0; i < K; ++i) {
            if (!__check_p[i]) {
                __p[__depth] = i;
                __check_p[i] = true;
                permutate(__depth + 1, __p, __check_p);
                __check_p[i] = false;
            }
        }
        __p[__depth] = -1;
        permutate(__depth + 1, __p, __check_p);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int TC;
    std::cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        ans = 0x7FFFFFFF;
        std::cin >> N >> K;
        for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
            std::cin >> map[r][c];
        }
        for (int k = 0; k < K; ++k) {
            std::cin >> t[k].c >> t[k].r >> t[k].l;
        }
        int p[5];
        bool check_p[5] = {};
        permutate(0, p, check_p);
        std::cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}
