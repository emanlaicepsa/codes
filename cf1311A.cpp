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
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==b){
			cout<<0<<'\n';
		}
		else if(a<b){
			if((b-a)&1)cout<<1<<'\n';
			else cout<<2<<'\n';
		}
		else{
			if((a-b)&1)cout<<2<<'\n';
			else cout<<1<<'\n';
		}
	}


}

