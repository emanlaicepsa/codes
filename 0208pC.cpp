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
map<ll,int> cnt;
map<ll,int> cnt2;
ll arr[100005];
ll C(ll x,ll y){
	if(y==0)return 1;
	if(y==1)return x;
	if(y==2)return x*(x-1)/2;
	if(y==3)return x*(x-1)*(x-2)/2/3;
}
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=3;i++){
		cnt2[arr[i]] ++;
	}
	for(int i=1;i<=n;i++){
		if(arr[i] > arr[3])break;
		cnt[arr[i]] ++;
	}
	ll ans = 1;
	for(auto i:cnt2){
		ans *= C(cnt[i.fi],cnt2[i.fi]);
	}
	cout<<ans<<'\n'; 

}

