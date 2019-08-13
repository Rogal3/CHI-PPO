#include <iostream>
#include <cstring>
using namespace std;
void find(int x, int y, int pan);
bool cheWall( int x, int y, int pan);

int map[17][17] = { 0, };
int n;
int cnt = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	map[0][0] = 1;
	map[0][1] = 1;

	find( 1, 0, 1);

	cout << cnt << endl;
	getchar();
	getchar();
}
void find(int x,int y,int pan) {//끝점 대각판별
	
	if (x >= n||y>=n)return;

	if (x == n-1) {
		if (y == n-1) {//끝점에 다다랐다면 +1 종료
			cnt++;
			return;
		}
	}
	if (cheWall(x, y, 1)) {//대각놓을수 있는지검
		find( x + 1, y + 1, 3);
	}

	if (pan == 1 || pan == 3) {//이전방 가로 그래서 가로로만 이동
		if (cheWall( x, y, 2)) {
			find( x + 1, y, 1);
		}
	}
	if(pan==2||pan==3) {//세로이동
		if (cheWall( x, y, 3)) {
			find( x, y + 1, 2);
		}
	}
	
}
bool cheWall(int x,int y,int pan) {
	int sum = 0;
	switch (pan) {
	case 1://대각
		sum=map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1];
		break;
	case 2:
		sum = map[y][x+1];
		break;
	case 3:
		sum = map[y+1][x];
	}

	if (sum >= 1) {
		return false;
	}
	return true;
}
