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
int psum[1000005];
int main(){
	IOS;
	string a,b;
	cin>>a>>b;
	a = " "+a;
	int sa = a.size(),sb = b.size();
	for(int i=1;i<sa;i++){
		psum[i] = psum[i-1] + (a[i]=='1');
	}
	int x = 0;
	for(auto i:b){
		x += i=='1';
	}
	ll ans =0;
	for(int i=sb;i<sa;i++){
		ans += (psum[i] - psum[i-sb] - x )&1^1 ;
	}
	cout<<ans<<'\n';
}

