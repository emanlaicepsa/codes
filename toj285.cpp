#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[205][205];
pii s[30];
bool vis[30][205][205];
ll dis[30][205][205];
int n,m;
struct D{
	int dx;
	int dy;	
}dir[4]={{0,1},{1,0},{-1,0},{0,-1}};
void bfs(int u,int x,int y){
	queue<pii> q;
	while(!q.empty())q.pop();
	vis[u][x][y]=1;
	dis[u][x][y]=0;
	q.push({x,y});
	
	while(!q.empty()){
		int tx=q.front().first;
		int ty=q.front().second;
		//cout<<tx<<" "<<ty<<'\n';
		q.pop();
		for(int i=0;i<4;i++){
			if(tx+dir[i].dx>0&&tx+dir[i].dx<=n&&ty+dir[i].dy>0&&ty+dir[i].dy<=m){
				if(!vis[u][tx+dir[i].dx][ty+dir[i].dy]&&arr[tx+dir[i].dx][ty+dir[i].dy]){
					vis[u][tx+dir[i].dx][ty+dir[i].dy]=1;
					dis[u][tx+dir[i].dx][ty+dir[i].dy]=dis[u][tx][ty]+1;
					q.push({tx+dir[i].dx,ty+dir[i].dy});
				}
			}
		}
	}
}



int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		memset(arr,0,sizeof(arr));
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<30;i++){
			for(int j=1;j<=200;j++){
				for(int k=1;k<=200;k++){
					dis[i][j][k]=0x3f3f3f;
				}
			}
		}
		int idx=0;
		cin>>n>>m;
		string t1;
		for(int i=1;i<=n;i++){
			cin>>t1; 
			for(int j=1;j<=m;j++){
				if(t1[j-1]=='.')arr[i][j]=1;
				else if(t1[j-1]=='#')arr[i][j]=0;
				else{
					arr[i][j]=1;
					s[idx++]={i,j};
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<arr[i][j]<<' '; 
			}
			cout<<'\n';
		}*/
		//cout<<idx<<'\n';
		for(int i=0;i<idx;i++){
			bfs(i,s[i].first,s[i].second);
			/*for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					cout<<dis[i][j][k]<<'\t';
				}
				cout<<'\n';
			}
			cout<<'\n';*/ 
		}
		ll ans=0x3f3f3f3f;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				bool ok=1;
				ll temp=0;
				for(int k=0;k<idx;k++){
					if(dis[k][i][j]==0x3f3f3f){
						ok=0;
						break;
					}
					temp+=dis[k][i][j];
				}
				if(ok)ans=min(ans,temp);
			}
		}
		if(ans!=0x3f3f3f3f)cout<<ans<<'\n';
		else cout<<-1<<'\n';
	}



}

