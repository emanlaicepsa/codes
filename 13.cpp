#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<memory.h>
using namespace std;
ll dp[100005]={0};
int main(){
	IOS;
	ll V;
	while(cin>>V){
		ll maxnum=0;
		memset(dp,0,sizeof(dp));
		ll n;
		cin>>n;
		ll wi,pi;
		while(n--){
			cin>>wi>>pi;
			if(wi>V)continue;
			for(int x=wi;x<=V;x++){
				dp[x]=max(dp[x],dp[x-wi]+pi);
				maxnum=max(maxnum,dp[x]);
			}
		 }
		cout<<maxnum<<endl;
	}
	


}

