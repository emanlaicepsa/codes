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
ll arr[200005];
int main(){
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] %= (a+b);
		if(arr[i]==0)arr[i] += (a+b);
		arr[i] = (arr[i]-1)/a;
	}
	sort(arr+1,arr+1+n);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(k<arr[i])break;
		cnt++;
		k -= arr[i];
	}
	cout<<cnt<<'\n';
}

