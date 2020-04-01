#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll l[10005];
ll arr[10005];
ll s[10005];
ll e[10005];

int main(){
	int n,m,d;
	cin>>n>>m>>d;
	int tn=n;
	int now=0;
	for(int i=0;i<m;i++){
		cin>>l[i];
		s[i]=now+1;
		e[i]=now+l[i];
		now=now+l[i]-1;
	}
	int last=m-1;
	
	while(now+d<n+1){
		if(last<0){
			cout<<"No\n";
			return 0;
		}
		
		e[last]=n+1-d;
		s[last]=n+1-d-l[last]+1;
		n=s[last]-1;
		last--;
		if(last>0)now=e[last];
		else now=0;
	}
	if(s[0]>d){
		cout<<"No\n";
		return 0;
	}
	
	for(int i=0;i<m;i++){
		for(int j=s[i];j<=e[i];j++){
			arr[j]=i+1;
		}
	}
	
	cout<<"Yes\n";
	for(int i=1;i<=tn;i++){
		cout<<arr[i]<<" \n"[i==tn];
	}
}

