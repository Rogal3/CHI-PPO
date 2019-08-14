#include <iostream>
#define MAX 11
#define KIND 4
using namespace std;

int N,A[MAX],oper[KIND];
int maxN=-2100000000,minN=2100000000;

void dfs(int depth,int res);
int main(void){
	int cnt=0;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<KIND;i++){
		cin>>oper[i];
	}
	dfs(1,A[0]);
	cout<<maxN<<endl<<minN<<endl;
	return 0;
}
void dfs(int depth,int res){
	if(depth == N){
		if(maxN < res)
			maxN=res;
		if(minN > res)
			minN=res;
		return ;
	}
	if(oper[0]){
		oper[0]--;
		dfs(depth+1,res+A[depth]);
		oper[0]++;
	}
	if(oper[1]){
		oper[1]--;
		dfs(depth+1,res-A[depth]);
		oper[1]++;
	}
	if(oper[2]){
		oper[2]--;
		dfs(depth+1,res*A[depth]);
		oper[2]++;
	}
	if(oper[3]){
		oper[3]--;
		dfs(depth+1,res/A[depth]);
		oper[3]++;
	}
}
