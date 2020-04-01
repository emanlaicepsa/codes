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
ll s,x;
ll go(ll bit,ll cs){
	if(bit==-1){
		if(cs==0)return 1;
		return 0;
	}
	if(cs<0)return 0;
	if(x&(1LL<<bit)){
		return 2*(go(bit-1,cs-(1LL<<bit)));
	}
	else{
		if(cs >= (1LL<<(bit+1))){
			return go(bit-1,cs - (1LL<<(bit+1)));
		}
		else{
			return go(bit-1,cs);
		}
	}
}
int main(){
	IOS;
	cin>>s>>x;
	if(x>s)cout<<0<<'\n';
	else{
		ll ans = go(60,s);
		if(s==x)ans-=2;
		cout<<ans<<'\n';
	}
	


}

