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
map<ll,int> m;
ll arr[500005];
int cnt=0;
void ins(int x){
	m[arr[x]]++;
	if(m[arr[x]]==1)cnt++;
}
void del(int x){
	m[arr[x]]--;
	if(m[arr[x]]==0)cnt--;
}
int main(){
	IOS;
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int l=1,r=0;
	ll ans = 0;
	ll al,ar;
	while(l<=n){
		while(cnt<=k){
			r++;
			if(r==n+1){
				break;	
			}
			ins(r);
		}
		if(r==n+1)r--;
		else del(r--);
		if(r-l+1>ans){
			al= l,ar = r, ans =r-l+1;
		}
		del(l++);
	}
	cout<<al<<" "<<ar<<'\n';
}

