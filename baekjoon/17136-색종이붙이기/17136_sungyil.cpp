#include <iostream>
#include <cstring>
using namespace std;
void dfsF(int paper[10][10], int bang, int curCnt, int curLeft, int colorP[5]);

int paper[10][10] = { 0, };
int colorP[5] = { 5,5,5,5,5 };
int leftPaper = 0;
int cnt = 3200;
int main() {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; ++j) {
			cin >> paper[i][j];
			if (paper[i][j] == 1)leftPaper++;
		}
	}

	dfsF(paper,5,0,leftPaper,colorP);

	if (cnt != 3200) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
	getchar();
	getchar();
}
void dfsF(int paper[10][10], int bang, int curCnt, int curLeft,int colorP[5]) {
	if (bang == 0) {//마지막에 다다랏다면

		if (curLeft <= 0) {
			if (cnt > curCnt) {
				
				cnt = curCnt;
			}
		}
		return;
	}
	int newPaper[10][10] = { 0, };
	int newColorP[5] = { 0, };
	memcpy(newPaper, paper, 10 * 10*sizeof(int));
	memcpy(newColorP, colorP, 5*sizeof(int));
	dfsF(newPaper, bang - 1, curCnt, curLeft, newColorP);//현재방에서 0장 덮고나서 다음방.
	for (int i = 0; i < 10; ++i) {//1장씩 증가해서 다음방
		for (int j = 0; j < 10; ++j) {
			
			if (paper[i][j] == 1&&colorP[bang-1]>0) {
				int che = 0;
				for (int h = 0; h <bang; ++h) {//덮을 가로 탐색
					for (int k = 0; k < bang; ++k) {
						che += paper[i + h][j + k];
					}
				}
				if (che == bang * bang) {// 다덮는다면
					for (int h = 0; h < bang; ++h) {//덮어 버린다.
						for (int k = 0; k < bang; ++k) {
							paper[i + h][j + k] = 0;
						}
					}
					curCnt++;
					colorP[bang-1]--;
					curLeft -= bang * bang;
					int newPaper[10][10] = { 0, };
					int newColorP[5] = { 0, };
					memcpy(newPaper, paper, 10 * 10*sizeof(int));
					memcpy(newColorP, colorP, 5*sizeof(int));
					dfsF(newPaper, bang - 1, curCnt, curLeft, newColorP);//큰거 한장 덮었음 ㄱㄱ
				}
			}

		}
	}

}
