#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
int sum[100005];
int n,k;
bool toosmall(int x){
	//cout<<x<<endl;
	int l=0,r=0;
	int cnt=0;
	int ans=arr[0];
	while(l<n){
		while(ans<x&&r<n-1){
			r++;
			ans+=arr[r];
		}
		if(ans>=x)cnt+=n-r;
		//cout<<l<<" "<<r<<endl;
		ans-=arr[l];
		l++;
	}
	//cout<<x<<" "<<cnt<<endl;
	//cout<<cnt<<endl;
	if(cnt>=k)return 1;
	else return 0;
}




int main(){
	IOS
	cin>>n>>k;
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i)sum[i]=sum[i-1];
		sum[i]+=arr[i];
		maxn=max(maxn,arr[i]);
	}
	int l=0,r=sum[n-1]+5;
	while(l<r){
		int m=(l+r)/2;
		if(toosmall(m)){
			l=m+1;
		}
		else r=m;
	}
	cout<<l-1<<'\n';

}

