#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<int> p;
bool np[1000005];
ll arr[1000005];
unordered_map<int,int> cnt;
int main(){
	np[1]=1;
	for(ll i=1;i<=1000005;i++)arr[i]=i;
	for(ll i=2;i<=1000005;i++){
		if(np[i])continue;
		for(ll j=i*i;j<=1000005;j+=i){
			arr[j]=min(arr[j],i);
			np[j]=1;
		}
	}
	
	int t;
	cin>>t;
	int a,b;
	while(t--){
		cnt.clear();
		cin>>a>>b;
		while(a>1){
			if(cnt.find(arr[a])==cnt.end()){
				cnt[arr[a]]=1;
			}
			else cnt[arr[a]]++;
			a/=arr[a];
		}
		while(b>1){
			if(cnt.find(arr[b])==cnt.end()){
				cnt[arr[b]]=1;
			}
			else cnt[arr[b]]++;
			b/=arr[b];
		}
		int ans=1;
		for(auto &i: cnt){
			ans*=(i.second+1);
		}
		cout<<ans<<'\n';
	}
	


}

