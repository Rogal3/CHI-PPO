#include <iostream>
#include <cstring>//memset,memcpy
#define MAX 10
#define TREECNT 1000
using namespace std;

int N,M,Y;
int map[MAX][MAX][TREECNT];
int treecnt[MAX][MAX];
int energy[MAX][MAX];//all energy
int charge[MAX][MAX];
int r[8]={-1,-1,-1,0,1,1,1,0};//start is 11'clock
int c[8]={-1,0,1,1,1,0,-1,-1};//start is 11'clock

void dfs();
void springAndSummer();
void fall();
void winter();
void printTree();
int main(void){
	int sum=0;
	cin>>N>>M>>Y;
	//input charge amount
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin>>charge[i][j];
	}
	for(int i=0;i<M;i++){
		int row,col,age;
		cin>>row>>col>>age;
		map[row-1][col-1][0]=age;
		treecnt[row-1][col-1]++;
	}
	
	//energy set 5
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			energy[i][j]=5;
	dfs();

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			sum+=treecnt[i][j];
	cout<<sum<<endl;
	return 0;
}
void printCnt(){
	cout<<"--------------------------"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<treecnt[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------------"<<endl;
}
void printTree(){
	cout<<"--------------------------"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<i<<","<<j<<" : ";
			for(int k=0;k<treecnt[i][j];k++)
				cout<<map[i][j][k]<<" ";
			cout<<endl;
		}
	}
	cout<<"--------------------------"<<endl;
}
void dfs(){
	for(int i=0;i<Y;i++){
		//spring
		//summer
		springAndSummer();
		//fall
		fall();
		//winter
		winter();
	}
}
void springAndSummer(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int cnt=treecnt[i][j];
			int k=-1;
			//spring
			for(k=cnt-1;k>=0;k--){
				if(map[i][j][k] <= energy[i][j]){
					energy[i][j]-=map[i][j][k];
					map[i][j][k]++;
				}
				else
					break;
			}
			//summer
			if(k != -1){//remove tree + charge energy
				for(int l=0;l<=k;l++){//charge enrgy
					energy[i][j]+=map[i][j][l]/2;
				}
				treecnt[i][j]-=k+1;
				for(int l=0;l<treecnt[i][j];l++){//remove tree
					map[i][j][l]=map[i][j][k+1+l];
				}
			}
				
		}
	}
}
void fall(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<treecnt[i][j];k++){
				if(map[i][j][k]%5 != 0)
					continue;
				for(int l=0;l<8;l++){
					int row=i+r[l];
					int col=j+c[l];
					if( 0<=row && row<N && 0<=col && col<N ){
						map[row][col][treecnt[row][col]]=1;
						treecnt[row][col]++;
					}
				}
			}
		}
	}
}
void winter(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			energy[i][j]+=charge[i][j];		
}
