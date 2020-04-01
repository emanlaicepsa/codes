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
ll dp[20][50000];
int n,m;
ll cal(int premask , int nmask , int nrow, int npos){
	//cout<<premask<<" "<<nmask<<" "<<nrow<<" "<<npos<<'\n';
	if(npos == m){
		return dp[nrow-1][premask];
	}
	if((nmask&(1<<npos)) == 0) return cal(premask,nmask,nrow,npos+1);
	ll ta = cal(premask^(1<<npos),nmask,nrow,npos+1);
	if(npos + 1< m && (nmask&(1<<(npos+1)))) ta += cal(premask,nmask,nrow,npos+2);
	return ta;
}
int main(){
	IOS;
	while(cin>>n>>m){
		if(!n&&!m)break;
		memset(dp,0,sizeof(dp));
		dp[0][(1<<m)-1] = 1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(1<<m)-1;j++){
				dp[i][j] = cal((1<<m)-1 , j , i , 0);
			}
		}
		cout<<dp[n][(1<<m)-1]<<'\n'; 
	}


}

