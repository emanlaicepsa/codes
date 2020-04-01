#include <iostream>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int dp[1005];
int num[1005];
int arr[1005][1005];
int main(){
	int n,q;
	cin>>n;
	int t = 105;// can change 
	int ori = 0;
	//memset(dp,-0x3f,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=0;j<num[i];j++){
			cin>>arr[i][j];
			if(!j) ori += arr[i][j];
			else arr[i][j] -= arr[i][0];
		}
	}
	t -= n;
	for(int i=1;i<=n;i++){
		for(int j=num[i]-1;j>0;j--){
			for(int k=t;k>=j;k--){
				dp[k] = max(dp[k] , dp[k-j] + arr[i][j]);
			}
		}
	}
	while(cin>>q){
		if(q<n)cout<<0<<'\n';
		else cout<<ori+dp[q-n]<<'\n';
	}
	/*
	4
	4 3 4 3 6
	4 6 6 4 7
	4 7 9 8 9
	4 8 11 9 10
	*/ 

}

