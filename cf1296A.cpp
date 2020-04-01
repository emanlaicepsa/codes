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
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		bool odd = 0 ,even = 0;
		for(int i=0;i<n;i++){
			cin>>a;
			if(a&1)odd = 1;
			else even = 1;
		}
		if(odd && even)cout<<"YES\n";
		else if((n&1) && odd) cout<<"YEs\n";
		else cout<<"NO\n";
	}
	


}

