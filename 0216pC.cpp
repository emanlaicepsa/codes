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
vector<int> p;
bool np[2505];
int arr[3005][3005];
ll pre[3005][3005];
ll ans[400];
int n,m;
ll sum(int x1,int y1,int x2,int y2){
	if(x2>3000)x2 = 3000;
	if(y2>3000)y2 = 3000;
	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<'\n';
	return pre[x2][y2] - pre[x1][y2] - pre[x2][y1] + pre[x1][y1];
}

ll calc(int x){
	ll ans = 0;
	for(int i=0;i<=n;i+=x){
		for(int j=0;j<=m;j+=x){
			ll tmp = sum(i,j,i+x,j+x);
			//cout<<tmp<<'\n';
			ans += min(tmp,x*x-tmp);
		}
	}
	return ans;
}


int main(){
	IOS;
	for(int i=2;i<=2500;i++){
		if(!np[i])p.pb(i);
		for(auto &j:p){
			if(i*j>2500)break;
			np[i*j]=1;
			if(i%j==0)break;
		}
	}
	
	char c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			arr[i][j] = c-'0';
		}
	}
	for(int i=1;i<=3000;i++){
		for(int j=1;j<=3000;j++){
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + arr[i][j];
			//cout<<i<<" "<<j<<" "<<pre[i][j]<<'\n';
		}
	}
	ll ans = 1e18;
	for(auto i:p){
		if(i>max(n,m)*2)break;
		ans = min(ans,calc(i));
	}
	cout<<ans<<'\n';
}

