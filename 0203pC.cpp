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
pii arr[105];
int water[105];
int ans[105];
int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++)cin>>arr[i].fi ,arr[i].se = i;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		water[i] = (arr[i].fi + 1)/2;
		w-= water[i];
	}
	if(w<0)cout<<-1<<'\n';
	else{
		for(int i=n-1;i>=0;i--){
			if(!w)break;
			int x = min(arr[i].fi - water[i] , w);
			water[i] += x;
			w -= x; 
		}
		for(int i=0;i<n;i++){
			ans[arr[i].se] = water[i]; 
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<' ';
		}
	} 


}

