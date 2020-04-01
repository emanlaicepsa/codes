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
int arr[300005];
bool lok[300005];
bool rok[300005];
int main(){
	IOS; 
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>arr[i];
		for(int i=1;i<=n;i++)lok[i] = rok[i] = 0;
		bool ok = 0;
		lok[1] = rok[n] = 1;
		for(int i=2;i<=n;i++){
			if(lok[i-1] && min(arr[i-1],arr[i]-1) >= i-2) lok[i] = 1;
		}
		for(int i=n-1;i>=1;i--){
			if(rok[i+1] && min(arr[i+1] , arr[i]-1) >= n-i-1) rok[i] = 1;
		}
		for(int i=1;i<=n;i++){
			if(lok[i] && rok[i]) ok = 1;
		}
		if(ok)cout<<"Yes\n";
		else cout<<"No\n";
	}



}

