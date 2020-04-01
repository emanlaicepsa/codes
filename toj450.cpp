#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	ll c;
	cin>>c;
	c/=2;
	ll x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	ll x4=x2-x1;
	ll y4=y2-y1;
	ll x5=x3-x1;
	ll y5=y3-y1;
	ll ans=abs(x4*y5-y4*x5);
	ans*=c;
	cout<<ans<<'\n';
	


}

