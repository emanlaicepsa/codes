#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
ll dp[200005];
ll r[200005];
pii arr[200005];
stack<int> stk;
bool cmp(pii &a,pii &b){
	return (a.fi<b.fi);
}
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].fi>>arr[i].se;
		arr[i].se += arr[i].fi;
	}
	sort(arr+1,arr+1+n,cmp);
	arr[n+1] = {1e18,2e18};
	dp[n+1] = 1;
	stk.push(n+1);
	for(int i=n;i>=1;i--){
		//cout<<arr[i].fi<<" "<<arr[i].se<<'\n';
		while(arr[i].se > arr[stk.top()].fi) stk.pop();
		r[i] = stk.top();
		stk.push(i);
		dp[i] = dp[i+1] + dp[r[i]];
		//cout<<r[i]<<" "<<dp[i]<<'\n';
		dp[i] %= 998244353;
	}
	cout<<dp[1]<<'\n';

}

