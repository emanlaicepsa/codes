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

long double pw(long double x,ll y){
	long double ans = 1, m = x;
	while(y){
		if(y&1)ans*=m;
		m*=m;
		y>>=1;
	}
	return ans;
}

int main(){
	IOS;
	long double n;
	ll y;
	cin>>n>>y;
	cout<<fixed<<setprecision(7)<<n*pw(1.000000011,y)<<'\n';


}

