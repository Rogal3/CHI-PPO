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
//�ѽ������ �ȶ��ؼ� ������ �Ǵ� ��찡 �����Ѵ� ����
        if(temp<0)
            continue;
		//C
		sum+=(temp)/C;
		if((temp)%C != 0 )
			sum++;
	}
}