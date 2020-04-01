#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[6][2000];
ll arr[6][2000];
int main(){
	IOS
	int n;
	cin>>n;
	int type;
	for(int i=0;i<n;i++){
		cin>>type;
		int t1=0,t;
		for(int j=0;j<10;j++){
			cin>>t;
			t1<<=1;
			t1+=t;
		}
		arr[type-1][t1]++;
	}
	for(int i=0;i<1024;i++){
		dp[0][i]=arr[0][i];
	}
	for(int i=1;i<5;i++){
		for(int j=0;j<1024;j++){
			if(arr[i][j]==0)continue;
			for(int k=0;k<1024;k++){
				dp[i][j|k]+=dp[i-1][k]*arr[i][j];
				dp[i][j|k]%=1000000007;
			}
		}
	}
	cout<<dp[4][1023]<<'\n';

}

