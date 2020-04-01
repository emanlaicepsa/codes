#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll ans[70000][20];
ll tim[20];
int main(){
	reset(ans,0x3f);
	int n;
	cin>>n;
	rep(i,n){
		cin>>tim[i];
		ans[1<<(i)][i]=tim[i];
	}
	rep(i,(1<<n)){
		//cout<<i<<'\n';
		rep(j,n){
			if(i&(1<<j)){
				if(i==(1<<j))continue;
				rep(k,n){
					//cout<<k<<'\n';
					if(j==k)continue;
					if((i^(1<<j))&(1<<k)){
						//cout<<"5"<<'\n';
						ll res=ans[i^(1<<j)][k]+abs(j-k);
						//cout<<"5"<<'\n';
						if(res%tim[j])res+=tim[j]-(res%tim[j]);
						ans[i][j]=min(ans[i][j],res);
					}
				}
			}
		}
	}
	
	ll aaa=(ll)1e18;
	rep(i,n)aaa=min(aaa,ans[(1<<n)-1][i]);
	cout<<aaa<<'\n';

}

