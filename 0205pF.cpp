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
struct fli{
	int t;
	int to;
	int c;
	bool operator <(const fli &b){
		return t< b.t;
	}
};
vector<fli> come;
vector<fli> go;
deque<pii> cur[100005];
ll goans;
ll comeans;
ll cmin[100005];
ll ans = 1e15;
void ins(int x,int t,int c){
	while(cur[x].size() && cur[x].back().fi > c) cur[x].pop_back();
	cur[x].pb({c,t});
}
int main(){
	IOS;
	int n,m,k;
	cin>>n>>m>>k;
	fill(cmin,cmin+n+1,1e12);
	for(int i=0,a,b,c,d;i<m;i++){
		cin>>a>>b>>c>>d;
		if(!b){
			go.pb({a,c,d});
		}
		else{
			come.pb({a,b,d});
		}
	}
	sort(all(go));
	sort(all(come));
	for(auto i:go){
		ins(i.to,i.t,i.c);
	}
	for(int i=1;i<=n;i++){
		if(cur[i].empty()){
			cout<<-1<<'\n';
			return 0;
		}
		goans += cur[i][0].fi;
		comeans += cmin[i];
	}
	int idx = 0;
	for(auto i:come){
		if(cmin[i.to] > i.c){
			comeans -= cmin[i.to] - i.c;
			cmin[i.to] = i.c;
			while(idx < go.size() && i.t + k  >= go[idx].t){
				int num = go[idx].to;
				if(cur[num][0].se == go[idx].t){
					int nn = cur[num][0].fi;
					cur[num].pop_front();
					if(cur[num].empty()){
						goans = 1e15;
					}
					else{
						goans += cur[num][0].fi - nn;
					}
				}
				idx++; 
			}
		}
		//cout<<goans<<" "<<comeans<<'\n';
		ans = min(ans,goans + comeans);
	}
	if(ans > 1e12)cout<<-1<<'\n';
	else cout<<ans<<'\n';
}

