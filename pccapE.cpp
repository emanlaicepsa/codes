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
map<ll,int> m; 
ll n,x;
ll mm(ll x){
	int cnt[10]={0};
	while(x){
		cnt[x%10]++;
		x/=10;
	}
	ll ans = 0 ,cc=0;
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			ans = ans*10 + i;
			cc++;
		}
	}
	while(cc<n){
		ans *=10;
		cc++;
	}
	return ans;
}
ll mi(ll x){
	int cnt[10]={0};
	while(x){
		cnt[x%10]++;
		x/=10;
	}
	ll ans = 0;
	for(int i=0;i<=9;i++){
		while(cnt[i]--){
			ans = ans*10 + i;
		}
	}
	return ans;
}
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		m.clear();	
		m[x] = 0;
		for(int i=0;;i++){
			x = mm(x) - mi(x);
			if(m[x]){
				cout<<i-m[x]<<'\n';
				break;
			}
			m[x] = i;
			//cout<<x<<'\n';	
		}	
	}



}

