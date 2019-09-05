#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
void bfs();

struct Node{
	int rx,ry,bx,by;
};
int n, m;
char bmap[11][11];
pair<int, int> spoted[3];

int moveY[4] = { -1,1,0,0 };
int moveX[4] = { 0,0,-1,1 };
int cheking[11][11][11][11];
bool tcheck = true;
int ans = -1;
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> bmap[i][j];
			if (bmap[i][j] == 'R') {
				spoted[0] = make_pair(j, i);
			}
			else if (bmap[i][j] == 'B') {
				spoted[2] = make_pair(j, i);
			}
		}
	}

	bfs();

	cout << ans;

	getchar();
	getchar();
}
void bfs(){
	queue<Node> q;
	Node n={spoted[0].first,spoted[0].second,spoted[2].first,spoted[2].second};
	cout<<n.rx<<n.ry<<n.bx<<n.by<<endl;
	q.push(n);
	int dept=0;
	cheking[spoted[0].first][spoted[0].second][spoted[2].first][spoted[2].second]=1;

	while(q.size()){
		int qs=q.size();
		while(qs){
			qs--;
			Node n=q.front();
			q.pop();

			if(bmap[n.ry][n.rx]=='O'&&bmap[n.ry][n.rx]!=bmap[n.by][n.bx]){
				ans=dept;
				return;
			}

			for(int i=0;i<4;++i){
				int rx=n.rx;
				int ry=n.ry;
				int bx=n.bx;
				int by=n.by;

				while(bmap[ry+moveY[i]][rx+moveX[i]] !='#'&&bmap[ry][rx]!='O'){
					ry+=moveY[i];
					rx+=moveX[i];
				}
				while(bmap[by+moveY[i]][bx+moveX[i]]!='#'&&bmap[by][bx]!='O'){
					by+=moveY[i];
					bx+=moveX[i];
				}
				if(by==ry&&rx==bx){//곂쳤을 경우에
					if(bmap[by][bx]=='O')continue;
					if(abs(rx-n.rx)+abs(ry-n.ry)<abs(n.bx-bx)+abs(n.by-by)){//블루가 앞에있을떄
						by-=moveY[i];
						bx-=moveX[i];//한칸 앞으로
					}else{
						ry-=moveY[i];
						rx-=moveX[i];
					}
				}
				
				
				if(cheking[rx][ry][bx][by])continue;
				cheking[rx][ry][bx][by]=1;
				Node emp={rx,ry,bx,by};
				q.push(emp);
			}	
		}
		if(dept==10){
				ans=-1;
				return;
		}
		dept++;
	}
	
}
