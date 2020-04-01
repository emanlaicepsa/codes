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
struct edge{
	int c;
	bool cho;
	int num;
	bool operator<(const edge& a){
		if(c!=a.c)return c<a.c;
		return cho>a.cho;
	}
};
vector<edge> v;
deque<pii> can;
pii ans[100005];

int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	v.resize(m);
	for(int i=0;i<m;i++){
		cin>>v[i].c>>v[i].cho;
		v[i].num = i;
	}
	sort(all(v));
	ll now = 1;
	for(auto x:v){
		if(x.cho){
			for(int i=now-1;i>0;i--){
				can.pb({i,now+1});
				if(can.size()>100005)break;
			}
			ans[x.num] = {now,now+1};
			now++; 
		}
		else{
			if(can.empty()){
				cout<<-1<<'\n';
				return 0;
			}
			ans[x.num] = can.front();can.pop_front();
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[i].fi<<" "<<ans[i].se<<'\n';
	}


}

