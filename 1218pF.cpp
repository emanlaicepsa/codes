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
struct poi{
	int x;
	int y;
	int num;
};
queue<poi> q;
int now[3005][3005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[3005][3005];
ll cnt[3005];
int n,m,p,ta,tb;
bool cango(int x,int y){
	if(x<1||x>n||y<1||y>m||vis[x][y])return false;
	return true;
}
int main(){
	IOS
	cin>>n>>m;
	cin>>p;
	for(int i=0;i<p;i++){
		cin>>ta>>tb;
		q.push({ta,tb,i+1});
		vis[ta][tb]=1;
		cnt[i+1]++;
	}
	while(!q.empty()){
		auto i=q.front();q.pop();
		vis[i.x][i.y]=1;
		for(int j=0;j<4;j++){
			
			int nx=i.x+dx[j];
			int ny=i.y+dy[j];
			
			if(cango(nx,ny)&&now[nx][ny]<i.num){
				now[nx][ny]=i.num;
				q.push({nx,ny,i.num});
				cnt[i.num]++;
			} 
		} 
	}
	
	for(int i=1;i<=p;i++){
		cout<<cnt[i]<<'\n';
	}

}

