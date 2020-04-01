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
ll a[3];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[0]+a[1]>=a[2]-1)cout<<"YES\n";
		else cout<<"NO\n";
	}



}

