#include<bits/stdc++.h>
using namespace std;
int magic[1505];
int sidecnt;
int leftcnt;
void initialize(int n){
    for(int i=0;i<n;i++)
        magic[i]=n-1;
    leftcnt = n*(n-1)/2;
    sidecnt = n-1;
}
int hasEdge(int a, int b){
	magic[a] --;
	magic[b] --;
	if(sidecnt==leftcnt){
		sidecnt--;
		leftcnt--;
		return 1;
	}
	leftcnt--;
	if(magic[a]==0||magic[b]==0){
		sidecnt--;
		return 1;
	}
	return 0;
}
int main(){
	initialize(5);
	int a,b;
	while(cin>>a>>b){
		cout<<hasEdge(a,b)<<'\n';
	}
	
}
