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
const ll mod = 1000000007;
int dp[5005][5005];
int ans[5005];
bool isp[5005][5005];
//int rcha[5005][5005];

ll pw(ll x,ll y){
	ll ans = 1,m = x;
	while(y){
		if(y&1)ans = (ans*m)%mod;
		m = (m*m)%mod;
		y>>=1;	
	}
	return ans;
}

int main(){
	IOS;
	string s;
	cin>>s;
	int siz = s.size();
	for(int i=0;i<siz;i++){
		isp[i][i] = 1;
		dp[i][i] = 1;
		ans[1] ++;
	}
	ll l = 2;
	while(l<=siz){
		for(int i=0;i+l-1<siz;i++){
			if(l==2){
				if(s[i] == s[i+1]){
					isp[i][i+1] = 1;
					dp[i][i+l-1] = 2;
					ans[dp[i][i+l-1]]++;	
				}
				//cout<<i<<" "<<i+l-1<<'\n';
			}
			else if(isp[i+1][i+l-2] && s[i] == s[i+l-1]){
				isp[i][i+l-1] = 1;
				dp[i][i+l-1] = 1;
				int x = l/2;
				if(isp[i][i+x-1] && isp[i+l-x][i+l-1]){
					dp[i][i+l-1] = dp[i][i+x-1] + 1; 
				}
				ans[dp[i][i+l-1]]++;	
			}		
		}
		l++;
	}
	
	for(int i=siz;i>=1;i--){
		ans[i] += ans[i+1];
	}
	
	for(int i=1;i<=siz;i++){
		cout<<ans[i]<<" \n"[i==siz];
	}
	


}

