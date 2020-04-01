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
ll arr[100005];
ll cnt[32];
int n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	IOS;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<=31;j++){
			if(arr[i]&(1<<j)) cnt[j]++;
		}
	}
	int bit = 0;
	for(int i=31;i>=0;i--){
		if(cnt[i] == 1){
			bit = i;
			break;
		}
	}
	//cout<<bit<<'\n';
	
	int idx = 0;
	for(int i=0;i<n;i++){
		if(arr[i] & (1<<bit)){
			idx = i;
			break;
		}
	}
	cout<<arr[idx];
	for(int i=0;i<n;i++){
		if(i==idx)continue;
		cout<<" "<<arr[i];
	}
	cout<<'\n';
}

