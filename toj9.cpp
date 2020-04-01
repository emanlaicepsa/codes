#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int h[10005];
vector<int> con[10005];
bool vis[10005];
int dis[10005];
queue<int> q;
int main(){
	IOS
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cout<<"Case #"<<++cas<<": ";
		memset(h,0,sizeof(h));
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f3f3f,sizeof(dis));
		for(int i=0;i<10000;i++)con[i].clear();
		int n,m,s;
		int minh=0x3f3f3f3f;
		cin>>n>>m>>s;
		for(int i=0;i<n;i++){
			cin>>h[i];
			minh=min(minh,h[i]);
		}
		int t1,t2;
		for(int i=0;i<m;i++){
			cin>>t1>>t2;
			con[t1].emplace_back(t2);
			con[t2].emplace_back(t1);
		}
		int ans1=0x3f3f3f3f,ans2=0x3f3f3f3f;
		
		while(!q.empty())q.pop();
		q.push(s);
		dis[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int nd=q.front();
			q.pop();
			if(h[nd]==minh){
				ans1=dis[nd];
				break;
			}
			for(int i:con[nd]){
				if(vis[i])continue;
				vis[i]=1;
				dis[i]=dis[nd]+1;
				q.push(i);
			}
		}
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f3f3f,sizeof(dis));
		while(!q.empty())q.pop();
		
		q.push(s);
		dis[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int nd=q.front();
			q.pop();
			if(h[nd]==minh){
				ans2=dis[nd];
				break;
			}
			int nminh=2147483647;
			for(int i:con[nd]){
				if(vis[i])continue;
				nminh=min(nminh,h[i]);
			}
			if(nminh>=h[nd])break;
			for(int i:con[nd]){
				if(vis[i])continue;
				if(h[i]==nminh){
					vis[i]=1;
					dis[i]=dis[nd]+1;
					q.push(i);
				}
			}
		}
		
		
		if(ans1==0x3f3f3f3f&&ans2==0x3f3f3f3f){
			cout<<"Call 119!\n";
		}
		else{
			//cout<<ans1<<" "<<ans2<<'\n';
			ll ans;
			if(ans1!=0x3f3f3f3f&&ans2!=0x3f3f3f3f){
				ans=ans1*6-ans2;
			}
			else ans=ans1*6;
			cout<<ans<<'\n';
		}
		
		
		
	}



}

