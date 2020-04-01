#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int dp[1000005]={0};
int main(){
	IOS;
	int k,p;
	cin>>k>>p;
	int n,f,w;
	while(k--){
		cin>>n>>f>>w;
		for(int a=1,T=n;T>0;a*=2){
			if(a>T)a=T;
			T-=a;
			int weight=a*w,value=f*a;
			for(int x=p;x>=weight;x--){
			dp[x]=max(dp[x],value+dp[x-weight]);}	
		}
	}
	cout<<dp[p]<<'\n';
}

