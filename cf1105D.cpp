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
int dis[10][1005][1005];
char arr[1005][1005];
int col[1005][1005];
int cnt[10];
vector<pii> s[10];
ll r[10];
queue<pii> q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m,p;
int cc;
vector<pii> tq;
bool cango(int x,int y){
	if(x<1 || x>n || y<1 || y>m)return 0;
	if(arr[x][y] != '.')return 0;
	return 1;
}
void dfs(int x,int y,int c){
	//cout<<x<<" "<<y<<" "<<c<<'\n';
	col[x][y] = c;
	cc -- ;
	for(int i=0;i<4;i++){
		int gx = x+dx[i], gy = y+dy[i];
		if(cango(gx,gy) && !col[gx][gy]){
			if(dis[c][x][y] == dis[c][gx][gy]) dfs(gx,gy,c);
			else if(dis[c][x][y] + 1 == dis[c][gx][gy]){
				tq.pb({gx,gy});
			}
		}
	}
}
int main(){
	IOS;
	cin>>n>>m>>p;
	for(int i=1;i<=p;i++){
		cin>>r[i];
	}
	cc = n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			if(arr[i][j] >= '0' && arr[i][j] <='9'){
				//cout<<i<<" "<<j<<'\n';
				s[arr[i][j] - '0'].pb({i,j});
			}
			else if(arr[i][j] == '#')cc--;
		}
	}
	
	for(int i=1;i<=p;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				dis[i][j][k] = 10000000;
			}
		}
		for(auto &x:s[i]){
			dis[i][x.fi][x.se] = 0;
			q.push(x);	
		}
		while(!q.empty()){
			int x = q.front().fi ,y = q.front().se; q.pop();
			//cout<<x<<" "<<y<<'\n';
			for(int j=0;j<4;j++){
				int gx = x + dx[j] ,gy = y+dy[j];
				//cout<<gx<<" "<<gy<<'\n';
				if(cango(gx,gy) && arr[gx][gy] == '.' && dis[i][gx][gy] >= 1000000){
					dis[i][gx][gy] = dis[i][x][y] + 1;
					q.push({gx,gy}); 
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=m;j++){
				dis[i][k][j] = (dis[i][k][j] - 1) / r[i] + 1;
				if(!dis[i][k][j]) dis[i][k][j] = 1;
				//cout<<i<<" "<<k<<" "<<j<<" "<<dis[i][k][j]<<'\n';
			}
		}
	}
	while(cc){
		bool go = 0;
		for(int i=1;i<=p;i++){
			for(auto x:s[i]){
				//cout<<x.fi<<" "<<x.se<<" "<<dis[i][x.fi][x.se]<<'\n';
				if(!col[x.fi][x.se]){
					dfs(x.fi,x.se,i);
					go = 1;
				}
			}
			swap(s[i] , tq);
			tq.clear();
		}
		if(!go)break;
	} 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j] != '#'){
				cnt[col[i][j]] ++;
			}
		}
	}
	
	for(int i=1;i<=p;i++){
		cout<<cnt[i]<<" \n"[i==p];
	}

}

