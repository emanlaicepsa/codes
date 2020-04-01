#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
pii extgcd(ll a,ll b){
	if(b==0)return {1,0};
	pii tmp = extgcd(b,a%b);
	if(a*b<0) tmp.fi*=-1,tmp.se*=-1;
	//cout<<"^"<<a<<" "<<b<<" "<<tmp.se<<" "<<tmp.fi - a/b*tmp.se<<'\n';
	return {tmp.se , tmp.fi - a/b*tmp.se};
}
ll a[100005],m[100005];
int main(){
	IOS;
	int n;
	mt19937 mt(clock());
	uniform_int_distribution<int> ud(0,10000);
	int t;
	cin>>t;
	while(t--){
		n = 2;
		for(int i=0;i<n;i++)cin>>m[i]>>a[i];
		
		ll ans = m[0];
		ll lcm = a[0];
		for(int i=1;i<n;i++){
			ll gcd = __gcd(lcm,a[i]);
			
			if((m[i]-ans) % gcd){
				ans = -1;
				break;
			} 
			
			ll tim = (m[i]-ans) / gcd;
			pii x = extgcd(lcm,-a[i]);
			x.fi = x.fi % a[i] * tim % a[i];
			
			ans = lcm * x.fi + ans;
			//cout<<ans<<'\n';
			lcm = lcm  / gcd * a[i];
			ans = (ans%lcm+lcm)%lcm;
			
			//cout<<lcm<<" "<<ans<<'\n';
		}
		if(ans>0){
			for(int i=0;i<n;i++){
				assert(ans%a[i]==m[i]);
			} 
			cout<<ans<<" "<<lcm<<'\n';
		} 
		else{
			cout<<"no solution\n";
		}
	} 
	/* 
	5
	53 5
	37 25
	19 13
	59 45
	43 40
	*/ 

}

