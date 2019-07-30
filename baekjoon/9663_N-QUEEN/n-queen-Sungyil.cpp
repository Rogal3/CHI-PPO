#include <iostream>
#include <cstring>
using namespace std;
void fi(int n[16][16], int);

int n[16][16] = { 0, };
int mSize = 0;
int cnt = 0;
int main() {
	cin >> mSize;
	
	fi(n, 0);

	cout << cnt << endl;

	getchar();
	getchar();
}
void fi(int n[16][16],int d) {
	
	for (int i = 0; i < mSize; ++i) {//가로
		if (n[d][i] == 0) {
			n[d][i] = 1;
			
			if (d>= mSize - 1) {//마지막 줄이라면?  놓는순간 끝
				cnt++;
				n[d][i] = 0;//하나 놨으니 마지막 줄에 또 다른곳 둘곳 잇나 확인.
			}
			else {
				int temp[16][16];
				memcpy(temp, n, 16 * 16 * sizeof(int));

				for (int j = 0; j < mSize - d; ++j) {
					temp[d + j][i] = 1;
					if (i + j < mSize) {//오른대각
						temp[d + j][i + j] = 1;
					}
					if (i - j >= 0) {//왼대각
						temp[d + j][i - j] = 1;
					}
				}

				fi(temp, d + 1);//한줄 밑으로가서 진행
			}
		}
	}
}