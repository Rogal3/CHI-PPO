#include <cstdio>
#include <algorithm>

int N, K;
int pool[10];
bool check[10];
int comb[10 * 9 * 8 * 7];
int comb_size;

void readInput() {
	scanf("%d%d", &N, &K);
	for (int n = 0; n < N; ++n) {
		scanf("%d", &pool[n]);
	}
}

void dfs(int _depth, int _sum) {
	if (K <= _depth) {
		for (int i = 0; i < comb_size; ++i) {
			if (comb[i] == _sum)
				return;
		}
		comb[comb_size++] = _sum;
	} else {
		for (int i = 0; i < N; ++i) {
			if (!check[i]) {
				check[i] = true;
				int n_sum = _sum * (10 <= pool[i] ? 100 : 10) + pool[i];
				dfs(_depth + 1, n_sum);
				check[i] = false;
			}
		}
	}
}

int main() {
	readInput();
	dfs(0, 0);
	printf("%d", comb_size);
	return 0;
}
