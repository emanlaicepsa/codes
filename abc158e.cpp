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
ll cnt[10005];

int n,p;
string s;

ll power(int x,int y){
	ll mul = x;
	ll ans = 1;
	while(y){
		if(y&1)ans = ans * mul % p;
		mul= mul* mul % p;
		y>>=1;
	}
	return ans;
}

ll calc(ll now,ll idx){
	ll mul = n-idx;
	return now * power(10,mul)  % p	;
}

int main(){
	IOS;
	cin>>n>>p;
	cin>>s;
	s = " " + s;
	
	if(p!=2 && p!=5){
		ll now = 0, ans = 0;
		cnt[0] ++;
		for(int i=1;i<=n;i++){
			now = (now * 10 + (s[i]-'0')) %p;
			ll tmp = calc(now,i);
			ans += cnt[tmp];
			cnt[tmp]++;
		}
		cout<<ans<<'\n';
	}
	else if(p==2){
		ll ans = 0;
		for(int i=1;i<=n;i++){
			if((s[i]-'0')%2 == 0) ans += i;
		}
		cout<<ans<<'\n';
	}
	else{
		ll ans = 0;
		for(int i=1;i<=n;i++){
			if((s[i]-'0')%5 == 0) ans += i;
		}
		cout<<ans<<'\n';
	}


}

