#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[105][105];
int main(){
	IOS
	int c,s,q,ta,tb,tc,kas=0;
	while(cin>>c>>s>>q,c){
		reset(dp,0x3f);
		for(int i=1;i<=c;i++){
			dp[i][i]=0;
		}
		ll tt=dp[0][1];
		while(s--){
			cin>>ta>>tb>>tc;
			dp[ta][tb]=tc;
			dp[tb][ta]=tc;
			assert(tc<tt);
		}
		for(int k=1;k<=c;k++){
			for(int i=1;i<=c;i++){
				for(int j=1;j<=c;j++){
					dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
				}
			}
		}
		if(kas)cout<<'\n';
		cout<<"Case #"<<++kas<<'\n';
		while(q--){
			cin>>ta>>tb;
			if(dp[ta][tb]==tt)cout<<"no path\n";
			else cout<<dp[ta][tb]<<'\n';
		}
	} 



}

