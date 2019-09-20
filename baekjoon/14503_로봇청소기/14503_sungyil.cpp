#include <iostream>
using namespace std;


typedef struct Robot {
	int x;
	int y;
	int view;
};
void cleaning();
bool turning();


Robot ro;
int n, m;
int cmap[51][51];
int moveX[4] = {0,1,0,-1};
int moveY[4] = {-1,0,1,0};
int ans = 0;
int main() {
	
	cin >> n >> m;
	cin >> ro.y >> ro.x >> ro.view;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cmap[i][j];
		}
	}
	cleaning();
	cout << ans;

	getchar();
	getchar();

}
void cleaning() {

	while (true) {
		if (cmap[ro.y][ro.x] == 0) {//현재위치 청소
			cmap[ro.y][ro.x] = 2;
			ans++;
		}
		bool pan = false;
		for (int i = 0; i < 4; i++) {
			if (turning()) {//왼쪽 청소가능 하면 전진
				pan = true;
				ro.y += moveY[ro.view];
				ro.x += moveX[ro.view];
				break;
			}
		}
		if (pan)continue;//전진했으니까 첨부터
		if (cmap[ro.y - moveY[ro.view]][ro.x - moveX[ro.view]] == 1) {//후진가능?
			break;
		}
		ro.y -= moveY[ro.view];//후진
		ro.x -= moveX[ro.view];
	}
}
bool turning() {
	switch (ro.view) {
	case 0:
		ro.view = 3;
		if (cmap[ro.y + moveY[3]][ro.x + moveX[3]] == 0) {
			return true;
		}
		break;
	case 1:
		ro.view = 0;
		if (cmap[ro.y + moveY[0]][ro.x + moveX[0]] == 0) {
			return true;
		}
		break;
	case 2:
		ro.view = 1;
		if (cmap[ro.y + moveY[1]][ro.x + moveX[1]] == 0) {
			return true;
		}
		break;
	case 3:
		ro.view = 2;
		if (cmap[ro.y + moveY[2]][ro.x + moveX[2]] == 0) {
			return true;
		}
		break;
	}
	return false;
}
