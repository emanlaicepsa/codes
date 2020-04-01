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
ll md[100005];
ll md2[100005];
ll mc[100005];
ll mc2[100005];
ll quec(int pos){
	ll ans = 0;
	for(int i=pos;i;i-=(i&-i)){
		ans = max(ans,mc[i]);
	}
	return ans;
}
ll qued(int pos){
	ll ans = 0;
	for(int i=pos;i;i-=(i&-i)){
		ans = max(ans,md[i]);
	}
	return ans;
}
void modc(int pos,ll x){
	for(int i=pos;i<=100000;i+=(i&-i)){
		mc[i] = max(mc[i],x);
	}
}
void modd(int pos,ll x){
	for(int i=pos;i<=100000;i+=(i&-i)){
		md[i] = max(md[i],x);
	}
}
int main(){
	IOS;
	int n,c,d;
	cin>>n>>c>>d;
	char ope;
	for(ll i=0,val,cost;i<n;i++){
		cin>>val>>cost>>ope;
		if(ope == 'D'){
			if(cost>d)continue;
			ll x = qued(d-cost);
			if(x) md2[d] = max(md2[d] , x + val);
			modd(cost,val);
		}
		else{
			if(cost>c)continue;
			ll x = quec(c-cost);
			if(x) mc2[c] = max(mc2[c], x + val);
			modc(cost,val);
		}
	}
	ll ans = 0;
	for(int i=1;i<=c;i++){
		mc[i] = max(mc[i],mc[i-1]);
	}
	for(int i=1;i<=d;i++){
		md[i] = max(md[i],md[i-1]); 
	}
	
	if(mc[c]&&md[d]){
		ans = mc[c] + md[d];
	}
	//cout<<ans<<'\n';
	//ll ans = 
	
	for(int i=1;i<=c;i++){
		ans = max(ans,mc2[i]);
	}
	
	for(int i=1;i<=d;i++){
		ans = max(ans,md2[i]);
	}
	cout<<ans<<'\n';

}

