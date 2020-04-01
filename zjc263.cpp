#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()

using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[55][55];
ll dp[55][55][55][55];

inline ll calc(int x1,int y1,int x2,int y2,int px,int py){
	ll res=0;
	for(int i=y1;i<=y2;i++){
		res+=arr[px][i];
	}
	for(int j=x1;j<=x2;j++){
		res+=arr[j][py];
	}
	res-=arr[px][py];
	res*=arr[px][py];
	return res;
}

ll godp(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2)return 0;
	if(dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
	ll ta=(ll)1e18; 
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			ta=min(ta,calc(x1,y1,x2,y2,i,j)+godp(x1,y1,i-1,j-1)+godp(x1,j+1,i-1,y2)+godp(i+1,y1,x2,j-1)+godp(i+1,j+1,x2,y2));
			
		}
	} 
	return dp[x1][x2][y1][y2]=ta;
}

int main(){
	int n,m;
	cin>>n>>m;
	rep1(i,n){
		rep1(j,m){
			cin>>arr[i][j];
			dp[i][j][i][j]=arr[i][j]*arr[i][j];
		}
	}
	
	for(int k1=0;k1<n;k++){
		for(int k2=0;k2<=m;k++){
			for(int i=1;i+k1<=n;i++){
				for(int j=1;j+k2<=m;j++){
					dp[i][j][i+k1][i+k2]=
				}
			}
		}
	}
	
	ll ans= godp(1,1,n,m);

	cout<<ans<<'\n';

}

