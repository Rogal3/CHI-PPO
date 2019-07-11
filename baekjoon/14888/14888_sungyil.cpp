#include <iostream>
#include<queue>
using namespace std;
void find(int multi, int plus, int minus, int divi, int res, int count);

int numcnt = 0;
int oper[4] = { 0, };
int num[12] = { 0, };
int maxNum= -1000000000;
int minNum = 1000000000 ;

int main() {

	cin >> numcnt;
	for (int i = 0; i < numcnt; ++i) {
		cin >> num[i];
	}
	for (int i = 3; i >=0; --i) {
		cin >> oper[i];
	}
	find(oper[3], oper[2], oper[1], oper[0], num[0], 1);

	cout << maxNum << endl << minNum << endl;
	
}
void find(int plus,int minus,int multi,int divi,int res,int count) {
	int res1;
	if (count >= numcnt) {
		if (maxNum < res) {
			maxNum = res;
		}
		if (minNum > res) {
			minNum = res;
		}
	}
	if (plus > 0) {
		res1 = num[count] + res;
		find(plus - 1, minus,multi, divi, res1, count + 1);
	}
	if (minus > 0) {
		res1 = res- num[count];
		find(plus , minus-1, multi, divi, res1, count + 1);
	}
	if (multi > 0) {
		res1 =res* num[count];
		find(plus , minus, multi-1, divi, res1, count + 1);
	}
	
	if (divi > 0) {
		res1 =  res/ num[count];
		find(plus , minus, multi, divi-1, res1, count + 1);
	}
	
}