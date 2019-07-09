#include <iostream>
#include <queue>
using namespace std;
int box[1001][1001];
int che[1001][1001];
int main() {
	int x=0, y=0;
	int i = 0, j = 0;
	queue<pair<int, int>> q;

	cin >> x;
	cin >> y;

	for (i = 0; i<y; ++i) {
		for (j = 0; j<x; ++j) {
			cin >> box[i][j];
			che[i][j] = 0;
		}
	}
	
	for (i = 0; i < y; ++i) {
		for (j = 0; j < x; ++j) {
			if (box[i][j] == 1) {
				che[i][j] = 1;
				pair<int, int> a = make_pair(i, j);
				q.push(a);
			}
		}
	}
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();
		if (a + 1 < y&&box[a + 1][b] == 0) {
			box[a + 1][b] = 1;
			che[a + 1][b] = che[a][b] + 1;
			pair<int, int> c = make_pair(a + 1, b);
			q.push(c);
		}
		if (a - 1 >= 0 && box[a - 1][b] == 0) {
			box[a - 1][b] = 1;
			che[a - 1][b] = che[a][b] + 1;
			pair<int, int> c = make_pair(a - 1, b);
			q.push(c);
		}
		if (b + 1 < x&&box[a][b + 1] == 0) {
			box[a][b + 1] = 1;
			che[a][b + 1] = che[a][b] + 1;
			pair<int, int> c = make_pair(a, b + 1);
			q.push(c);
		}
		if (b - 1 >= 0 && box[a][b - 1] == 0) {
			box[a][b - 1] = 1;
			che[a][b - 1] = che[a][b] + 1;
			pair<int, int> c = make_pair(a, b - 1);
			q.push(c);
		}
	}

	int chek = 0;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			if (box[i][j] == 0) {
				chek = 1;
				break;
			}
		}
		if (chek == 1)break;
	}
	if (chek == 1)cout << -1 << endl;
	else {
		int day = 0;
		for (i = 0; i < y; ++i) {
			for (j = 0; j < x; ++j) {
				if (day < che[i][j]) {
					day = che[i][j];
				}
			}
		}
		cout << day-1 << endl;
	}
	return 0;
}
