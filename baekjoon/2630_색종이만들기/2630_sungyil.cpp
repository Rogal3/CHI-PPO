#include<iostream>
using namespace std;
void cutting(int startX, int startY, int divi);
int n[257][257] = { -1, };
int paperSize = 0;
int white=0,blue=0;

int main() {

	cin >> paperSize;
	paperSize *= 2;
	for (int i = 0; i < paperSize; i++) {
		for (int j = 0; j < paperSize; j++) {
			n[i][j] = 9;
		}
	}

	for (int i = 0; i < paperSize; i+=2) {
		for (int j = 0; j < paperSize; j+=2) {
			cin >> n[i][j];
		}
	}
	cutting(0, 0, 2);

	cout << white << endl;
	cout << blue << endl;

	getchar();
	getchar();
}
void cutting(int startX,int startY, int divi) {
	if (divi >= paperSize) {
		if (n[startX][startY] == 1) {
			blue++;
		}
		else {
			white++;
		}
		return;
	}
	
	int check = 0;
	int thisSize = paperSize / divi;
	int thisBoxSize = thisSize / 2 * thisSize / 2;
	pair<int, int> st[4] = {make_pair(startX,startY),make_pair(startX,startY+thisSize),make_pair(startX+thisSize,startY),make_pair(startX+thisSize,startY+thisSize)};
	
	for (int f = 0; f < 4; ++f) {//4등분 이므로 4번검사
		check = 0;

		for (int i = st[f].first; i < st[f].first+thisSize; i += 2) {//다 더해서 방체크
			for (int j = st[f].second; j < st[f].second+thisSize; j += 2) {
				check += n[i][j];
			}
		}

		if (check != 0 && check != thisBoxSize) {//다시 사등분해야한다.
			cutting(st[f].first, st[f].second, divi * 2);
		}
		else if (check == 0) {
			white++;
		}
		else if(check== thisBoxSize){
			blue++;
		}
	}
}