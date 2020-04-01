#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
stack<int> stk;
const int maxn=1000005;
int arr[maxn];
int le[maxn];
int ri[maxn];
vi E[maxn];
ll ans[maxn];
ll siz[maxn];
ll num[maxn];
ll n;

void dfs(int nd,int p){
	ans[nd]=n*(n-1);
	siz[nd]=1;
	for(auto i:E[nd]){
		if(i==p)continue;
		//cout<<i<<'\n';
		dfs(i,nd);
		siz[nd]+=siz[i];
		ans[nd]-=siz[i]*(siz[i]-1);
	}
	ll le=n-siz[nd];
	ans[nd]-=le*(le-1);
}

int main(){
	IOS;
	cin>>n;
	rep1(i,n)cin>>arr[i],num[arr[i]]=i;
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&stk.top()<arr[i])stk.pop();
		if(stk.empty())le[arr[i]]=0;
		else le[arr[i]]=stk.top();
		stk.push(arr[i]);
	}
	while(!stk.empty())stk.pop();
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&stk.top()<arr[i])stk.pop();
		if(stk.empty())ri[arr[i]]=0;
		else ri[arr[i]]=stk.top();
		stk.push(arr[i]);
	}
	for(int i=1;i<=n;i++){
		
		if((le[i]!=0)||(ri[i]!=0)){
			if(!le[i])E[ri[i]].pb(i),E[i].pb(ri[i]);
			else if(!ri[i])E[le[i]].pb(i),E[i].pb(le[i]);
			else {
				if(le[i]<ri[i]){
					E[le[i]].pb(i),E[i].pb(le[i]);
				}
				else{
					E[ri[i]].pb(i),E[i].pb(ri[i]);
				}
			}
		}
		//cout<<i<<" "<<le[i]<<" "<<ri[i]<<'\n';
	}
	ll curans=-1;
	int curnd=0;
	dfs(1,0);
	rep1(i,n){
		
		//cout<<ans[i]<<'\n';
		if(ans[i]>curans){
			curans=ans[i];
			curnd=num[i];
		}
		else if(ans[i]==curans&&num[i]<curnd){
			curnd=num[i];
		}
	} 
	assert(curnd!=0);
	cout<<curans<<" "<<curnd<<'\n';
}

