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
ll n;
ll arr[200005];
vector<int> v;
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		v.clear();
		ll cans = 0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			if(arr[i] == -1)continue;
			bool pushed = 0;
			if(i>1){
				if(arr[i-1] == -1){
					v.pb(arr[i]);
					pushed = 1;
				}
			}
			
			if(!pushed && i<n){
				if(arr[i+1] == -1){
					v.pb(arr[i]);
				}
			}
		}
		sort(all(v));
		int siz = v.size();
		int aa;
		if(siz){
			aa = (v[0] + v[siz-1]) / 2;
		}
		else aa = 0;
		for(int i=1;i<=n;i++){
			if(arr[i] == -1) arr[i] = aa;
			if(i>1) cans = max(cans, abs(arr[i]-arr[i-1]));
		}
		cout<<cans<<' ';
		cout<<aa<<'\n';
		
	}


}

