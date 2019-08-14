#include <iostream>
#include <queue>

using namespace std;

int map[21][21];
int temp[21][21];
int N;
int startR,startC;
int sharkLevel=2;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int minR,minC;
int minNum=-1;
int day;
int eatCnt;
struct Node{
	int row;
	int col;
	int step;
};

queue<Node> q;

void solve();
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			cin>>map[i][j];
			if(map[i][j] == 9){
				startR=i;
				startC=j;
				map[i][j]=0;
			}
		}
	Node start={startR,startC,1};	
	q.push(start);
	solve();
	cout<<day<<endl;
	/*
	cout<<minNum<<endl;
	cout<<minR<<","<<minC<<endl;
	*/
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
//step starts 1
void solve(){
	//cout<<q.front().row<<","<<q.front().col<<endl;
	while(q.size() != 0){

		Node tempN=q.front();
		q.pop();
		int step=tempN.step;	

		if(minNum != -1 && minNum < step )
			continue;

	for(int i=0;i<4;i++){
		int nowRow=tempN.row+dx[i];
		int nowCol=tempN.col+dy[i];
		//in Box
		if(0 < nowRow  && nowRow <=N && 0 < nowCol && nowCol <=N){
			//can move
			if(map[nowRow][nowCol] == sharkLevel || map[nowRow][nowCol] == 0)
				if(temp[nowRow][nowCol] == 0){
					temp[nowRow][nowCol]=step;
					Node t={nowRow,nowCol,step+1};
					q.push(t);
				}
			//can eat
			if( 0 < map[nowRow][nowCol] && map[nowRow][nowCol] < sharkLevel){
				if(minNum == -1 || minNum > step){
					minNum=step;
					minR=nowRow;
					minC=nowCol;
				}
				
				if(minNum == step){
					if(nowRow < minR){
						minR=nowRow;
						minC=nowCol;
					}
					else if(nowRow == minR){
						if(nowCol < minC){
							minC=nowCol;
							minR=nowRow;
						}
					}
					else;
				}
				
			}
				
		}

	}	
	}
	//when shark eat
	if(minNum != -1){
		//cout<<"spend : "<<minNum<<endl;
		day+=minNum;
		map[minR][minC]=0;
		minNum=-1;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				temp[i][j]=0;
		eatCnt++;
		if(eatCnt == sharkLevel){
			eatCnt=0;
			sharkLevel++;
		}
		Node t={minR,minC,1};
		q.push(t);
		cout<<"--------------------------"<<endl;
		cout<<day<<endl;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
		cout<<"--------------------------"<<endl;
		solve();
	}
}
