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
int tag[4000005];
int le[4000005];
struct edge{
	ll sx;
	ll sy;
	ll ey;
	int add;
};
vector<edge> v;
void modify(int l,int r,int ql,int qr,int ad,int id){
	int m=(l+r)>>1;
	if(ql<=l&&qr>=r){
		tag[id]+=ad;
		if(tag[id])le[id]=r-l+1;
		else if(r-l)le[id]=le[id<<1]+le[id<<1|1];
		else le[id]=0;
	}
	else{	
		if(ql<=m)modify(l,m,ql,qr,ad,id<<1);
		if(qr>m)modify(m+1,r,ql,qr,ad,id<<1|1);
		if(tag[id])le[id]=r-l+1;
		else{
			le[id]=le[id<<1]+le[id<<1|1];
		}
	}
	
	//cout<<l<<" "<<r<<" "<<le[id]<<'\n';
}
int main(){
	IOS
	ll n,a,b,c,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d;
		v.pb({a,c,d,1});
		v.pb({b,c,d,-1});
	}
	sort(all(v),[](edge &a,edge &b){
		return a.sx<b.sx;
	});
	ll now=0;
	ll ans=0;
	for(auto i:v){
		ans+=(i.sx-now)*le[1];
		//cout<<le[1]<<'\n';
		now=i.sx;
		modify(0,1000000,i.sy,i.ey-1,i.add,1);
	}
	cout<<ans<<'\n';


}

