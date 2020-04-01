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
	int val;
	int l;
	int r;
	tree(){
		val = 0;
		l = 0;
		r = 0;
	}
}tr[5000005];

int now;
int arr[100005];
int cnt[100005];
int rt[100005];
deque<int> ord[100005];

int modify(int old,int pos,int l,int r,int va){
	int nx = ++now;
	tr[nx] = tr[old];
	int m = (l+r)>>1;
	if(l==r){
		tr[nx].val += va;
		return nx;
	}
	if(pos <= m){
		tr[nx].l = modify(tr[old].l,pos,l,m,va);
	}
	else{
		tr[nx].r = modify(tr[old].r,pos,m+1,r,va);
	}
	tr[nx].val = tr[tr[nx].l].val + tr[tr[nx].r].val;
	//cout<<nx<<" "<<l<<" "<<r<<" "<<tr[nx].val<<'\n';
	return nx;
}

int query(int nx,int l,int r,int ql,int qr){
	//cout<<nx<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<'\n';
	if(ql<=l&&r<=qr){
		return tr[nx].val;
	}
	int m = (l+r)>>1;
	if(qr<=m){
		return query(tr[nx].l,l,m,ql,qr);
	}
	if(ql>m){
		return query(tr[nx].r,m+1,r,ql,qr);
	}
	return query(tr[nx].l,l,m,ql,qr) + query(tr[nx].r,m+1,r,ql,qr);
}

int main(){
	IOS;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	for(int i=1;i<=n;i++){
		rt[i] = modify(rt[i-1],i,1,n,1);
		ord[arr[i]].pb(i);
		if(ord[arr[i]].size() > k){
			rt[i] = modify(rt[i],ord[arr[i]][0],1,n,-1);
			ord[arr[i]].pop_front();
		}
		//cout<<rt[i]<<'\n';
	}
	
	int m;
	int last = 0;
	cin>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		a = (a+last) %n +1;
		b = (b+last) %n +1;
		if(a>b)swap(a,b);
		//cout<<a<<" "<<b<<'\n';
		last = query(rt[b],1,n,a,b);
		cout<<last<<'\n'; 
	}
}

