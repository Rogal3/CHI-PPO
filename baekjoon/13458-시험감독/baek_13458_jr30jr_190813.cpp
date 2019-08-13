#include <iostream>
#include <stdio.h>

using namespace std;
int N,A[1000001],B,C;
long sum=0;
void solve();
int main(void){
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	cin>>B>>C;
	solve();
	cout<<sum<<endl;
	return 0;
}
void solve(){
	for(int i=0;i<N;i++){
		sum++;//B
        int temp=A[i]-B;
//총시험관이 똑똑해서 음수가 되는 경우가 존재한다 ㅋㅋ
        if(temp<0)
            continue;
		//C
		sum+=(temp)/C;
		if((temp)%C != 0 )
			sum++;
	}
}