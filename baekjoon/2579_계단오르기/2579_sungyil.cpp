#include <iostream>
#include <algorithm>
using namespace std;
void dfs(int cur, int p, int prev);

int stair[301] = { 0, };
int memo[301] = { 0, };
int n = 0;
int ans = 0;
int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> stair[i];
	}

	dfs(0, 1, 0);

	for (int i = 0; i < n; ++i) {
		cout << memo[i] << " ";
	}
	cout << endl;
	cout << ans << endl;
	getchar();
	getchar();
}
void dfs(int cur,int p,int prev) {
	if (n < cur)return;
	if (n == cur) {
		ans = max(ans,memo[prev]+stair[cur]);
		return;
	}
	if (memo[cur] > memo[prev] + stair[cur]) {
		return;
	}
	memo[cur] = memo[prev] + stair[cur];//max(memo[cur], memo[prev]+stair[cur]);

	//cout << cur << " " << p << " " << prev <<" "<<memo[cur]<< endl;
	//getchar();*/

	if(p<3)dfs(cur + 1, p + 1,cur);//연속 3계단 x
	dfs(cur + 2, 1,cur);
}
