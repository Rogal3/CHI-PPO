#include <iostream>
using namespace std;
void finds(int bang, int colorSize);

int paper[10][10] = { 0, };
int colorP[5] = { 5,5,5,5,5 };
int leftPaper = 0;
int cnt = 0;
int main() {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; ++j) {
			cin >> paper[i][j];
			if (paper[i][j] == 1)leftPaper++;
		}
	}

	for (int i = 0; i < 5; i++) {
		finds(i, 5 - i);
	}
	if (leftPaper == 0) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
	getchar();
	getchar();
}
void finds(int bang, int colorSize) {//얘는 무조건 큰애로 시작함. 큰애말고 작은애 부터
	int che = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			if (paper[i][j] == 1&&colorP[bang]!=0) {//덮어야할 종이가 있으면
				che = 0;
				for (int h = 0; h < colorSize; ++h) {//덮을 가로 탐색
					for (int k = 0; k < colorSize; ++k) {
						che += paper[i + h][j + k];
					}
				}
				if (che == colorSize * colorSize) {//다 덮을수 있다면
					for (int h = 0; h < colorSize; ++h) {//덮어 버린다.
						for (int k = 0; k < colorSize; ++k) {
							paper[i + h][j + k]=0;
						}
					}
					cnt++;
					colorP[bang]--;
					leftPaper -= colorSize * colorSize;
				}
			}

		}
	}
}