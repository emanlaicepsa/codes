#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll

using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
pii arr[1605];


pii operator -(pii &a, pii&b){
	return {a.fi - b.fi , a.se - b.se};
}

ll cross(pii x,pii y){
	return x.fi*y.se - x.se*y.fi;
}

int dim(pii x){
	if(x.fi>=0 && x.se>=0)return 1;
	if(x.fi<=0 && x.se>=0)return 2;
	if(x.fi<=0 && x.se<=0)return 3;
	if(x.fi>=0 && x.se<=0)return 4;
}

bool cmp(int a,int b){
	pii x = arr[a];
	pii y = arr[b];
	if(dim(x)!=dim(y))return dim(x) < dim(y);
	if(cross(x,y))return cross(x,y)>0;
	return x.fi*x.fi < y.fi*y.fi; 
}

double calc(int x,int y){
	return sqrt( (arr[x].fi - arr[y].fi) * (arr[x].fi - arr[y].fi) + (arr[x].se - arr[y].se) * (arr[x].se - arr[y].se)  ); 
}

double dp[805][805];
vector<pii> ans;
vector<int> ord;

void dfs(int i,int j){
	//cout<<i<<" "<<j<<'\n';
	//cout<<dp[i][j]<<'\n';
	if(j-i<=2)return;
	for(int k=i+1;k<j;k++){
		if(dp[i][j] + 1e-9 >= dp[i][k] + dp[k][j] + calc(ord[i],ord[k])*(k!=i+1) + calc(ord[k],ord[j])*(k!=j-1)){
			if(i+1!=k){
				ans.pb({ord[i],ord[k]});
			}
			if(k+1!=j){
				ans.pb({ord[k],ord[j]});
			}
			dfs(i,k);
			dfs(k,j);
			break;
		}
	}
}

signed main(){
	//IOS;
	int n;
	cin>>n;
	ll sx=0,sy=0;
	for(int i=0;i<n;i++){
		cin>>arr[i].fi>>arr[i].se;
		sx += arr[i].fi;
		sy += arr[i].se;
	}
	sx /= n;
	sy /= n;
	sx++;
	sy++;
	for(int i=n-1;i>=0;i--){
		arr[i].fi -= arr[0].fi;
		arr[i].se -= arr[0].se;
	}
	
	
	for(int i=0;i<n;i++)ord.pb(i);
	sort(all(ord),cmp);
	
	/*for(int i=0;i<n;i++){
		cout<<ord[i]<<'\n';
	}*/
	
	for(int i=0;i<800;i++)
		for(int j=0;j<800;j++)
			dp[i][j] = 1e18;
			
	for(int i=0;i<n;i++){
		dp[i][i] = dp[i][i+1] = dp[i][i+2] = 0;
	}
	
	
	for(int l=3;l<n;l++){
		for(int i=0;i+l<n;i++){
			int j = i+l;
			for(int k=i+1;k<j;k++){
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] + calc(ord[i],ord[k])*(k!=i+1) + calc(ord[k],ord[j])*(k!=j-1));
			}
			
		}
	}
	
	dfs(0,n-1);
	//cout<<cmin<<'\n';
	for(auto i:ans){
		//if(i.fi + 1 == i.se) continue;
		cout<<i.fi<<" "<<i.se<<'\n';
	}
	
}
/*
5
0 0
1 1
2 3
4 9
2 26
*/ 
