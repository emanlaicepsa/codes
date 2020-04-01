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
ll arr[105];
ll used[205];
ll ans[205];
int main(){
	IOS;
	ll t,n;
	cin>>t;
	while(t--){
		bool ok = 1;
		memset(used,0,sizeof(used));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			used[arr[i]] = 1;
		}
		for(int i=1;i<=n;i++){
			ans[2*i-1] = arr[i];
			int idx = arr[i]+1;
			while(used[idx])idx++;
			if(idx>2*n){
				ok = 0;
				break;
			}
			used[idx] = 1;
			ans[2*i] = idx;
		}
		if(ok){
			for(int i=1;i<=2*n;i++){
				cout<<ans[i]<<" \n"[i==2*n];
			}
		}
		else{
			cout<<-1<<'\n';
		}
	}


}

