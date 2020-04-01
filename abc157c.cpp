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
int arr[5];
int main(){
	IOS;
	int n,m,a,b;
	cin>>n>>m;
	memset(arr,-1,sizeof(arr));
	bool ok = 1;
	while(m--){
		cin>>a>>b;
		if(arr[a]!=-1 && arr[a]!=b){
			ok = 0;
			break;
		}
		arr[a] = b;
	}
	
	if(n>1 && arr[1] == 0){
		ok = 0;
	}
	for(int i=2;i<=n;i++){
		if(arr[i] == -1){
			arr[i] = 0;
		} 
	}
	if(arr[1] == -1){
		if(n==1) arr[1] = 0;
		else arr[1] = 1;
	}
	if(ok){
		for(int i=1;i<=n;i++){
			cout<<arr[i];
		}
		cout<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}


}

