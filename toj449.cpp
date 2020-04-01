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
bool ok;
char arr[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int step;
int n,m,sx,sy;
bool vis[105][105][18];

bool cango(int x,int y,int key){
	if(x<=0 || x>n)return 0;
	if(y<=0 || y>m)return 0;
	if(arr[x][y] == '#') return 0;
	if(arr[x][y] == 'R' && !(key&1)) return 0;
	if(arr[x][y] == 'G' && !(key&2)) return 0;
	if(arr[x][y] == 'B' && !(key&4)) return 0;
	if(arr[x][y] == 'Y' && !(key&8)) return 0;
	return 1;
}

void iddfs(int x,int y,int key,int st){
	if(st>step)return;
	if(ok)return;
	if(arr[x][y] == 'X'){
		ok = 1;
		return;
	}
	if(vis[x][y][key]) return;
	if(arr[x][y] == 'r')key |= 1;
	if(arr[x][y] == 'g')key |= 2;
	if(arr[x][y] == 'b')key |= 4;
	if(arr[x][y] == 'y')key |= 8;
	vis[x][y][key] = 1;
	for(int i=0;i<4;i++){
		int nx = x+dx[i],ny = y+dy[i];
		if(cango(nx,ny,key)){
			iddfs(nx,ny,key,st+1);
		}
	}
	vis[x][y][key] = 0;
} 

int main(){
	IOS;
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			if(arr[i][j] == '*'){
				sx = i;
				sy = j;
			}
		}
	}
	
	int l = 1,r = 1000;
	while(l<r){
		ok = 0;
		step = (l+r)>>1;
		iddfs(sx,sy,0,0);
		if(ok){
			r=step;
		}
		else{
			l=step+1;
		}
	}
	
	ok = 0;
	step = l;
	iddfs(sx,sy,0,0);
	if(ok){
		cout<<"Escape possible in "<<l<<" steps.\n";
		return 0;
	}
	else{
		cout<<"The poor student is trapped!\n";
	}
	
	
}

