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
bool tle;
int cnt;
double start;
void dfs(int x,int y,int mask){
	cnt++;
	if(tle)return;
	if(ok) return;
	if(cnt%100==0){
		if((clock() - start) / CLOCKS_PER_SEC >=0.6){
			tle = 1;
			return;
		} 
	}
	if(mask == all){
		ok = 1;
		return;
	}
	for(int i=0;i<=x;i++){
		int aa = i*y;
		if(aa>100) continue;
		for(auto j:area[aa]){
			if(!(mask&(1<<j))){
				q.pb({i,y,j});
				dfs(x-i,y,mask|(1<<j));
				if(!ok) q.pop_back();
			}
			if(ok)break;
		}
		if(ok)break;
	}
	if(ok)return;
	for(int i=0;i<=y;i++){
		int aa = x*i;
		if(aa>100)continue;
		for(auto j:area[aa]){
			if(!(mask&(1<<j))){
				q.pb({x,i,j});
				dfs(x,y-i,mask|(1<<j));
				if(!ok) q.pop_back();
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
	start = clock();
	dfs(w,h,0);
	if(!ok){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
		while(!q.empty()){
			auto x = q.front();q.pop_front();
			cout<<x.num+1<<" "<<x.x<<" "<<x.y<<'\n';
		}
	}
}
