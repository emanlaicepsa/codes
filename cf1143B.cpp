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
ll power(int x,int y){
	ll ans = 1,mul = x;
	while(y){
		if(y&1) ans *= mul;
		mul*=mul;
		y>>=1;
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	ll now = 1;
	ll nmax = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'&&i==0) nmax = power(9,s.size()-1);
		else if(s[i]=='0')break;
		else{
			nmax = max(nmax,now * (s[i]-'0'-1) * power(9,s.size()-i-1));
			now *= s[i]-'0';
		}
	}
	nmax =max(nmax,now);
    cout<<nmax<<'\n';

}

