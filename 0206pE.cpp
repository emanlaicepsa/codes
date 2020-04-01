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
vector<pair<string,int>> v;
vector<string> dep[1000005];
int i;
void dfs(int d){
	//cout<<i<<" "<<d<<'\n';
	dep[d].pb(v[i].fi);
	int t = v[i].se;
	i++;
	while(t--){
		dfs(d+1);
	}
}
int main(){
	IOS;
	string s;
	cin>>s;
	int n = s.size();
	int now = 1;
	i = 0;
	while(i<n){
		//cout<<i<<'\n';
		string tmp="";
		while(i<n && s[i]!=','){
			tmp += s[i];
			i++;
		}
		i++;
		int tt = 0;
		while(i<n && s[i]!=','){
			tt = tt*10 + s[i] - '0';
			i++;
		}
		i++;
		//cout<<tmp<<" "<<tt<<'\n';
		v.pb({tmp,tt});
	}
	i = 0;
	n = v.size();
	while(i<n){
		dfs(1);
		//cout<<"%"<<i<<'\n';
	}
	int md = 0;
	for(int i=1;i<=1000000;i++){
		if(dep[i].size())md = i;
	}
	cout<<md<<'\n';
	for(int i=1;i<=md;i++){
		for(auto j:dep[i])cout<<j<<" ";
		cout<<'\n';
	}
}

