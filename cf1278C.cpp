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
int arr[100005];
int arr2[100005];
int a[400005];
int main(){
	IOS
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		reset(arr,0);
		reset(arr2,0);
		reset(a,0x3f);
		int ca=0,cb=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]==1)ca++;
			else cb++;
		}
		int mb=0;
		a[200000]=0;
		for(int i=0;i<n;i++){
			cin>>arr2[i];
			if(arr2[i]==1)ca++,mb++;
			else cb++,mb--;
			a[mb+200000]=min(a[mb+200000],i+1); 
		}
		int dif=ca-cb;
		//cout<<dif<<'\n';
		int mr=0,ans=1e9;
		ans=min(ans,a[dif+200000]);
		for(int i=n-1;i>=0;i--){
			if(arr[i]==2)mr++;
			else mr--;
			ans=min(ans,n-i+a[mr+dif+200000]);
		}
		cout<<ans<<'\n';
	}



}

