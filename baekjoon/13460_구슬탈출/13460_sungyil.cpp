#include <iostream>
#include <utility>
using namespace std;
void findss(char bmap[11][11], pair<int, int> red, pair<int, int> blue, int dept);
int* movingCheck(char bmap[11][11], pair<int, int> red);
int movingBall(char bmap[11][11], pair<int, int> red, pair<int, int> blue, int moving);

int n, m;
char bmap[11][11];
pair<int, int> spoted[3];

int moveY[4] = { -1,1,0,0 };
int moveX[4] = { 0,0,-1,1 };

bool tcheck = true;
int ans = -1;
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> bmap[i][j];
			if (bmap[i][j] == 'R') {
				spoted[0] = make_pair(i, j);
			}
			else if (bmap[i][j] == 'B') {
				spoted[2] = make_pair(i, j);
			}
		}
	}
	findss(bmap,spoted[0], spoted[2], 1);

	cout << ans;

	getchar();
	getchar();
}
void findss(char bmap[11][11],pair<int, int> red, pair<int, int> blue, int dept) {
	if (dept == 11) {
		return;
	}
	if (tcheck) {
		int* move = movingCheck(bmap, red);

		for (int i = 0; i < 4; ++i) {
			if (move[i]) {
				pair<int, int> newBlue = make_pair(blue.first, blue.second);
				pair<int, int> newRed = make_pair(red.first, red.second);
				char newBmap[11][11];
				memcpy(newBmap, bmap, sizeof(char) * 11 * 11);
				int a=movingBall(newBmap, newRed, newBlue, i);
				if (a == 0) {
					findss(newBmap, newRed, newBlue, dept + 1);
				}
				else if (a == 1) {
					tcheck == false;
					ans = dept;
					return;
				}
			}
		}
	}
}
int* movingCheck(char bmap[11][11], pair<int, int> red) {
	int move[4] = { 0, };
	for (int i = 0; i < 4; i++) {
		if (bmap[red.first + moveY[i]][red.second + moveX[i]] != '#') {
			move[i] = 1;
		}

	}
	return move;
}
int movingBall(char bmap[11][11], pair<int, int> red, pair<int, int> blue,int moving) {
	bool che = true;
	while (che) {
		che = false;
		int movingX = blue.first + moveY[moving];
		int movingY = blue.second + moveX[moving];
		char curC = bmap[movingY][movingX];

		if (curC == 'O') {
			return -1;
		}
		else if (curC != '#'&&curC !='R') {
			bmap[blue.first][blue.second] = '.';
			bmap[movingY][movingX] = 'B';
			blue.first += movingY;
			blue.second += movingX;
			che = true;
		}

		movingX = red.first + moveY[moving];
		movingY = red.second + moveX[moving];
		curC = bmap[movingY][movingX];

		if (curC == 'O') {
			return 1;
		}
		else if (curC != '#'&&curC != 'R') {
			bmap[red.first][red.second] = '.';
			bmap[movingY][movingX] = 'R';
			red.first += movingY;
			red.second += movingX;
			che = true;
		}
	}
	return 0;
}
