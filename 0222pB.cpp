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
ll pre[105];
vector<int> pos;
int main(){
	IOS;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pre[i] = pre[i-1] + arr[i];
		if(arr[i]!=0)pos.pb(i);
	}
	if(pre[n] != 0){
		cout<<"YES\n1\n1 "<<n<<'\n';
		return 0;
	}
	if(pos.size()<=1){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<pos.size()<<'\n';
	int now = 1;
	for(int i=0;i<pos.size()-1;i++){
		cout<<now<<" "<<pos[i]<<"\n";
		assert(pre[pos[i]] - pre[now-1] != 0);
		now = pos[i]+1;
	}
	cout<<now<<" "<<n<<'\n';
	


}

