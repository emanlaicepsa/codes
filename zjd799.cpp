#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll n,q,st,l,r,v;
ll tr[1000005];
ll tag[500005];
void build(){
	for(int i=n;i<2*n;i++)cin>>tr[i];
	for(int i=n-1;i>0;i--)tr[i]=tr[i<<1]+tr[i<<1|1];
}
void pull(int x){
	int h=1;
	while(x>1){
		tr[x>>1]=tr[x]+tr[x^1]+(tag[x>>1]<<h);
		x>>=1;
		h++;
	}
}
void mod(int x,int p,int h){
	tr[x]+=(p<<h);
	if(x<n)tag[x]+=p;
}
void push(int x){
	for(int h=__lg(x);h>=0;h--){
		int i=(x>>h);
		if(!tag[i>>1])continue;
		mod(i,tag[i>>1],h);
		mod(i^1,tag[i>>1],h);
		tag[i>>1]=0;
	}
}
void add(int l,int r,int v){
	int tl=l,tr=r,h=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1,h++){
		if(l&1)mod(l++,v,h);
		if(r&1)mod(--r,v,h);
	}
	pull(tl+n),pull(tr+n-1);
}
ll query(int l,int r){
	ll res=0;
	push(l+n);
	push(r+n-1);
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1)res+=tr[l++];
		if(r&1)res+=tr[--r];
	}
	return res;
}
signed main(){
	IOS
	cin>>n;
	build();
	cin>>q;
	while(q--){
		cin>>st;
		if(st==1){
			cin>>l>>r>>v;
			l--;
			add(l,r,v);
		}
		else{
			cin>>l>>r;
			l--;
			cout<<query(l,r)<<'\n';
		}
	}
}

