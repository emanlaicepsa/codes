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
bool has[20];
int main(){
	int n,k,a;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int ans = 0;
		for(int j=0;j<k;j++){
			cin>>a;
			ans |= a*(1<<j);
		}
		//cout<<ans<<'\n';
		has[ans]=1;
	}
	bool ok = 0;
	if(has[0])ok = 1;
	for(int i=1;i<(1<<k);i++){
		if(has[i]){
			for(int j = 0;j<(1<<k);j++){
				if(has[j] && i+j == (i^j))ok = 1;
			}
		}
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";

}

