#include <iostream>
#include <cstring>
using namespace std;
void change(int map[51][51],int x, int y, int k);
void find(int map[51][51], int top, bool check[7]);
void minFind(int line[51]);
int n, m,k;
int map[51][51];
int mina = 0xFFFFFF;

int bx[7] = { 0, }, by[7] = { 0, }, bz[7] = { 0, };

int main() {
	
	cin >> n >> m>>k;
	int line[51];
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			sum += map[i][j];
		}
		line[i] = sum;
	}
	//minFind(line);

	for (int i = 0; i < k; ++i) {
		cin >> by[i] >> bx[i] >> bz[i];
	}
	bool check[7] = { 0, };
	find(map, 0, check);

	cout << mina << endl;

	getchar(); 
	getchar();
	return 0;
}
void find(int map[51][51],int top,bool check[7]) {
	if (top == k) {
		int line[51];
		for (int i = 0; i < n; i++) {
			int sum=0;
			for (int j = 0; j < m; j++) {
				sum+=map[i][j];
			}
			line[i] = sum;
		}
		
		minFind(line);

		return;
	}
	for (int i = 0; i < k; ++i) {
		if (!check[i]) {
			int tempMap[51][51];
			memcpy(tempMap, map, sizeof(int) * 51 * 51);
			check[i] = true;
			top++;
			for (int q = 1; q <= bz[i]; q++) {
				change(tempMap, bx[i]-1, by[i]-1, q);
			}
			
			find(tempMap,top, check);
			top--;
			check[i] = false;
		}
	}
}
void minFind(int line[51]) {
	int emp = 0xFFFFFF;
	for (int i = 0; i < n; ++i) {
		if (emp > line[i]) {
			emp = line[i];
		}
	}
	if (mina > emp) {
		mina = emp;
	}
}
void change(int map[51][51],int x, int y, int k) {
	int sx = x - k;
	int sy = y - k;
	int temp = map[sy][sx];
	int emp = 0;
	for (int i = 0; i < k * 2;++i) {
		emp=map[sy][sx + 1];
		map[sy][sx + 1] = temp;
		temp = emp;
		sx++;
	}
	for (int i = 0; i < k * 2; ++i) {
		emp = map[sy + 1][sx];
		map[sy + 1][sx] = temp;
		temp = emp;
		sy++;
	}
	for (int i = 0; i < k * 2; ++i) {
		emp = map[sy][sx - 1];
		map[sy][sx - 1] = temp;
		temp = emp;
		sx--;
	}
	for (int i = 0; i < k * 2; ++i) {
		emp = map[sy - 1][sx];
		map[sy - 1][sx] = temp;
		temp = emp;
		sy--;
	}
}
