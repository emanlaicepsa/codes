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
int arr[1000005];
unordered_map<int,int> cnt;
unordered_map<int,int> cnt2;
int bit[1000005];
void add(int x,int num){
	for(int i=x;i<=1000000;i+=(i&-i))bit[i]+=num;
}
ll que(int x){
	ll ans = 0;
	for(int i=x;i;i-=(i&-i))ans += bit[i];
	return ans;
}
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=n;i>=1;i--){
		cnt[arr[i]] ++;
		add(cnt[arr[i]],1);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		add(cnt[arr[i]],-1);
		cnt2[arr[i]]++;
		cnt[arr[i]] -- ;
		ans += que(cnt2[arr[i]]-1);
	}
	cout<<ans<<'\n';


}

