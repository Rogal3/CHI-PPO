#include <iostream>
#include <stack>
using namespace std;
int finds(int **g, int *v, int f, int computer);

int main() {
	int computer = 0;
	int line = 0;
	int x, y;
	int **g,*v;
	stack<int> virus;
	
	cin >> computer;
	cin >> line;
	
	g = new int*[computer];
	v = new int[computer];
	for (int i = 0; i < computer; ++i) {
		g[i] = new int[computer];
		v[i] = 0;
	}

	for (int i = 0; i < computer; ++i) {
		for (int j = 0; j < computer; ++j) {
			g[i][j] = 0;
		}
	}

	while(line) {
		cin >> x;
		cin >> y;

		g[x-1][y-1] = 1;
		g[y-1][x-1] = 1;
		line--;
	}

	cout << finds(g, v, 0, computer)-1 << endl;
	
}
int finds(int **g,int *v,int f,int computer) {
	int counter=1;
	v[f] = 1;

	for (int i = 0; i < computer; ++i) {
		if (g[f][i] == 1 && v[i] == 0) {
			counter+=finds(g, v, i, computer);
		}
	}
	return counter;
}