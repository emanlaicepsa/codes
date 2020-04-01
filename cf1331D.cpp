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
	int a;
	cin>>a;
	ll ans = 1;
	for(int i=1;i*i<=a;i++){
		if(!(a%i)) ans = i;
	} 
	cout<<ans<<a/ans<<'\n'; 

}

