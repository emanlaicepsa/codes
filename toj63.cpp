#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
int dis[105][105]; 
int main(){
	int t;
	cin>>t;
	while(t--){
	memset(dis,0x3f3f3f,sizeof(dis));
	int n,m;
	cin>>n>>m;
	int s,e,v;
	for(int i=0;i<m;i++){
		cin>>s>>e>>v;
		dis[s][e]=min(dis[s][e],v);
		dis[e][s]=min(dis[e][s],v);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
			if(i!=j)ans=max(ans,dis[i][j]);
		}
	}
		cout<<ans<<'\n';
	}
}

