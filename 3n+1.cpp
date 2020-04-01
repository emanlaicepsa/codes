#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll num[1000005];
ll ma[4000005];
ll go(ll x){
	//if(x<0||x>1000000)	cout<<x<<'\n';
	if(x==1)return 0;
	if(x<=1000000&&num[x])return num[x];
	if(x<=1000000&&(x&1))return num[x]=1+go(3*x+1);
	if(x<=1000000&&!(x&1))return num[x]=1+go(x/2);
	if(x%2)return 1+go(3*x+1);
	return 1+go(x/2);	
} 

void build(int l,int r,int idx){
	if(l==r){
		ma[idx]=num[l];
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,idx<<1);
	build(m+1,r,idx<<1|1);
	ma[idx]=max(ma[idx<<1],ma[idx<<1|1]);
}

ll query(int l,int r,int ql,int qr,int idx){
	if(l>=ql&&r<=qr)return ma[idx];
	int m=(l+r)>>1;
	if(m>=qr)return query(l,m,ql,qr,idx<<1);
	if(m<ql)return query(m+1,r,ql,qr,idx<<1|1);
	return max(query(l,m,ql,qr,idx<<1),query(m+1,r,ql,qr,idx<<1|1));
}


int main(){
	IOS;
	num[1]=0;
	for(ll i=2;i<1000005;i++){
		if(num[i])continue;
	//	if(i%10000==0)cout<<i<<'\n';
		num[i]=go(i);
	}
	
	build(1,1000000,1);
	int n,m;
	while(cin>>n>>m){
		cout<<n<<" "<<m<<" ";
		if(n>m)swap(n,m);
		cout<<query(1,1000000,n,m,1)+1<<'\n';
	}
	

}

