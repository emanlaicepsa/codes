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
ll dp1[500005];
ll dp2[500005];
ll arr[500005];
ll l[500005];
ll r[500005];
stack<ll> s;
int main(){
	IOS;
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	arr[0] = 0;
	s.push(0);
	for(int i=1;i<=n;i++){
		while(arr[s.top()] > arr[i])s.pop();
		l[i] = s.top();
		dp1[i] = dp1[s.top()] + (i-s.top()) * arr[i];
		s.push(i);
	}
	while(!s.empty())s.pop();
	
	arr[n+1] = 0;
	s.push(n+1);
	for(int i=n;i>=1;i--){
		while(arr[s.top()] > arr[i])s.pop();
		r[i] = s.top();
		dp2[i] = dp2[s.top()] + (s.top() - i) * arr[i];
		s.push(i);
	}
	
	ll cur = 0, id = -1;
	for(int i=1;i<=n;i++){
		if(dp1[i] + dp2[i] - arr[i] > cur){
			cur = dp1[i] + dp2[i] - arr[i];
			id = i;
		}
	}
	
	vector<int> ans;
	ll idx = id;
	while(idx!=0){
		for(int i=l[idx]+1;i<=idx;i++)ans.pb(arr[idx]);
		idx = l[idx];
	}
	reverse(all(ans));
	ans.pop_back();
	idx = id;
	while(idx!=n+1){
		for(int i=idx;i<r[idx];i++)ans.pb(arr[idx]);
		idx = r[idx];
	}
	for(auto i:ans)cout<<i<<" ";
	


}

