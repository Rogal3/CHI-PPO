#include <iostream>
#include <cstring>

enum {MAX_SIZE = 50, MAX_K = 6, k_INT_MAX = 0x7FFFFFFF};

struct Tweak {
    int r, c, l;
};

int N, M, K;
int map[MAX_SIZE][MAX_SIZE];
Tweak t[MAX_K];
int ans = k_INT_MAX;

inline int getDistance(const int &__r1, const int &__c1, const int &__r2, const int &__c2) {
	return abs(__r1 - __r2) + abs(__c1 -  __c2);
}

/*
@param  __map 변경할 맵. 미리 memcpy해놓은 copy_map
@param  __r   왜곡이 일어날 중심의 행수
@param  __c   왜곡이 일어날 중심의 열수
@param  __l   왜곡의 범위
*/
inline void tweaks(int __map[][MAX_SIZE], const int &__r, const int &__c, const int &__l) {
    // 방향은 아래, 오른쪽, 위, 왼쪽으로 반시계로 가면서 당겨줌 == 시계로 밀림.
    const int dr[] = {1, 0, -1, 0};
    const int dc[] = {0, 1, 0, -1};
    for (int l = __l; 0 < l; --l) {
        int cr = __r - l;
        int cc = __c - l;
        // 최초의 하나는 tmp로 옮겨야함
        int tmp = __map[cr][cc];
        int nr, nc;
        // 네 방향 반복.
        for (int d = 0; d < 4; ++d) {
			while (true) {
				nr = cr + dr[d];
				nc = cc + dc[d];
				if (l << 1 < getDistance(__r, __c, nr, nc)) {
					break;
				}
				__map[cr][cc] = __map[nr][nc];
				cr = nr;
				cc = nc;
			}
			
        }
        __map[cr][cc + 1] = tmp;
    }
}

inline int min(const int &__a, const int &__b) {
    return __a < __b ? __a : __b;
}

inline int findMin(const int __map[][MAX_SIZE], const int &__N, const int &__M) {
    int ret = k_INT_MAX;
    for (int r = 0; r < __N; ++r) {
        int sum_r = 0;
        for (int c = 0; c < __M; ++c) {
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
        int n_map[MAX_SIZE][MAX_SIZE];
        // 시험에서는 memcpy를 생각못하고 이중 포문 썼음.
        memcpy(n_map, map, MAX_SIZE * MAX_SIZE * sizeof(int));
        for (int k = 0; k < K; ++k) {
			tweaks(n_map, t[__p[k]].r, t[__p[k]].c, t[__p[k]].l);
        }
        ans = min(ans, findMin(n_map, N, M));
    } else {
        for (int i = 0; i < K; ++i) {
            if (!__check_p[i]) {
                __p[__depth] = i;
                __check_p[i] = true;
                permutate(__depth + 1, __p, __check_p);
                __check_p[i] = false;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	// freopen("input.txt", "r", stdin);
	std::cin >> N >> M >> K;
	for (int r = 0; r < N; ++r) for (int c = 0; c < M; ++c) {
		std::cin >> map[r][c];
	}
	for (int k = 0; k < K; ++k) {
		int r, c, l;
		std::cin >> r >> c >> t[k].l;
		t[k].r = r - 1;
		t[k].c = c - 1;
	}
	int p[MAX_K];
	bool check_p[MAX_K] = {};
	permutate(0, p, check_p);
	std::cout << ans;
    return 0;
}
