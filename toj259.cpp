#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int lis1[10005];
int lis2[10005];
int tarr[10005];
int arr[10005];
int main(){
	IOS
	int n;
	while(cin>>n){
		memset(lis1,0,sizeof(lis1));
		memset(lis2,0,sizeof(lis2));
		memset(tarr,0,sizeof(tarr));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int pos=0;
		tarr[0]=arr[0];
		lis1[0]=1;
		for(int i=1;i<n;i++){
			if(arr[i]>tarr[pos]){
				tarr[++pos]=arr[i];
				lis1[i]=pos+1;
			}
			else{
				int p=upper_bound(tarr,tarr+pos+1,arr[i]-1)-tarr;
				tarr[p]=arr[i];
				lis1[i]=p+1;
			}
		}
		memset(tarr,0,sizeof(tarr));
		pos=0;
		tarr[0]=arr[n-1];
		lis2[n-1]=1;
		for(int i=n-2;i>=0;i--){
			if(arr[i]>tarr[pos]){
				tarr[++pos]=arr[i];
				lis2[i]=pos+1;
			}
			else{
				int p=upper_bound(tarr,tarr+pos+1,arr[i]-1)-tarr;
				tarr[p]=arr[i];
				lis2[i]=p+1;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,min(lis1[i],lis2[i])*2-1);
		}
		cout<<ans<<'\n';
	}



}

