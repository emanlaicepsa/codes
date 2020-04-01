#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
bool cmp (int a,int b){
	return a>b;
}
int ans[100005];
int idx=0;
int t,n;
ll tmp;
unordered_map<int,int> used;
void dfs(int id,int now){
	//cout<<id<<'\n';
	if(id>=n||now>t)return;
	if(now==t){
		tmp=0;
		for(int i=0;i<idx;i++){
			tmp*=37;
			tmp+=ans[i];
			tmp%=1000000007;
		}
		if(!used[tmp]){
			for(int i=0;i<idx;i++)cout<<ans[i]<<",\n"[i==idx-1];
			used[tmp]=1;
		}
		return;
	}
	for(int i=id+1;i<n;i++){
		ans[idx++]=arr[i];
		dfs(i,now+arr[i]);
		idx--;
	}
}

int main(){
	
	cin>>t>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	
	for(int i=0;i<n;i++){
		ans[idx++]=arr[i];
		dfs(i,arr[i]);
		idx--;
	}
}

