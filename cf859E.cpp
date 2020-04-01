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
int pa[200005];
bool used[200005];
int cir[200005];
const ll mod = 1000000007;
bool vis[200005];
ll siz[200005];

int fp(int x){
	if(x==pa[x])return x;
	return pa[x] = fp(pa[x]);	
}

void merge(int a,int b){
	if(a==b){
		cir[fp(a)] = 1;
		return;
	}
	a = fp(a) ,b = fp(b);
	if(a == b){
		cir[a] = 2;
		return;
	}
	pa[a] = b;
	siz[b] += siz[a];
}

int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++){
		pa[i] = i;
		siz[i] = 1;
	}
	for(int i=1,a,b;i<=n;i++){
		cin>>a>>b;
		used[a] = 1;
		used[b] = 1;
		merge(a,b);
	}
	ll ra = 1;
	for(int i=1;i<=2*n;i++){
		if(used[i]){
			int p = fp(i);
			if(!vis[p]){
				vis[p] = 1;
				if(cir[p]){
					ra *= cir[p];
					ra %= mod;
				}
				else{
					ra *= siz[p];
					ra %= mod;
				}
			}
			
		}
	}
	cout<<ra<<'\n';
}

