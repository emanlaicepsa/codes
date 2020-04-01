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
int dp[10];
int main(){
	int n,p;
	string s;
	cin>>n;
	for(int i=1;i<=10;i++){
		dp[i] = 100000000;
	}
	dp[0] = 0;
	while(n--){
		cin>>p;
		cin>>s;
		int stat = 0;
		for(auto i:s){
			stat |= (1<<(i-'A'));
		}
		for(int i=7;i>=0;i--){
			dp[i|stat] = min(dp[i|stat],dp[i]+p);
		} 
		
	}
	if(dp[7]>1000000)cout<<-1<<'\n';
	else cout<<dp[7]<<'\n';


}

