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
int arr1[105];
int arr2[105];
int main(){
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		for(int i=0;i<a;i++)cin>>arr1[i];
		for(int i=0;i<b;i++)cin>>arr2[i];
		sort(arr1,arr1+a);
		sort(arr2,arr2+b);
		if(arr1[a-1]>arr2[b-1])cout<<"YES\n";
		else cout<<"NO\n";
	}



}

