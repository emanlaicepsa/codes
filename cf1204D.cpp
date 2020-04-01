#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll ans[2005][2005];
ll arr[2005];
int ze[2005];
int on[2005];
int pos[2005];
int maxd[2005];
int main(){
	string s;
	cin>>s;
	int n=s.length();
	
	for(int i=1;i<=n;i++){
		arr[i]=s[i-1]-'0';
	}
	int cnt=0;
	int cnt1=0;
	ll p=-1;
	ll maxdif=0;
	pos[n+1]=n+1;
	for(int i=n;i>=1;i--){
		if(arr[1]==0)cnt++;
		else cnt1++;
		ze[i]=cnt;
		on[i]=cnt1;
		pos[i]=pos[i+1];
		if(on[i+1]-ze[i+1]>on[pos[i+1]]-ze[pos[i+1]]){
			pos[i]=i+1;
			maxdif=cnt1-cnt;
		}
		
	}
	
	for(int i=1;i<=n;i++){
		if(arr[i]==0){
			continue;
		}
		if(on[i+1]==ze[i+1]-ze[pos[i]]+on[pos[i]]){
			arr[i]=0;
			continue;
		}
	}
	
	
	
	for(int i=1;i<=n;i++){
		cout<<arr[i];
	}
	cout<<'\n';
	
	
	

}

