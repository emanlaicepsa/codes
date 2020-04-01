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
vector<int> v[30];
int dp[1050000];
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<26;i++)v[i].clear();
		int n;
		cin>>n;
		fill(dp,dp+(1<<n),0);
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			v[s[i]-'a'].pb(i);
		}
		for(int i=0;i<26;i++){
			v[i].pb(s.size() + 1);
		}
		bool ok = 1;
		for(int i=1;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					if(i==(1<<j)){
						dp[i] = *v[j].begin();
					}
					else{
						int k = i^(1<<j);
						dp[i] = max(dp[i] , *lower_bound(all(v[j]),dp[k]) );
					}
				}
			}
			if(dp[i] == s.size()+1){
				ok = 0;
				break;
			}
		}
		if(!ok)cout<<"No\n";
		else cout<<"Yes\n";	
	}
	


}

