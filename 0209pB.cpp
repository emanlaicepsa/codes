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
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<2*n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+2*n);
		cout<<arr[n] - arr[n-1]<<'\n';
	}



}

