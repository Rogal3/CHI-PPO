#include <cstdio>
#include <algorithm>

int N, M;
int number_pool[8];

int choose[8];
bool check[8];

void dfs(int depth) {
	if (M <= depth) {
		for (int i = 0; i < depth; ++i) {
			printf("%d ", choose[i]);
		}
		putchar('\n');
	} else {
		for (int index = 0; index < N; ++index) {
			if (!check[index]) {
				check[index] = true;
				choose[depth] = number_pool[index];
				dfs(depth + 1);
				check[index] = false;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int n = 0; n < N; ++n) {
		scanf("%d", &number_pool[n]);
	}
	std::sort(number_pool, number_pool + N);
	dfs(0);
	return 0;
}
