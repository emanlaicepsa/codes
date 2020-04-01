#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[200005];
int main(){
	IOS;
	int t,h,n;
	cin>>t;
	while(t--){
		cin>>h>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		} 
		arr[n]=0;
		int i=0;
		int ans=0;
		while(i<n){
			arr[i]=arr[i+1]+1;
			if(arr[i+1]==0||arr[i+1]==arr[i+2]+1){
				i+=2;
				continue;
			}
			else{
				ans++;
				arr[i+1]--;
				i++;
			}
		}
		cout<<ans<<'\n';
	}



}

