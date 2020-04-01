#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define fi first
#define se second
#define reset(n) memset(n,0,sizeof(n))
#define all(n) n.begin(),n.end()
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[505][505];
ll s[505][505];

inline ll ask(int i,int j,int k){
	return s[k][j]-s[k][i-1];
}

int main(){
	int n;
	cin>>n;
	rep1(n){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			s[i][j]=arr[i][j]+s[i][j-1];
		}
	}
	ll ans=(ll)-1e18;
	rep1(n){
		
		for(int j=i;j<=n;j++){
			ll temp=0;
			ll ta=(ll)-1e18;
			for(int k=1;k<=n;k++){
				temp=max({0LL,temp+ask(i,j,k),ask(i,j,k)});
				ta=max(ta,temp);
			}
			
			ans=max(ans,ta);
		}
	}
	
	cout<<ans<<'\n';
}

