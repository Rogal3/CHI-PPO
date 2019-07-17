#include <iostream>
#include <queue>
using namespace std;
int check();

int n[20][20] = { 0, };
int road[20][20] = { 0, };
int age = 2;
int eatTime = 0;
int sx, sy;
int cnt;
int x;

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
		}
	}

	int checkAge = 0;
	while (1) {
		int tempTime = 1000;

		tempTime=check();

		if (tempTime == 1000) {//암것도 못먹음
			break;
		}
		eatTime += tempTime;//잡아묵었으니 총시간에 추가
		//n[emp.first][emp.second] = -1;//잡아먹었으니 그자리에 sx,sy 

		checkAge++;
		if (checkAge >= age) {//나이만큼 잡아묵었으면 나이증가
			checkAge = 0;
			age++;
		}
		

	}
	cout << eatTime << endl;
	getchar();
	getchar();
}
int check() {
	queue<pair<int, int>> temp;

	int ans = 0;
	int c[20][20] = { 0, };
	int road[20][20] = { 0, };
	temp.push(make_pair(sx, sy));
	c[sx][sy] = 1;
	while (!temp.empty()) {
		int siz = temp.size();
		//cout << "ans : " <<ans<< endl;
		for (int i = 0; i < siz; ++i) {
			int tx = temp.front().first;
			int ty = temp.front().second;

			temp.pop();
			if (n[tx][ty] > age) {
				continue;
			}
			else if (n[tx][ty] < age&&n[tx][ty]>0) {
				
				for (int z = i + 1; z < siz; ++z) {
					if (n[temp.front().first][temp.front().second] < age&&n[temp.front().first][temp.front().second] > 0){
						//cout << "x : " << temp.front().first << " y : " << temp.front().second << " " << road[temp.front().first][temp.front().second] << endl;
						if (tx > temp.front().first) {
							tx = temp.front().first;
							ty = temp.front().second;
						}
						else if (tx == temp.front().first) {
							if (ty > temp.front().second) {
								tx = temp.front().first;
								ty = temp.front().second;
							}
						}
					}
					temp.pop();
				}

				n[sx][sy] = 0;
				sx = tx;
				sy = ty;
				n[tx][ty] = -1;
				return ans;
			}
			
			
			if (tx - 1 >= 0) {
				if (c[tx - 1][ty] == 0) {
					c[tx-1][ty] = 1;
					temp.push(make_pair(tx - 1, ty));
					road[tx - 1][ty] = ans+1;
				}
			}
			
			
			if (ty - 1 >= 0) {
				if (c[tx][ty - 1] == 0) {
					c[tx][ty-1] = 1;
					temp.push(make_pair(tx, ty - 1));
					road[tx][ty - 1] = ans + 1;
				}
			}
			if (ty + 1 < x) {
				if (c[tx][ty + 1] == 0) {

					c[tx][ty+1] = 1;
					temp.push(make_pair(tx, ty + 1));
					road[tx][ty + 1] = ans + 1;
				}
			}
			if (tx + 1 < x) {
				if (c[tx + 1][ty] == 0) {
					c[tx +1][ty] = 1;
					temp.push(make_pair(tx + 1, ty));
					road[tx + 1][ty] = ans + 1;
				}
			}
			
		}
		ans++;
	}
	return 1000;
}
