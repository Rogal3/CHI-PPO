#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001] = { 0, };
int inp[1001];
int ans = 0;
int main(){

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> inp[i];

		int p = 0;
		for (int j = 0; j < i; ++j) {
			if (inp[i] > inp[j]) {
				p = max(dp[j], p);
			}
		}
		dp[i] = p + 1;
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	return 0;
}
