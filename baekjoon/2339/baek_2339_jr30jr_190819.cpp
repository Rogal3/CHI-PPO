#include <iostream>
#define MAX 20
#define HORIZON 1
#define VERTICAL 0
using namespace std;

int map[MAX][MAX];
int N;
int maxN;
int daq(int sx,int sy,int ex,int ey,int dir);
int canSlice(int sx,int sy,int ex,int ey,int dir);
int main(void){
    int rcnt=0,scnt=0;
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
         cin>>map[i][j];   
         if(map[i][j]==2)
             scnt++;
         else if(map[i][j]==1)
             rcnt++;
         else;
        }
    if(scnt == 1 && rcnt == 0){
        cout<<scnt<<endl;
        return 0;
    }
	maxN+=daq(0,0,N-1,N-1,VERTICAL);
	maxN+=daq(0,0,N-1,N-1,HORIZON);
    if(maxN > 0)
	cout<<maxN<<endl;
    else
        cout<<-1<<endl;
	return 0;
}
//horizon = 1,vertical = 0
int daq(int sx,int sy,int ex,int ey,int dir){
	int rcnt=0,scnt=0;//rock cnt,star cnt
	int sum=0;
	for(int i=sy;i<=ey;i++){
		for(int j=sx;j<=ex;j++){
			if(map[i][j] == 1){
				rcnt++;
				if(dir==VERTICAL && canSlice(sx,i,ex,i,HORIZON)){
					//cout<<"can H?"<<endl;
					sum+=daq(sx,sy,ex,i-1,HORIZON)*daq(sx,i+1,ex,ey,HORIZON);	
				}
				if(dir==HORIZON && canSlice(j,sy,j,ey,VERTICAL)){
					//cout<<"can V?"<<endl;
					sum+=daq(sx,sy,j-1,ey,VERTICAL)*daq(j+1,sy,ex,ey,VERTICAL);
				}
			}
			else if(map[i][j] == 2)
				scnt++;
			else;
		}
	}
	if(rcnt == 0 && scnt == 1){
		//cout<<"last"<<endl;
		return 1;
	}
	return sum;
}
// 0 = false, 1 = true
int canSlice(int sx,int sy,int ex,int ey,int dir){//can horizon,vertical
	if(dir == HORIZON){//horizon
		for(int i=sx;i<=ex;i++){
			if(map[sy][i] == 2)
				return 0;
		}
	}
	else{//vertical
		for(int i=sy;i<=ey;i++)
			if(map[i][sx] == 2)
				return 0;
	}
	return 1;
}
