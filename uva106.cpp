#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
bitset<1000005> used;
int main(){
	IOS;
	ll n;
	while(cin>>n){
		used.reset();
		int cnt1=0,cnt2=0;
		int sqr = sqrt(n);
		for(ll i=2;i<=sqr;i++){
			for(ll j=1;j<=i;j++){
				if(__gcd(i,j)>1)continue;
				ll x = i*i-j*j;
				ll y = 2*i*j;
				ll z = i*i+j*j;
				
				if(z>n)break;
				if(__gcd(x,y)>1)continue;
				//cout<<x<<" "<<y<<" "<<z<<'\n';
				cnt1++;
				ll t = n/z;
				for(int k=1;k<=t;k++){
					used[x*k] = used[y*k] = used[z*k] = 1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!used[i]){
				//cout<<i<<' ';
				cnt2++;
			}
		}
		cout<<cnt1<<" "<<cnt2<<'\n';
		
	}
	
	
	


}

