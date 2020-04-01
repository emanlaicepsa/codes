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
ll arr[200005];
bool exi[200005];
int rem[200005];
ll pa[200005];
ll mv[200005];
ll siz[200005];
ll ans[200005];
ll cans;

int fp(int x){
	if(x==pa[x])return x;
	return pa[x] = fp(pa[x]);
}
void merge(int x,int y){
	//cout<<x<<" "<<y<<'\n';
	x= fp(x); y = fp(y);
	if(x==y)return;
	if(siz[x] < siz[y]) swap(x,y);
	pa[y] = x;
	siz[x] += siz[y];
	mv[x] = max(mv[x],mv[y]);
	cans = max(cans,siz[x] * mv[x]);
}


int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		exi[i] = 1;
		pa[i] = i;
		siz[i] = 1;
		mv[i] = arr[i];
		//cans = max(cans,arr[i]);
	} 
	for(int i=m;i>=1;i--){
		cin>>rem[i];
		exi[rem[i]] = 0;
	}
	for(int i=1;i<=n;i++){
		if(exi[i]) cans = max(cans,arr[i]);
	}
	for(int i=2;i<=n;i++){
		if(exi[i] && exi[i-1]) merge(i,i-1);
	}
	ans[m] = cans;
	for(int i=1;i<=m;i++){
		exi[rem[i]] = 1;
		cans = max(cans,arr[rem[i]]);
		if(exi[rem[i]-1]) merge(rem[i],rem[i]-1);
		if(exi[rem[i]+1]) merge(rem[i],rem[i]+1);
		ans[m-i] = cans;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" \n"[i==m];
	}

}

