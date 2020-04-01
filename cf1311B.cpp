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
int main(){
	IOS;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>arr[i];
		vector<int> can(m);
		for(int i=0;i<m;i++)cin>>can[i];
		sort(all(can));
		int now = can[0];
		for(int i=0;i<m;i++){
			if(i==m-1||can[i]!=can[i+1]-1){
				sort(arr+now,arr+can[i]+2);
				now = can[i+1];
			}
		}
		bool ok = 1;
		for(int i=2;i<=n;i++){
			if(arr[i]<arr[i-1])ok = 0;
		}
		cout<<(ok?"YES\n":"NO\n");
	}


}

