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
int cnt[5000];
ll ans[5000][1300];
int cal[5000];
int main(){
	IOS;
	int n,m,q,ask;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>cal[i];
	}
	string s;
	for(int i=0;i<m;i++){
		cin>>s;
		int cur = 0;
		for(int j=0;j<n;j++){
			if(s[j] == '1'){
				cur |= (1<<j);
			}
		}
		cnt[cur] ++;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<(1<<n);j++){
			int x = i^j^((1<<n)-1);
			//cout<<i<<" "<<j<<" "<<x<<'\n';
			int cur = 0;
			for(int k=0;k<n;k++){
				if(x&(1<<k))cur += cal[k]; 
			}
			ans[i][cur] += cnt[j];
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=100*n;j++){
			ans[i][j] += ans[i][j-1];
		}
	}
	while(q--){
		cin>>s>>ask;
		if(ask > n*100)ask = n*100;
		int cur = 0;
		for(int j=0;j<n;j++){
			if(s[j] == '1'){
				cur |= (1<<j);
			}
		}
		cout<<ans[cur][ask]<<'\n';
	}
}

