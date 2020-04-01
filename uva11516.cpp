#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
int n,m;
bool ok(int x){
	//cout<<x<<'\n';
	int idx=0;
	int now=-1;
	int cnt=0;
	while(idx<m){
		while(arr[idx]<=now&&idx<m)idx++;
		//cout<<idx<<'\n';
		if(idx<m){
			now=arr[idx]+x;
			idx++;
			cnt++;
			if(cnt>n)return false;
		}
	}
	return true;
}



int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		memset(arr,0,sizeof(arr));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>arr[i];
		}
		sort(arr,arr+m);
		int l=0,r=arr[m-1];
		while(l<r){
			int mid=(l+r)/2;
			if(ok(mid))r=mid;
			else l=mid+1;
		}
		double ans=l*1.0/2;
		cout<<fixed<<setprecision(1)<<ans<<'\n';
	} 
}

