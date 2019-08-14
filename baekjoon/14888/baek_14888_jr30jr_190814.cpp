#include <iostream>
#define MAX 11
#define KIND 4
using namespace std;

int N,A[MAX],operList[MAX-1];
int operKind[KIND];
int check[MAX-1];
int maxN=-2100000000,minN=2100000000;
void dfs(int depth,int index,int res);
void print();
int main(void){
	int cnt=0;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<KIND;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++,cnt++){
			operList[cnt]=i;
		}
	}
	dfs(1,1,A[0]);
	cout<<maxN<<endl<<minN<<endl;
	return 0;
}
void print(){
	for(int i=0;i<N-1;i++)
		cout<<operList[i]<<" ";
	cout<<endl;
}
void dfs(int depth,int index,int res){
	if(depth == N){
		if(maxN < res)
			maxN=res;
		if(minN > res)
			minN=res;
		return ;
	}
	for(int i=0;i<N-1;i++){
		if(check[i] == 0){
			int temp=res;
			check[i]=1;
			switch(operList[i]){
				case 0:
					res+=A[index];
					break;
				case 1:
					res-=A[index];
					break;
				case 2:
					res*=A[index];
					break;
				case 3:
					res/=A[index];
					break;
			}
			dfs(depth+1,index+1,res);
			check[i]=0;
			res=temp;
		}
	}
}
