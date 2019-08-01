#include <iostream>
#include <cstring>
using namespace std;
void dfsFin(int paper[10][10], int curCnt, int curLeft, int colorP[5]);

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

	dfsFin(paper, 0, leftPaper, colorP);

	if (cnt != 3200) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
	getchar();
	getchar();
}
void dfsFin(int paper[10][10], int curCnt, int curLeft, int colorP[5]) {
	if (curCnt > cnt)return;//종이수 많으면 포기
	if (curLeft <= 0) {//모두 붙였다면
		if (curCnt < cnt) {
			
			cnt = curCnt;
		}
	}
	int x, y,t;

	for (y=0; y < 10; ++y) {
		t = 0;
		for (x = 0; x < 10; ++x) {
			if (paper[y][x] == 1) {
				t = 1;
				break;
			}
		}
		if (t==1)break;
	}
	//cout << "x=" << x << " y=" << y<<" "<<paper[y][x] << endl;
	for (int bang = 5; bang > 0; --bang) {
		if (colorP[bang - 1] > 0) {
			bool che = true;
			for (int i = 0; i < bang; ++i) {
				if (i + y >= 10) {
					che = false;
					break;
				}
				for (int j = 0; j < bang; ++j) {
					if (j + x >= 10) {
						che = false;
						break;
					}
					if (paper[y + i][x + j] == 0) {
						che = false; break;
					}
				}
			}

			if (che) {
				int newPaper[10][10] = { 0, };
				int newColorP[5] = { 0, };
				memcpy(newPaper, paper, 10 * 10 * sizeof(int));
				memcpy(newColorP, colorP, 5 * sizeof(int));
				for (int i = 0; i < bang; ++i) {
					//if (i + y >= 10)break;
					for (int j = 0; j < bang; ++j) {
						//if (j + x >= 10)break;
						newPaper[y+i][x+j] = 0;
					}
				}
				newColorP[bang - 1]--;
				dfsFin(newPaper, curCnt + 1, curLeft - (bang*bang),newColorP );
			}
		}
	}

}
