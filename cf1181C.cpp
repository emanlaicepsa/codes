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
int l[1005][1005];
char arr[1005][1005];
ll dp[1005][1005];

ll go(int x,int y){
	int l1 = l[x][y], l2 = l[l1][y] ,l3 = l[l2][y];
	
	//cout<<l1<<'\n';
	if(!l1||!l2)return 0;
	if(l1-x!=l2-l1)return 0;
	if(x-l1>l2-l3)return 0;
	l3 = l2 - (l1-l2);
	//cout<<x<<" "<<y<<' '<<l1<<" "<<l2<<" "<<l3<<'\n';
	if(y==1)return 1;
	int tl1 = l[x][y-1], tl2 = l[tl1][y-1],tl3 = l[tl2][y-1];
	tl3 = tl2 - (tl1-tl2);
	if(tl1 == l1 && tl2 == l2 && tl3 == l3 && arr[x][y] == arr[x][y-1] && arr[l1][y] == arr[l1][y-1] && arr[l2][y] == arr[l2][y-1])return dp[x][y-1]+1;
	return 1;
	//return 1;
}

int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			if(i==1)l[i][j] = 0;
			else l[i][j] = (arr[i][j] == arr[i-1][j])?l[i-1][j]:i-1;					
		}	
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = go(i,j);
			ans += dp[i][j];
		}
	}
	cout<<ans<<'\n';


}

