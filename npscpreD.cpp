#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[5005];
ll co[5005];

int main(){
	ll n,k;
	cin>>n>>k;
	ll ans=(ll)1e50;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==k){
			cout<<0<<'\n';
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		cin>>co[i];
		if(arr[i]>k){
			ans=min(ans,co[i]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==k){
				cout<<0<<'\n';
				return 0;
			}
			else if(arr[i]+arr[j]>k){
				ans=min({ans,co[i],co[j]});
			}
		}
	}
	
	if(ans==(ll)1e50){
		cout<<-1<<'\n';
	}
	else cout<<ans<<'\n';

}

