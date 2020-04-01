#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int sol[6];
int v[6];
int p[6];
int sc[6] = {3000,2500,2000,1500,1000,500};
int ar[6] = {32,16,8,4,2,1};
int n,x;
ll ans(int id,int add,int num){
	//cout<<id<<" "<<add<<" "<<num<<'\n';
	int ac = sol[id] + add*num;
	int all = n + num;
	for(int i=0;i<6;i++){
		if(ac*ar[i] <= all){
			//cout<<ac<<" "<<all<<" "<<sc[i]<<'\n';
			return sc[i];
		}
	}
	while(1);
	return -1;
}

ll ok(ll x){
	ll sv = 0,sp = 0;
	for(int i=1;i<=5;i++){
		if(v[i]>-1 && p[i]>-1){
			//cout<<"$"<<i<<
			if(v[i] < p[i]){
				int maxsc = ans(i,0,x);
				sv += maxsc - maxsc * v[i] / 250;
				sp += maxsc - maxsc * p[i] / 250; 
			}
			else{
				int maxsc = ans(i,1,x);
				sv += maxsc - maxsc * v[i] / 250;
				sp += maxsc - maxsc * p[i] / 250; 
			}
		}
		else if(v[i] > -1){
			int maxsc = ans(i,0,x);
			sv += maxsc - maxsc * v[i] / 250;
		}
		else if(p[i] > -1){
			int maxsc = ans(i,0,x);
			sp += maxsc - maxsc * p[i] / 250; 
		}
	}
	return sv - sp;
}
signed main(){
	
	IOS;
	cin>>n;
	for(int j=1;j<=5;j++){
		cin>>v[j];
		if(v[j]>-1)sol[j]++;
	}
	for(int j=1;j<=5;j++){
		cin>>p[j];
		if(p[j]>-1)sol[j]++;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=5;j++){
			cin>>x;
			if(x>-1){
				sol[j]++;
			}
		}
	}
	
	for(int i=0;i<=5000;i++){
		if(ok(i) > 0){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';
	return 0;
	/*ll l = 0,r = 1e9 +7;
	while(l<r){
		ll m = (l+r)>>1;
		ll ta = ok(m);
		if(ok(m)>0){
			r=m;
		}
		else{
			ll tb = ok(m+1);
			if(tb>ta){
				l = m+1;
			}
			else r = m;
		}
	}
	cout<<l<<'\n';*/

}

