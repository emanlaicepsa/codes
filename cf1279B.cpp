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
ll arr[100005];
int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		ll n,v,sum=0;
		cin>>n>>v;
		for(int i=1;i<=n;i++)cin>>arr[i],sum+=arr[i];
		if(sum<=v)cout<<"0\n";
		else{
			sum=0;
			ll cmax=arr[1],cid=1;
			for(int i=1;i<=n;i++){
				if(arr[i]>cmax){
					cmax=arr[i];
					cid=i;
				}
				sum+=arr[i];
				if(sum>v)break;
			}
			cout<<cid<<'\n';
		}
	}



}

