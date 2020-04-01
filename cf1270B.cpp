#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[200005];

signed main(){
	IOS
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		bool ok=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(ok)continue;
			if(i){
				if(abs(arr[i]-arr[i-1])>=2){
					cout<<"YES\n";
					cout<<i<<" "<<i+1<<'\n';
					ok=1;
				}
			}
		}
		if(!ok)cout<<"NO\n";
	}



}

