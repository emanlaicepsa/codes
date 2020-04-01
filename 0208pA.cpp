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
	int a;
	string s;
	cin>>a;
	cin>>s;
	ll ans = 0;
	int now = 0;
	for(auto i:s){
		if(i=='1'){
			now ++;
		}
		else{
			ans *=10;
			ans +=now;
			now = 0; 
		}
	}
	ans *=10;
	ans +=now;
	cout<<ans<<'\n';


}

