#include <stdio.h>
#include <iostream>
#include <algorithm>

#define SIZE 8

using namespace std;

int N,M;
int check[SIZE];
int array[SIZE];
int result[SIZE];
void npm(int depth);
int main(void){
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
		cin>>array[i];

	sort(array,array+N);
	npm(1);
	return 0;
}
void npm(int depth){
	if(depth > M)
		return ;
	for(int i=0;i<N;i++){
		if(check[i] == 0){
			result[depth-1]=array[i];
			if(depth == M){
				for(int i=0;i<M;i++)
					printf("%d ",result[i]);
				printf("\n");
			}
			check[i]=1;
			npm(depth+1);
			check[i]=0;
		}
	}
}
