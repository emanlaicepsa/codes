#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
int n,m;
bool ok(int x){
	ll cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(upper_bound(arr,arr+n,arr[i]+x)-arr-1)-i;
		if(cnt>=m)break;
	}
	if(cnt>=m)return 1;
	else return 0;
}



int main(){
	IOS;
	cin>>n>>m;
	int minx=2000000000;
	int maxx=-1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		minx=min(minx,arr[i]);
		maxx=max(maxx,arr[i]);
	}
	sort(arr,arr+n);
	int l=0,r=maxx-minx;
	while(l<r){
		int m=l+(r-l)/2;
		if(ok(m))r=m;
		else l=m+1;
	}
	cout<<l<<'\n';
}

