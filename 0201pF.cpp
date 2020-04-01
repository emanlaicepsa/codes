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
int cnt[1000005];
int arr[100005];
unordered_set<int> remain;
int main(){
	ll n,a,x;
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		remain.insert(arr[i]);	
	}
	if(remain.find(a)!=remain.end())remain.erase(a);
	for(int i=1;i<=n;i++){
		cnt[arr[i]]++;
		if(arr[i]==a){
			vector<int> v;
			for(auto j:remain){
				if(cnt[j]<cnt[a]){
					v.pb(j);
				}
			}
			for(auto j:v)remain.erase(j);
		}
	}
	//for(auto i:remain)cout<<i<<'\n';
	if(remain.size())cout<<*remain.begin()<<'\n';
	else cout<<-1<<'\n';


}

