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
		//pair<int, int > emp;
		int size = q.size();
		int fin = 1000;

		tempTime=check();

		/*while (!q.empty()) {
			cnt = 1000;
			int ex = q.front().first;
			int ey = q.front().second;
			cnt = road[ex][ey]+1;
			if (tempTime > cnt) {//cnt가 기존 경로보다 작다면
				tempTime = cnt;
				emp.first = ex;
				emp.second = ey;
			}
			q.pop();
		}*/


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
		//sx = emp.first;
		//sy = emp.second;
		
		
		/*for (int i = 0; i < x; i++) {
			for (int j = 0; j < x; j++) {
				road[i][j] = 0;
				if (n[i][j] > 0 && n[i][j] < age) {
					q.push(make_pair(i, j));;
				}
			}
		}*/

	}
	cout << eatTime << endl;
	getchar();
	getchar();
}
int check() {
	queue<pair<int, int>> temp;
	queue<pair<int, int>> answer;
	int ans = 0;
	int c[20][20] = { 0, };
	int road[20][20] = { 0, };
	temp.push(make_pair(sx, sy));

	while (!temp.empty()) {
		int siz = temp.size();
		for (int i = 0; i < siz; ++i) {
			int tx = temp.front().first;
			int ty = temp.front().second;
			road[tx][ty] = ans;
			temp.pop();
			if (n[tx][ty] > age) {
				continue;
			}
			/*if (n[tx][ty] < age&&n[tx][ty]>0) {
				answer.push(make_pair(tx, ty));
				for (int z = i + 1; z < siz; ++z) {
					if (n[temp.front().first][temp.front().second] < age) {
						answer.push(make_pair(temp.front().first,temp.front().second));
					}
					temp.pop();
				}
			/*	cout << "==========================이동칸 : " <<ans<<"나이 : "<<age<<"총 시간 : "<<eatTime<<endl;
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < x; j++) {
						if (i == tx && j == ty) {
							cout << "9" << " ";
						}
						else {
							cout << n[i][j] << " ";
						}
					}
					cout << endl;
				}
				cout << endl;
				getchar();
				
				for (int z = i+1; z < siz; ++z) {
					if (n[temp.front().first][temp.front().second] < age) {
						cout << "x = " << temp.front().first << " y= " << temp.front().second << " " <<road[temp.front().first][temp.front().second]<<endl;
					}
					temp.pop();
				}
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < x; j++) {
						cout << road[i][j]<<" ";
					}
					cout << endl;
				}

				n[sx][sy] = 0;
				sx = tx;
				sy = ty;
				n[tx][ty] = -1;
				return ans;*/
			//}
			c[tx][ty] = 1;

			/*if (tx == ex && ty == ey) {
				cnt = ans;
				return;
			}*/
		
			
			
			if (tx - 1 >= 0) {
				if (c[tx - 1][ty] == 0) {
					temp.push(make_pair(tx - 1, ty));
					road[tx - 1][ty] += road[tx][ty];
				}
			}
			
			
			if (ty - 1 >= 0) {
				if (c[tx][ty - 1] == 0) {
					temp.push(make_pair(tx, ty - 1));
					road[tx][ty - 1] += road[tx][ty];
				}
			}
			if (ty + 1 < x) {
				if (c[tx][ty + 1] == 0) {
					temp.push(make_pair(tx, ty + 1));
					road[tx][ty + 1] += road[tx][ty];
				}
			}
			if (tx + 1 < x) {
				if (c[tx + 1][ty] == 0) {
					temp.push(make_pair(tx + 1, ty));
					road[tx + 1][ty] += road[tx][ty];
				}
			}
			
			if (n[tx][ty] < age&&n[tx][ty]>0) {
				answer.push(make_pair(tx, ty));
				for (int z = i + 1; z < siz; ++z) {
					if (n[temp.front().first][temp.front().second] < age) {
						answer.push(make_pair(temp.front().first, temp.front().second));
					}
					temp.pop();
				}
				break;
			}
		}
		if (answer.size() > 0) {
			cout << "==========================이동칸 : " << ans << "나이 : " << age << "총 시간 : " << eatTime << endl;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
						cout << n[i][j] << " ";
					
				}
				cout << endl;
			}
			cout << endl;
			getchar();

			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x; j++) {
					cout << road[i][j] << " ";
				}
				cout << endl;
			}
			n[sx][sy] = 0;
			sx=answer.front().first;
			sy = answer.front().second;
			int ansSize = answer.size();
			cout <<"시발년의 싸이즈는 개씨발 :"<< ansSize << endl;
			for (int z = 0; z < ansSize; ++z) {
					cout << "x = " << answer.front().first << " y= " << answer.front().second << " " << road[answer.front().first][answer.front().second] << endl;
				
					answer.pop();
			}
			n[sx][sy] = -1;
			return ans;
		}
		ans++;
	}
	return 1000;
}
