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
ll dig(ll x){
	int ans = 0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main(){
	IOS;
	ll n,s;
	cin>>n>>s;
	ll i;
	ll cnt = 0;
	for(i=s;i<=s+200;i++){
		if(i>n)break;
		if(i - dig(i) >= s){
			cnt++;
		}
	}
	if(i<n){
		cnt += n-i+1;
	}
	cout<<cnt<<'\n';
}

