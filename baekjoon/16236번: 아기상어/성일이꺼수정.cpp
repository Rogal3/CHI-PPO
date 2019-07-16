// 
//	해충 수정버전.
//

#include <iostream>
#include <queue>
using namespace std;
int check();

int n[20][20] = { 0, };
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

/* 두 물고기의 좌표를 넣으면 먼저 먹어야하는 것을 리턴 */
typedef pair<int, int> pii;
pii& priority(pii& lhs, pii& rhs) {
	if (lhs.first < rhs.first) return lhs;	// 위에있는것부터
	else if (lhs.first == rhs.first && lhs.second < rhs.second) return lhs;		// 왼쪽에 있는것부터
	return rhs;
}

void printForDebug(pii fish, int ans) {
	for (int tx = 0; tx < x; ++tx) {
		for (int ty = 0; ty < x; ++ty) {
			printf("%2d ", n[tx][ty]);
		}
		putchar('\n');
	}
	printf("(%d, %d) 냠냠\n\n", fish.first, fish.second);
}

int check() {
	queue<pair<int, int>> temp;

	int ans = -1;
	int c[20][20] = { 0, };
	//int road[20][20] = { 0, };		// road 용도를 몰라서 일단 주석처리
	temp.push(make_pair(sx, sy));
	c[sx][sy] = 1;
	bool found = false;		// 먹이를 하나라도 찾으면 true가 됨.
	pii priority_fish = make_pair(0, 0);
	while (!temp.empty() && !found) {
		int siz = temp.size();
		for (int i = 0; i < siz; ++i) {
			int tx = temp.front().first;
			int ty = temp.front().second;
			//road[tx][ty] = ans;
			temp.pop();
			//if (n[tx][ty] > age) {		// 큰물고기 판정 뒤로 보냄.
			//	continue;
			//}
			if (n[tx][ty] < age && n[tx][ty]>0) {
				/* 아직 더찾아야함
				for (int z = i + 1; z < siz; ++z) {
					temp.pop();
				}
				n[sx][sy] = 0;
				sx = tx;
				sy = ty;
				n[tx][ty] = -1;
				return ans;
				*/	// 아직 더 찾아야함
				if (found == false) {
					found = true;
					priority_fish = make_pair(tx, ty);	// 처음 찾은 물고기가 됨.
				} else {
					pii newFish = make_pair(tx, ty);
					priority_fish = priority(priority_fish, newFish);	// 이전 물고기랑 새로운 물고기랑 우선순위 비교
				}
			}
			if (found) continue;		// 더 먼거리는 찾을 필요가 없음. 스킵.
			if (tx - 1 >= 0) {
				if (c[tx - 1][ty] == 0) {
					if (n[tx - 1][ty] <= age) {
						c[tx-1][ty] = 1;
						temp.push(make_pair(tx - 1, ty));
						//road[tx - 1][ty] += road[tx][ty];
					}
				}
			}
			if (ty - 1 >= 0) {
				if (c[tx][ty - 1] == 0) {
					if (n[tx][ty - 1] <= age) {
						c[tx][ty-1] = 1;
						temp.push(make_pair(tx, ty - 1));
						//road[tx][ty - 1] += road[tx][ty];
					}
				}
			}
			if (ty + 1 < x) {
				if (c[tx][ty + 1] == 0) {
					if (n[tx][ty + 1] <= age) {
						c[tx][ty+1] = 1;
						temp.push(make_pair(tx, ty + 1));
						//road[tx][ty + 1] += road[tx][ty];
					}
				}
			}
			if (tx + 1 < x) {
				if (c[tx + 1][ty] == 0) {
					if (n[tx + 1][ty] <= age) {
						c[tx +1][ty] = 1;
						temp.push(make_pair(tx + 1, ty));
						//road[tx + 1][ty] += road[tx][ty];
					}
				}
			}
			
		}
		ans++;
	}
	if (found) {
		n[sx][sy] = 0;
		n[priority_fish.first][priority_fish.second] = 0;	// 냠냠.
		sx = priority_fish.first;
		sy = priority_fish.second;
		n[sx][sy] = -1;
		printForDebug(priority_fish, ans);    // 제출할땐 주석처리.
		return ans;
	}
	else
		return 1000;
}
