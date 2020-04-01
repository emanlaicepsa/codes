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
vector<int> cant;
int arr[105];
bool no[1000005];
vector<int> ans;
int main(){
	int n;
	int t;
	cin>>t;
	while(t--){
		ans.clear();
		cant.clear();
		memset(no,0,sizeof(no));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		} 
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				cant.pb(arr[i] - arr[j]);
			}
		}
		int cnt=0,idx = 0;
		for(int i=1;i<=1000000;i++){
			if(no[i])continue;
			cnt++;
			ans.pb(i);
			for(auto x:cant){
				if(i+x>1000000)continue;
				no[i+x] = 1; 
			}
			if(cnt==n)break;
		}
		if(cnt<n)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(auto i:ans){
				cout<<i<<" ";
			}
			cout<<'\n';
		}
			
	}
	


}

