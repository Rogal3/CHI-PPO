#include <stdio.h>
#include <iostream>
#define SIZE 8

using namespace std;
int check,ans[SIZE];
int N;

void dfs(int,int);
int main(void){
	cin>>N;	
	dfs(0,0);
	return 0;
}

void dfs(int depth,int check){
	if(depth == N){
		for(int i=0;i<N;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=0;i<N;i++){
		if(check & 1<<i)
			continue;
		ans[depth]=i+1;
		check=check | 1<<i;
		dfs(depth+1,check);
		check=check ^ 1<<i;
	}
}
