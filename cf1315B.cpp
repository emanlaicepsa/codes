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
ll dp[100005];
int main(){
	IOS;
	ll t,a,b,p;
	string s;
	cin>>t;
	while(t--){
		cin>>a>>b>>p;
		cin>>s;
		ll x = s.size();
		s = " " + s;
		
		dp[x] = 0;
		while(x){
			if(s[x-1] == 'B')dp[x-1] = dp[x] + b;
			else dp[x-1] = dp[x] + a;
			x--;
			while(x-1 && s[x-1] == s[x]){
				dp[x-1] = dp[x];
				x--;
			}
		}
		
		for(int i=1;i<=s.size()-1;i++){
			if(dp[i] <= p){
				cout<<i<<'\n';
				break;
			}
		}
		
	}


}

