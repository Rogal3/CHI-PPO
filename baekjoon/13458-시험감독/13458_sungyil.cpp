#include<iostream>
using namespace std;
int n,  b, c;
int a[1000001];
long res = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> b >> c;

	int emp = 0;
	for (int i = 0; i < n; ++i) {
		emp = 0;
		emp = a[i] - b;
		res++;
		if (emp <= 0)continue;
		res += emp / c;
		if (emp % c >= 1) {
			res++;
		}
	}
	cout << res << endl;

	getchar();
	getchar();
}