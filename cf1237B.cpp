#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int order[100005];
int bit[100005];
int arr[100005];
int n,tem;
int query(int x){
	ll a=0;
	for(int i=x;i>0;i-=(i&-i)){
		a+=bit[i];
	}
	return a;
}

void add(int x){
	for(int i=x;i<=n;i+=(i&-i))
		bit[i]+=1;
}

int main(){
	
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tem;
		order[tem]=i;
	}
	for(int i=n;i>=1;i--){
		cin>>arr[i];
		arr[i]=order[arr[i]];
	}
	int nowmin=2147483647;
	for(int i=1;i<=n;i++){
		if(arr[i]>nowmin)ans++;
		nowmin=min(nowmin,arr[i]);
	}
	
	cout<<ans<<'\n';

}

