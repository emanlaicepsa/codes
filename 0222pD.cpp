#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
bool used[505][505];
ll ans[100005];
int main(){
	IOS;
	ll nx,ny;
	ll x,y;
	cin>>x>>y>>nx>>ny;
	string s;
	ll step = 0;
	ll le = x*y;
	cin>>s;
	ans[0] = 1;
	used[nx][ny] = 1;
	le--;
	for(auto i:s){
		step++;
		if(i=='U')nx--;
		if(i=='D')nx++;
		if(i=='L')ny--;
		if(i=='R')ny++;
		nx = max(nx,1LL);
		ny = max(ny,1LL);
		nx = min(nx,x);
		ny = min(ny,y);
		if(!used[nx][ny]){
			used[nx][ny] = 1;
			le--;
			ans[step]++;
		}
	}
	ans[step] += le;
	for(int i=0;i<=step;i++){
		cout<<ans[i]<<" \n"[i==step];
	}
	


}

