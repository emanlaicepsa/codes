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
int cnt[100005];
int arr[100005];
int cnt2[100005];
int main(){
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[arr[i]]>=2){
			cout<<0<<'\n';
			return 0;
		}
	}
	int ans = 3;
	for(int i=1;i<=n;i++){
		if(arr[i] == (arr[i]&x))continue;
		arr[i] &= x;
		cnt2[arr[i]]++;
		//cout<<i<<" "<<arr[i]<<'\n'; 
		if(cnt[arr[i]]){
			ans = min(ans,1);
			//cout<<1<<'\n';
			//return 0;
		}
		if(cnt2[arr[i]]==2){
			ans = min(ans,2);
			//cout<<2<<'\n';
			//return 0;
		}
	}
	if(ans==3)cout<<-1<<'\n';
	else cout<<ans<<'\n';

}

