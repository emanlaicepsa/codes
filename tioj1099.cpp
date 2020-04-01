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

int t;
int n,a,b,c,ax,ay,az;
int vis[3005][3005];

queue<pii> q;

int main(){
	IOS;
	while(cin>>n>>a>>b>>c>>ax>>ay>>az){
		if(n==0)break;	
		int tot = a+b+c;
		if(a+b+c!=ax+ay+az){
			cout<<"No\n";
			continue;
		}
		t++;
		if(a>n || b>n || c>n){
			cout<<"No\n";
			continue;
		}
		q.push({a,b});
		vis[a][b] = t;
		bool ok = 0;
		
		while(!q.empty()){
			pii tmp = q.front() ; q.pop();
			int tx = tmp.fi ,ty = tmp.se ,tz = tot - tx - ty;
			if(tz<0)continue;
			//cout<<tx<<" "<<ty<<" "<<tz<<'\n';
			if(tx == ax && ty == ay){
				ok = 1;
				break;
			}
			if(vis[ty][tx] < t){
				vis[ty][tx] = t;
				q.push({ty,tx});
			}
			if(vis[tx][tz] < t){
				vis[tx][tz] = t;
				q.push({tx,tz});
			}
			if(vis[tz][ty] < t){
				vis[tz][ty] = t;
				q.push({tz,ty});
			}
			int nx = 2*ty-tx+1, ny = 2*tx-ty-1, nz = tot - nx - ny;
			
			if(nz>=0 && nz<= n && nx>=0 && nx<=n && ny>=0 && ny<=n && vis[nx][ny] < t){
				vis[nx][ny] = t;
				q.push({nx,ny});
			}
		}
		if(ok)cout<<"Yes\n";
		else cout<<"No\n";
		while(!q.empty()) q.pop();
	}


}

