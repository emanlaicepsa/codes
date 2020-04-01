#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define forn for(int i=0;i<n;i++)
using namespace std;
using ll= long long;
map<int,int> itg;
int arr[100005];
int ans[100005];
int n,m;
int main(){
	int n,m;
	cin>>n>>m;
	forn{
		cin>>arr[i];
		if(itg.find(arr[i])!=itg.end())itg[arr[i]]++;
		else itg[arr[i]]=1;
	}
	ans[0]=itg.size();
	forn{
		itg[arr[i]]--;
		if(itg[arr[i]]==0)itg.erase(arr[i]);
		ans[i+1]=itg.size();
	}
	int temp;
	while(m--){
		cin>>temp;
		cout<<ans[temp-1]<<'\n';
	}
}

