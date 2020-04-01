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
ll n,k; 
char c;
vector<int> blkx[2005];
vector<int> blky[2005];
char arr[2005][2005];
ll dp[2005][2005];
ll dp2[2005][2005];
int nans;
int tans;
int nl ,nr ,nt , nd ;
void add(int y,int nt,int nd){
	if(blky[y].size()){
		if(nt <= blky[y][0] && nd >= blky[y][blky[y].size()-1]) nans ++;
	}
}

void sub(int y,int nt,int nd){
	if(blky[y].size()){
		if(nt <= blky[y][0] && nd >= blky[y][blky[y].size()-1]) nans --;
	}
}

void add2(int x,int nl,int nr){
	if(blkx[x].size()){
		if(nl <= blkx[x][0] && nr >= blkx[x][blkx[x].size()-1]) nans ++;
	}
}

void sub2(int x,int nl,int nr){
	if(blkx[x].size()){
		if(nl <= blkx[x][0] && nr >= blkx[x][blkx[x].size()-1]) nans --;
	}
}

int main(){
	IOS;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 'B') blkx[i].pb(j);
		}
		if(blkx[i].empty())tans ++;
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(arr[i][j] == 'B') blky[j].pb(i);
		}
		if(blky[j].empty())tans++;
	}
	
	for(int i=0;i<n-k+1;i++){
		nans = 0;
		for(int j=0;j<k;j++){
			add(j,i,i+k-1);
		}
		dp[i][0] = nans;
		for(int j=0;j<n-k;j++){
			sub(j,i,i+k-1);
			add(j+k,i,i+k-1);
			dp[i][j+1] = nans;
		}
	}
	
	for(int i=0;i<n-k+1;i++){
		nans = 0;
		for(int j=0;j<k;j++){
			add2(j,i,i+k-1);
		}
		dp2[0][i] = nans;
		for(int j=0;j<n-k;j++){
			sub2(j,i,i+k-1);
			add2(j+k,i,i+k-1);
			dp2[j+1][i] = nans;
		}
	}
	ll ans = 0;
	for(int i=0;i<n-k+1;i++){	
		for(int j=0;j<n-k+1;j++){
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp2[i][j]<<'\n';
			ans = max(ans, tans + dp[i][j] + dp2[i][j]);
		}
	}
	cout<<ans<<'\n';

}

