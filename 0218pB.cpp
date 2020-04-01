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

struct tree{
	int l;
	int r;
	int val;
}tr[200005];

ll rt[10005];
ll arr[10005];
int idx;

int init(int l,int r){
	int nd = idx++;
	if(l==r){
		tr[nd].val = 0;
		return nd;
	}
	int m = (l+r)>>1;
	tr[nd].l = init(l,m);
	tr[nd].r = init(m+1,r);
	tr[nd].val = tr[ tr[nd].l ].val + tr[ tr[nd].r ].val;
	return nd;
}

int build(int anc,int l,int r,int id){
	int nd = idx++;
	tr[nd] = tr[anc];
	if(l==r){
		tr[nd].val++;
		return nd;
	}
	int m = (l+r)>>1;
	if(id<=m){
		tr[nd].l = build(tr[anc].l,l,m,id);
	}
	else{
		tr[nd].r = build(tr[anc].r,m+1,r,id);
	}
	tr[nd].val = tr[ tr[nd].l ].val + tr[ tr[nd].r ].val;
	return nd;
}

int query(int ql,int qr,int l,int r,int idx){
	if(l==r){
		return l;
	}
	int dif = tr[ tr[qr].l ].val - tr[ tr[ql].l ].val;
	int m = (l+r)>>1;
	if(dif >= idx){
		return query(tr[ql].l,tr[qr].l,l,m,idx);
	}
	else{
		return query(tr[ql].r,tr[qr].r,m+1,r,idx - dif);
	}
}

int main(){
	IOS;
	ll n,q,l,r,k;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	rt[0] = init(1,n);
	for(int i=1;i<=n;i++){
		rt[i] = build(rt[i-1],1,n,arr[i]);
	}
	
	while(q--){
		cin>>l>>r>>k;
		ll x = query(rt[l-1],rt[r],1,n,k-l+1);
		//cout<<x<<'\n';
		if(x == arr[k]){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}

}

