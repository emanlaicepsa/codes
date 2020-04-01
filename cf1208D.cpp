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
ll bit[200005];
ll arr[200005]; 
ll ans[200005];
ll n;
inline void add(int p,int val){
	for(int i=p;i<=n;i+=(i&-i))bit[i] += val;
}
int getp(ll val){
	int now = 0;
	for(int i=__lg(n);i>=0;i--){
		if(now + (1<<i) > n) continue;
		if(val >= bit[now+(1<<i)]){
			val -= bit[now+(1<<i)];
			now += (1<<i);
		}
	}
	return now +1;
}
int main(){
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		add(i,i);
	}
	for(int i=n;i>=1;i--){
		int p = getp(arr[i]);
		ans[i] = p;
		add(p,-p);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" \n"[i==n];
	}
}

