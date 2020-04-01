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
ll n,m;
inline int toid(int x,int y){
	return x*m+y+1;
}
int pa[1000005];
int siz[1000005];
char arr[1005][1005];
ll ans[1005][1005];
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

int fp(int x){
	if(pa[x] == x)return x;
	return pa[x] = fp(pa[x]);	
}

void merge(int x,int y){
	//cout<<x<<" "<<y<<'\n';
	x = fp(x) ,y = fp(y);
	if(x==y)return;
	if(siz[x] < siz[y])swap(x,y);
	pa[y] = x;
	siz[x] += siz[y];
	//cout<<x<<" "<<y<<" "<<siz[x]<<'\n';	
}

int main(){
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		pa[i] = i;
		siz[i] = 1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j] == '.'){
				if(i&&arr[i-1][j] == '.'){
					merge(toid(i,j),toid(i-1,j));
				}
				if(j&&arr[i][j-1] == '.'){
					merge(toid(i,j),toid(i,j-1));
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == '*'){
				set<int> used;
				ans[i][j] = 1;
				for(int k=0;k<4;k++){
					ll tx = i+dx[k],ty = j+dy[k];
					//cout<<tx<<" "<<ty<<'\n';
					if(tx>=0&&tx<n&&ty>=0&&ty<m && arr[tx][ty] == '.'){
						ll x = fp(toid(tx,ty));
						//cout<<tx<<" "<<ty<<" "<<x<<'\n';
						if(used.find(x) == used.end()){
							used.insert(x);
							ans[i][j] += siz[x];
						}
					}
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i][j]){
				cout<<ans[i][j]%10;
			}
			else{
				cout<<".";
			}
		}
		cout<<'\n';
	}
	
}

