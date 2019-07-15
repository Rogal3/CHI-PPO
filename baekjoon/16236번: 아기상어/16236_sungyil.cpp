#include <iostream>
#include <queue>
using namespace std;
void check(int x, int y, int ex, int ey);

int n[20][20] = { 0, };
int age = 2;
int eatTime = 0;
int sx, sy;
int cnt;
int x;
queue<pair<int, int>> q;

int main() {

	cin >> x;

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			cin >> n[i][j];
			if (n[i][j] == 9) {
				sx = i;
				sy = j;
				n[i][j] = -1;
			}
			else if (n[i][j] < age&&n[i][j]>0) {
				q.push(make_pair(i, j));
			}
		}
	}

	int checkAge = 0;
	while (1) {
		int tempTime = 1000;
		pair<int, int > emp;
		int size = q.size();
		int fin = 1000;

		while (!q.empty()) {
			cnt = 1000;
			int ex = q.front().first;
			int ey = q.front().second;
			check(sx, sy, ex, ey);
			if (tempTime > cnt) {//cnt가 기존 경로보다 작다면
				tempTime = cnt;
				emp.first = ex;
				emp.second = ey;
			}
			q.pop();
		}

		if (tempTime == 1000) {//암것도 못먹음
			break;
		}
		eatTime += tempTime;//잡아묵었으니 총시간에 추가
		n[emp.first][emp.second] = -1;//잡아먹었으니 그자리에 sx,sy 

		checkAge++;
		if (checkAge >= age) {//나이만큼 잡아묵었으면 나이증가
			checkAge = 0;
			age++;
		}
		sx = emp.first;
		sy = emp.second;

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				if (q.size() > 7)break;
				if (n[i][j] > 0 && n[i][j] < age) {
					q.push(make_pair(i, j));;
				}
			}
		}

	}
	cout << eatTime << endl;
	getchar();
	getchar();
}
void check(int sx, int sy, int ex, int ey) {
	queue<pair<int, int>> temp;
	int ans = 0;
	int c[20][20] = { 0, };
	temp.push(make_pair(sx, sy));

	while (!temp.empty()) {
		int siz = temp.size();
		for (int i = 0; i < siz; ++i) {
			int tx = temp.front().first;
			int ty = temp.front().second;
			if (n[tx][ty] > age) {
				temp.pop();
				continue;
			}
			c[tx][ty] = 1;
			temp.pop();

			if (tx == ex && ty == ey) {
				cnt = ans;
				return;
			}
			if (tx - 1 >= 0) {
				if ( c[tx - 1][ty] == 0) {
					temp.push(make_pair(tx - 1, ty));
				}
			}
			if (tx + 1 < x) {
				if ( c[tx + 1][ty] == 0) {
					temp.push(make_pair(tx + 1, ty));
				}
			}
			if (ty - 1 >= 0) {
				if ( c[tx][ty - 1] == 0) {
					temp.push(make_pair(tx, ty - 1));
				}
			}
			if (ty + 1 < x) {
				if ( c[tx][ty + 1] == 0) {
					temp.push(make_pair(tx, ty + 1));
				}
			}
		}
		ans++;
	}
}