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
int main(){
	IOS;
	ll a,b;
	cin>>a>>b;
	if(b>a){
		cout<<-1<<'\n';
		return 0;
	}
	ll t1 = a-b , t2 = a+b; 
	double a1,a2;
	if(t1>=b){
		ll k = t1/2/b;
		a1 = t1*1.0/2/k;
	}
	else{
		a1 = 1e9; 
	} 
	ll k = t2/2/b;
	a2 = t2*1.0/2/k;
	cout<<fixed<<setprecision(10)<<min(a1,a2)<<'\n';
}

