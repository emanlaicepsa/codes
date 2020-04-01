#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
bool con[105][105];
int dis[105][105];
ll arr[1000005];
bool igno[1000005]; 
int nex[1000005];
int nex2[1000005];
int main(){
	IOS
	int n;
	cin>>n;
	char temp;
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>temp;
			if(temp=='1'){
				con[i][j]=1;
				dis[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j];
		}
		cout<<endl;
	}*/
	
	int l;
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>arr[i];
		if(i<l)nex[i]=i+1;
		if(i<l-1)nex2[i]=i+2;
	}
	
	
	
	ll ans=l;
	for(int i=1;i<=l-2;){
		while(dis[arr[i]][arr[nex2[i]]]==dis[arr[i]][arr[nex[i]]]+dis[arr[nex[i]]][arr[nex2[i]]]){
			ans--;
			igno[nex[i]]=1;
			nex[i]++;
			nex2[i]++; 
		}
		i=nex[i];
	}
	cout<<ans<<'\n';
	for(int i=1;i<=l;i++){
		if(igno[i])continue;
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	
}

