#include <iostream>
using namespace std;
int t;
int cnt=0;
int p[1000000] = { 0, };

int main() {
	int min = 0;
	int max = 0;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> cnt;
		for (int j = 0; j < cnt; ++j) {
			cin >> p[j];
		}
		if (cnt == 1) {
			cout << "#" << i+1 << " " << p[0] * p[0] << endl;
		}
		else {
			min = p[0];
			max = p[0];
			for (int j = 1; j < cnt; ++j) {
				if (min > p[j])min = p[j];
				if (max < p[j])max = p[j];
			}
			cout << "#" << i + 1 << " " << max*min << endl;
		}
	}

}