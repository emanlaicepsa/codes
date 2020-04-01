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
pii ans[5005][5005];
bool vis[5005][5005];
bool ok[5005][5005];

void go(int x,int y){
	if(x<0||y<0)return;
	cout<<x<<" "<<y<<'\n';
	
	if(vis[x][y]) return;
	vis[x][y] = 1;
	go(x-1,y-x+1);
	
	if(ok[x-1][y-x+1]){
		ans[x][y] = {x-1,y-x+1};
		ok[x][y] = 1;
		return;
	}
	bool f = 0;
	for(int i=x-1;i*2>=x;i--){
		for(int j=y-x+1;j>=1;j--){
			cout<<i<<" "<<j<<'\n';
			if(y-x+1-j < 0) continue;
			go(i,j);
			go(x-i-1,y-x+1-j);
			if(ok[i][j] && ok[x-i+1][y-x+1-j]){
				f=1;
				ok[x][y] = 1;
				ans[x][y] = {i,j};
				break;
			}
		}
		if(f)break;
	}
}
int main(){
	IOS;
	int t,n,d;
	cin>>t;
	ok[0][0] = 1;
	vis[0][0] = 1;
	while(t--){
		cin>>n>>d;
		go(n,d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<i<<" "<<j<<" "<<ok[i][j]<<'\n';
			}
		}
		if(ok[n][d]){
			cout<<"YES\n";
			//dfs(n,d);
		}
		else{
			cout<<"NO\n";
		}
	}	
	 

}

