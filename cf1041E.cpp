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
int cnt[1005];
bool used[1005];
vector<int> to[1005];
int main(){
	int n;
	cin>>n;
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(b!=n){
			cout<<"NO\n";
			return 0;
		}
		cnt[a] ++;
	}
	int now = 1;
	for(int i=1;i<n;i++){
		if(!cnt[i])continue;
		used[i] = 1;
		cnt[i]--;
		while(cnt[i] && now <= i){
			if(!used[now]){
				cnt[i] --;
				to[i].pb(now);
			}
			now ++;
		}
		to[i].pb(i);
		if(cnt[i]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<n;i++){
		if(to[i].empty())continue;
		//for(auto x:to[i])cout<<x<<" ";
		//cout<<'\n';
		//to[i].pb(n);
		int cur = n;
		for(int j=0;j<to[i].size();j++){
			cout<<cur<<" "<<to[i][j]<<'\n';
			cur = to[i][j];
		}
	}
	
}

