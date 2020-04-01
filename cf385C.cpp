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
vector<ll> pri;
bool np[10000005];
int mp[10000005];
int cnt[1000005];
unordered_map<int,int> num;
int main(){
	IOS;
	for(ll i=2;i<=10000000;i++){
		if(!np[i])pri.pb(i),mp[i] = i;
		for(auto j:pri){
			if(i*j > 10000000)break;
			np[i*j] = 1;
			mp[i*j] = j;
			if(i%j==0)break;
		}
	}
	//cout<<pri.size()<<'\n';
	int idx = 1;
	for(auto i:pri){
		num[i] = idx++;
	}
	int n,tp;
	cin>>n;
	while(n--){
		cin>>tp;
		while(tp>1){
			int bp = mp[tp];
			cnt[num[bp]] ++;
			while(tp%bp==0)tp/=bp;
		}
	}
	for(int i=1;i<=700000;i++){
		cnt[i] += cnt[i-1];
	}
	int q,a,b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		int x = lower_bound(all(pri),a) - pri.begin() +1;
		int y = upper_bound(all(pri),b) - pri.begin();
		//cout<<x<<" "<<y<<'\n';
		cout<<cnt[y] - cnt[x-1]<<'\n';
	}
	


}

