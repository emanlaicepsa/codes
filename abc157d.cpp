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
int cnt[100005];
vector<int> hate[100005];
int pa[100005];
int siz[100005];

int fp(int x){
	if(x==pa[x])return x;
	return pa[x] = fp(pa[x]);
}

void merge(int x,int y){
	x = fp(x) , y = fp(y);
	if(x == y)return;
	if(siz[x] < siz[y]) swap(x,y);
	siz[x] += siz[y];
	pa[y] = x;
}



int main(){
	IOS;
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) pa[i] = i , siz[i] = 1;
	for(int i=1,a,b;i<=m;i++){
		cin>>a>>b;
		cnt[a] ++;
		cnt[b] ++;
		merge(a,b);
	}
	for(int i=1,a,b;i<=k;i++){
		cin>>a>>b;
		hate[a].pb(b);
		hate[b].pb(a);
	}
	
	for(int i=1;i<=n;i++){
		ll ta = siz[fp(i)];
		ta = ta - 1 - cnt[i];
		for(auto x:hate[i]){
			if(fp(x) == fp(i)){
				ta--;
			}
		}
		cout<<ta<<" \n"[i==n];
	}
	
}

