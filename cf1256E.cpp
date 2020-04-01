#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
pii arr[200005];
ll dp[200005];
int front[200005];
int rrr[200005];
bool used[200005];

ll godp(int idx){
	if(idx==-1)return 0;
	if(idx<0)return 1e12;
	if(used[idx])return dp[idx];
	dp[idx]=1e12;
	for(int i=idx-2;i>=0;i--){
		if(arr[idx].first-arr[i].first+godp(i-1)<dp[idx]){
			dp[idx]=arr[idx].first-arr[i].first+godp(i-1);
			front[idx]=i-1;
		}
		
	}
	used[idx]=1;
	return dp[idx];
}



int main(){
	dp[0]=1e12;
	dp[1]=1e12;
	used[0]=used[1]=1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second=i;
	}
	sort(arr,arr+n);
	used[2]=1;
	front[2]=-1;
	dp[2]=arr[2].first-arr[0].first;
	ll ans=godp(n-1);
	cout<<ans<<' ';
	//for(int i=0;i<n;i++)cout<<front[i]<<'\n';
	int cnt=0;
	int now=n-1;
	while(now!=-1){
		cnt++;
		for(int i=now;i>front[now];i--)rrr[arr[i].second]=cnt;
		now=front[now];
	}
	cout<<cnt<<'\n';
	for(int i=0;i<n;i++){
		cout<<rrr[i]<<" \n"[i==n-1];
	}
}

