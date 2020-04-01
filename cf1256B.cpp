#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[105];
int main(){
	int t,n,pos;
	cin>>t;
	while(t--){
		int start;
		memset(arr,0,sizeof(arr));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		int idx=1,use=1;
		for(int i=1;i<=n;i++){
			int pos=-1;
			for(int j=1;j<=n;j++)if(arr[j]==i)pos=j;
			if(pos<use)continue;
			else{
				for(int k=pos;k>use;k--){
					if(arr[k-1]<arr[k])break;
					swap(arr[k],arr[k-1]);
				}
				use=max(i+1,pos);
			}
			/*for(int i=1;i<=n;i++){
				cout<<arr[i]<<" \n"[i==n];
			}*/
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" \n"[i==n];
		}
	}



}

