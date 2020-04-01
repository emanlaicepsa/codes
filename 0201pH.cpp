#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define double long double
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int n,k;
double l,v1,v2;
bool ok(double x){
	double now = 0;
	double t = 0;
	double tmp;
	double pos;
	double cur = n;
	while(cur>0){
		if(t + (l - now) / v1 <= x)return 1;
		pos = ((x - t) * v1 * v2 - (v2*l) +(v1*now)) / (v1-v2) ;
		cout<<pos<<' ';
		tmp = (pos  - now) / v2;
		now += tmp * v1;
		t += tmp;
		cout<<t<<"\n";
		cur-=k;
		if(t>x)return 0;
	}
	cout<<x<<" "<<t<<'\n';
	return (t<=x);
}
int main(){
	cin>>n>>l>>v1>>v2>>k;
	double L = 0, R = 1e14;
	ok(4.5);
/*	while(R-L>1e-7){
		double M = (L + R) / 2;
		if(ok(M))R=M;
		else L=M;
	}*/
	cout<<fixed<<setprecision(8)<<L<<'\n';


}

