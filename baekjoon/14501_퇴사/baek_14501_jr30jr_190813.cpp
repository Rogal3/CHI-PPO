#include <iostream>
#define SIZE 15
using namespace std;
int N;
int T[SIZE+1],P[SIZE+1];
int maxN=-1;
void dfs(int day,int pay);
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>T[i]>>P[i];
	dfs(1,0);//first is concluded
	cout<<maxN<<endl;
	return 0;
}
void dfs(int day,int pay){
	if(maxN<pay)
		maxN=pay;
	if(day == N+1)
		return ;
	if(day+T[day]<=N+1){
		dfs(day+T[day],pay+P[day]);
	}
	if(day<N)
		dfs(day+1,pay);
}
