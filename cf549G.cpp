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
ll ans[200005];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i] += i;
	}
	int mi = 0;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		ans[i] = arr[i] - mi;
		if(i && ans[i] < ans[i-1]){
			cout<<":(\n";
			return 0;
		}
		mi++;
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
	}

}

