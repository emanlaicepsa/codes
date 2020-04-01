#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[1005][1005];
ll ans[1005][1005];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+arr[i][j];
		}
	}
	int q,x1,x2,y1,y2;
	cin>>q;
	while(q--){
		cin>>y1>>x1>>y2>>x2;
		ll a=ans[x2][y2]-ans[x1-1][y2]-ans[x2][y1-1]+ans[x1-1][y1-1];
		cout<<a<<'\n';
	}



}

