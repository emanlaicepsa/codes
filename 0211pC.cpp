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
vector<int> v;
ll arr[2005];
int main(){
	IOS;
	ll k,n;
	cin>>k>>n;
	v.resize(k);
	for(int i=0;i<k;i++){
		cin>>v[i];
		if(i) v[i] += v[i-1];
	}
	ll x = v[0];
	for(auto &i:v){
		//cout<<i<<'\n';
		i -= x;
	}
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	x = arr[0];
	for(int i=0;i<n;i++){
		arr[i] -= x;
	}
	int ans = 0;
	int siz = v.size();
	for(int i=0;i<siz;i++){
		bool ok = 1;
		int dif = v[i] - arr[0];
		
		int j = i+1;
		int now = 1;
		while(now < n){
			while(j < siz && v[j] < arr[now] + dif)j++;
			if(j == siz || v[j] != arr[now] + dif){
				ok = 0;
				break;
			}
			//cout<<now<<" "<<j<<'\n';
			now ++;
		}
		
		if(ok) ans++;
	}
	cout<<ans<<'\n';
}

