#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
int cost[10005];
bool have[10005];
int main(){
	for(int i=0;i<10005;i++){
		cost[i]=2147483647;
	}
	int n,a,b;
	cin>>n>>a>>b;
	int tooth,co;
	for(int i=0;i<n;i++){
		cin>>tooth>>co;
		have[tooth]=1;
		cost[tooth]=min(cost[tooth],co);
	} 
	if(a<b)swap(a,b);
	if(a==b){
		cout<<0<<'\n';
		return 0;
	}
	int x=__gcd(a,b);
	a/=x;
	b/=x;
	int ans=2147483647;
	for(int i=b;i/b*a<=10000;i+=b){
		if(!have[i]||!have[i/b*a])continue;
		ans=min(ans,cost[i]+cost[i/b*a]);
	}
	if(ans==2147483647)cout<<-1<<'\n';
	else cout<<ans<<'\n';



}

