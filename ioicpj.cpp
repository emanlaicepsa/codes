#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
bool ok = 0;
int want[20];
struct ans{
	int x;
	int y;
	int num;
}; 
ll all;
deque<ans> q;
ll n,w,h,t;
vector<int> area[105];

void dfs(int x,int y,int mask){
	if(ok) return;
	if(mask == all){
		ok = 1;
		return;
	}
	for(int i=0;i<=x;i++){
		int aa = i*y;
		if(aa>100) continue;
		for(auto j:area[aa]){
			if(!(mask&(1<<j))){
				dfs(x-i,y,mask|(1<<j));
				if(ok){
					q.pb({i,y,j});
					break;
				}
			}
		}
		if(ok)break;
	}
	if(ok)return;
	for(int i=0;i<=y;i++){
		int aa = x*i;
		if(aa>100)continue;
		for(auto j:area[aa]){
			if(!(mask&(1<<j))){
				dfs(x,y-i,mask|(1<<j));
				if(ok) q.pb({x,i,j});
			}
			if(ok)break;
		}
		if(ok)break;
	}
}
int main(){
	
	cin>>n>>w>>h;
	for(int i=0;i<n;i++){
		cin>>t;
		area[t].pb(i);
	}
	all = (1<<n) - 1;
	dfs(w,h,0);
	if(!ok){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
		while(!q.empty()){
			auto x = q.back();q.pop_back();
			cout<<x.num+1<<" "<<x.x<<" "<<x.y<<'\n';
		}
	}
}
