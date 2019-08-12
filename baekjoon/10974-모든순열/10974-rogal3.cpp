#include <cstdio>

int N;
int arr[8];
bool check[9];

// depth는 깊이 == 고른 숫자의 개수
void dfs(int depth) {
	// 숫자를 충분히 골랐음.
	if (N <= depth) {
		for (int i = 0; i < N; ++i)
			printf("%d ", arr[i]);
		putchar('\n');
	}
	// 숫자를 더 골라야함.
	else {
		for (int n = 1; n <= N; ++n) {
			// n을 아직 안골랐으면 고르자.
			if (!check[n]) {
				check[n] = true;
				// depth번째로 고른 숫자를 저장.
				arr[depth] = n;
				dfs(depth + 1);
				check[n] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	// 깊이(depth)는 항상 0부터 시작.
	dfs(0);
	return 0;
}
