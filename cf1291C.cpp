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
int n,m,k;
ll arr[4000];
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		if(k>=m-1){
			ll ans = 0;	
			for(int i=1;i<=m;i++){
				ans = max(arr[i],ans);
			}
			for(int i=n;i>=n-m+1;i--){
				ans = max(arr[i],ans);
			}
			cout<<ans<<'\n';
		}
		else{
			ll ans = 0;
			int le = m-k-1;
			for(int i=0;i<=k;i++){
				ll ta = 1e9+5;
				int l = 1+i ,r = n-(k-i);
				for(int j=0;j<=le;j++){
					ta = min(ta, max(arr[l+j],arr[r-(le-j)]));
				}
				ans = max(ans,ta);
			}
			cout<<ans<<'\n';
		}
	}



}

