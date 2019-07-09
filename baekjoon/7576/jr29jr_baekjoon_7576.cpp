#include <iostream>//cin,cout
#include <queue>//queue

using namespace std;
int day;
int box[1002][1002];
int M,N;
int noRipCnt;
int cal[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue< pair<int,int> > q1,q2;

void solveQ1();
void solveQ2();

int main(void){

	cin>>M>>N;

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			cin>>box[i][j];	
			if(box[i][j] == 1)
				q1.push(make_pair(i,j));	

			if(box[i][j] == 0)
				noRipCnt++;
		}

	for(int i=0;i<=M+1;i++){
		box[N+1][i]=-1;
		box[0][i]=-1;
	}
	
	for(int i=0;i<=N+1;i++){
		box[i][M+1]=-1;
		box[i][0]=-1;
	}
	solveQ1();
	/*
	//result box
	for(int i=0;i<=N+1;i++){
		for(int j=0;j<=M+1;j++){
			cout<<box[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<noRipCnt<<endl;
	*/
	if(noRipCnt != 0)
		cout<<-1<<endl;
	else
		cout<<day<<endl;
	return 0;
}
void solveQ1(){
	while(q1.size() != 0){
		pair<int,int> temp=q1.front();	
		q1.pop();
		for(int i=0;i<4;i++){
			int row,col;
			row=temp.first+cal[i][0];
			col=temp.second+cal[i][1];
			if(box[row][col] == 0){
				q2.push(make_pair(row,col));
				box[row][col]=1;
				noRipCnt--;
			}
		}
	}
	if(q2.size() != 0 ){
		day++;
		solveQ2();
	}
}
void solveQ2(){
	while(q2.size() != 0){
		pair<int,int> temp=q2.front();	
		q2.pop();
		for(int i=0;i<4;i++){
			int row,col;
			row=temp.first+cal[i][0];
			col=temp.second+cal[i][1];
			if(box[row][col] == 0){
				q1.push(make_pair(row,col));
				box[row][col]=1;
				noRipCnt--;
			}
		}
	}
	if(q1.size() != 0){
		day++;
		solveQ1();
	}
}
