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
bool vis[2000005];
vector<pii> E[250005];
 
ll n,m,k;
int cnt = 0;
vector<int> ord;
void be(int x1,int y1,int x2,int y2){
	int a1 = x1 * m +y1, a2 = x2*m + y2;
	E[a1].pb({a2,cnt++});
	E[a2].pb({a1,cnt++}); 
}
 
void dfs(int x){
	for(auto &i:E[x]){
		if(!vis[i.se]){
			vis[i.se] = 1;
			dfs(i.fi);
		}
	}
	ord.pb(x);
}
 
int main(){
	IOS;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i){
				be(i,j,i-1,j);
			}
			if(j){
				be(i,j,i,j-1);
			}
		}
	}
	dfs(0);
	ord.pop_back();
	reverse(all(ord));
	if(ord.size() < k){
		cout<<"NO\n";
	}
	else{
		vector<char> ans;
		vector<pair<int,string>> aa;
		cout<<"YES\n";
		int now = 0;
		int cnt = 0;
		for(auto &i:ord){
			if(i==now+m){
				ans.pb('D'); 
			}
			else if(i==now-m){
				ans.pb('U'); 
			}
			else if(i==now+1){
				ans.pb('R'); 
			}
			else if(i==now-1){
				ans.pb('L'); 
			}
			//cout<<i<<'\n';
			now = i;
			cnt ++;
			if(cnt == k)break;
		}
		int idx = 0;
		while(idx < k){
			if(idx + 1 == k){
				string s = "";
				s += ans[idx];
				aa.pb({1,s});
				break;
			}
			int cnt = 0;
			string s = "";
			s += ans[idx];
			s += ans[idx + 1];
			while(idx + 1 < k && ans[idx] == s[0] && ans[idx+1] == s[1]){
				cnt ++;
				idx += 2;
			}
			aa.pb({cnt,s});
			//cout<<idx<<'\n';
		}
		cout<<aa.size()<<'\n';
		for(int i=0;i<aa.size();i++){
			cout<<aa[i].fi<<" "<<aa[i].se<<'\n';
		}
	}
	
}
