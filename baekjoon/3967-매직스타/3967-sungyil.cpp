#include <iostream>
using namespace std;
/*
       4	0
	1 3 5 7	1
	 2   6	2
	1 3 5 7	3
	   4	4
*/
// 1.1  1.3  1.5  1.7  1 3 5 7
// 3.1  3.3  3.5  3.7  1 3 5 7
// 0.4  1.3  2.2  3.1
// 0.4  1.5  2.6  3.7
// 1.1  2.2  3.3  4.4
// 1.7  2.6  3.5  4.4
void prepare();
void find(int num[6][4], int x, int y, bool c[12],bool);
void last(int num[6][4]);
bool checking(int num[6][4]);
void numInp(int num[6][4], int x, int y, int inp);
int chToNum(char ch);

char star[6][10];
char alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
//                  0   1   2   3   4   5   6   7   8   9  10  11
bool check[12] = { 0, };

int num[6][4];

int main() {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; ++j) {
			cin >> star[i][j];
		}
	}

	prepare();
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 12; ++i) {
		cout << check[i] << " ";
	}
	cout << endl;
	find(num, 0, 0, check,false);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; ++j) {
			cout << star[i][j] << " ";
		}
		cout << endl;
	}

	getchar();
	getchar();
}
void prepare() {
	num[0][0] = chToNum(star[0][4]);
	num[1][0] = chToNum(star[0][4]);

	num[2][0] = chToNum(star[1][1]);
	num[3][0] = chToNum(star[1][1]);

	num[0][1] = chToNum(star[1][3]);
	num[2][1] = chToNum(star[1][3]);

	num[2][3] = chToNum(star[1][7]);
	num[4][0] = chToNum(star[1][7]);

	num[1][1] = chToNum(star[1][5]);
	num[2][2] = chToNum(star[1][5]);

	num[0][2] = chToNum(star[2][2]);
	num[3][1] = chToNum(star[2][2]);

	num[4][1] = chToNum(star[2][6]);
	num[1][2] = chToNum(star[2][6]);

	num[0][3] = chToNum(star[3][1]);
	num[5][0] = chToNum(star[3][1]);

	num[5][1] = chToNum(star[3][3]);
	num[3][2] = chToNum(star[3][3]);

	num[4][2] = chToNum(star[3][5]);
	num[5][2] = chToNum(star[3][5]);

	num[1][3] = chToNum(star[3][7]);
	num[5][3] = chToNum(star[3][7]);

	num[3][3] = chToNum(star[4][4]);
	num[4][3] = chToNum(star[4][4]);
	
}
void find(int num[6][4],int x,int y,bool c[12],bool conti) {
	/*for (int q = 0; q < 6; ++q) {
		for (int z = 0; z < 4; ++z) {
			cout << num[q][z] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int q = 0; q < 12; ++q) {
		cout << c[q] << " ";
	}
	cout << endl;*/
	if (conti)return;
	if (x == 3 && y == 5) {
		/*cout << endl;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				cout << num[i][j] << " ";
			}
			cout << endl;
		}*/
		if (checking(num)) {
			conti = true;
			last(num);
		}
		return;
	}
	int px=0;
	int py=0;
	if (x + 1 > 3) {
		px = -3;
		py++;
	}
	else {
		px++;
	}
	if (num[y][x] == -1) {
		//cout << y << " " << x <<py<<" "<<px<< endl;
		for (int i = 0; i < 12; ++i) {

			
			if (!c[i]) {
				
				int tempNum[6][4] = { 0, };
				memcpy(tempNum, num, sizeof(int) * 6 * 4);
				numInp(tempNum, x, y, i);
				c[i] = true;
				//cout << y << " " << x << "  " << py << " " << px << endl;
				find(tempNum, x + px, y + py, c, conti);
				c[i] = false;
			}
		}
	}
	else {
		//cout << y << " " << x << "  " << py << " " << px <<"===="<< endl;
		find(num, x+px, y+py, c, conti);
	}
	//cout << "asdfasdf" << endl;
	
}
void last(int num[6][4]) {
	star[0][4] = alpha[num[0][0]];
	star[1][1] = alpha[num[2][0]];
	star[1][3] = alpha[num[0][1]];
	star[2][2] = alpha[num[0][2]];
	star[4][4] = alpha[num[3][3]];
	star[3][5] = alpha[num[4][2]];
	star[3][3] = alpha[num[5][1]];
	star[1][5] = alpha[num[1][1]];
	star[2][6] = alpha[num[4][1]];
	star[1][7] = alpha[num[2][3]];
	star[3][7] = alpha[num[1][3]];
	star[3][1] = alpha[num[0][3]];
}
bool checking(int num[6][4]) {
	bool che = true;
	for (int i = 0; i < 6; ++i) {
		int sum = 0;
		for (int j = 0; j < 4; ++j) {
			sum += num[i][j];
		}
		if (sum != 22) {
			che = false;
			break;
		}
	}
	return che;
}
void numInp(int num[6][4], int x, int y, int inp) {
	if (x == 0 && y == 0 || x == 0 && y == 1) {
		num[0][0] = inp;
		num[1][0] = inp;
	}
	else if (x == 0 && y == 2 || x == 0 && y == 3) {
		num[2][0] = inp;
		num[3][0] = inp;
	}
	else if (x == 0 && y == 1 || x == 1 && y == 2) {
		num[0][1] = inp;
		num[2][1] = inp;
	}
	else if (x == 2 && y == 0 || x == 1 && y == 3) {
		num[0][2] = inp;
		num[3][1] = inp;
	}
	else if (x == 3 && y == 3 || x == 3 && y == 4) {
		num[3][3] = inp;
		num[4][3] = inp;
	}
	else if (x == 2 && y == 4 || x == 2 && y == 5) {
		num[4][2] = inp;
		num[5][2] = inp;
	}
	else if (x == 1 && y == 5 || x == 2 && y == 3) {
		num[5][1] = inp;
		num[3][2] = inp;
	}
	else if (x == 1 && y == 1 || x == 2 && y == 2) {
		num[1][1] = inp;
		num[2][2] = inp;
	}
	else if (x == 1 && y == 4 || x == 2 && y == 1) {
		num[4][1] = inp;
		num[1][2] = inp;
	}
	else if (x == 3 && y == 2 || x == 0 && y == 4) {
		num[2][3] = inp;
		num[4][0] = inp;
	}
	else if (x == 3 && y == 1 || x == 3 && y == 5) {
		num[1][3] = inp;
		num[5][3] = inp;
	}
	else if (x == 3 && y == 0 || x == 0 && y == 5) {
		num[0][3] = inp;
		num[5][0] = inp;
	}
	
}
int chToNum(char ch) {
	int i = 0;
	if (ch == 'x')return -1;
	for (i = 0; i < 12; ++i) {
		if (ch == alpha[i]) {
			check[i] = true;
			break;
		}
	}
	return i;
}
