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
ll ha[200005];
ll hb[200005];
const ll mod = 1000000007;
int cnt = 0;
double st;
ll p(ll x,ll y){
	ll ans = 1, m = x;
	while(y){
		if(y&1) ans = (ans * m) % mod;
		m = (m*m) % mod;
		y>>=1;
	}
	return ans;
}
ll gha(ll l,ll r){
	if(l==0)return ha[r];
	ll ans = ha[r] - ha[l-1]*p(93,r-l+1);
	ans %= mod;
	if(ans <0) ans += mod;
	return ans;
}
ll ghb(ll l,ll r){
	if(l==0) return hb[r];
	ll ans = hb[r] - hb[l-1]*p(93,r-l+1);
	ans %= mod;
	if(ans <0) ans += mod;
	return ans;
}
bool ok(int la,int lb,int lc,int ld){
	cnt ++;
	if( (clock() - st )/CLOCKS_PER_SEC > 1.0 ) return 1;
	if(gha(la,lb) == ghb(lc,ld))return 1;
	int siz = lb - la + 1;
	if(siz & 1)return 0;
	siz >>= 1;
	return (ok(la,la+siz-1,lc,lc+siz-1) && ok(la+siz,lb,lc+siz,ld))  || ( ok(la,la+siz-1,lc+siz,ld) && ok(la+siz,lb,lc,lc+siz-1) );
}
string qq(string a){
	//cout<<a<<'\n';
	int siz = a.size();
	if(siz &1)return a;
	siz>>=1;
	string s1 = qq(a.substr(0,siz)),s2 = qq(a.substr(siz));
	if(s1 > s2){
		swap(s1,s2);
	} 
	return s1 + s2;
}
int main(){
	string a,b;
	cin>>a>>b; 
	st = clock();
	int siz = a.size();
	ha[0] = a[0] -'a';
	hb[0] = b[0] -'a';
	for(int i=1;i<siz;i++){
		ha[i] = ha[i-1] * 93 + (a[i] - 'a');
		ha[i] %= mod;
		hb[i] = hb[i-1] * 93 + (b[i] - 'a');
		hb[i] %= mod;
	}
	
	if(qq(a) == qq(b)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
}

