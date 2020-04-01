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
map<string,set<string>> m;
map<string,vector<string>> v;
bool cmp(string x,string y){
	return x.size() < y.size();
}
int main(){
	IOS;
	int n;
	string name;
	string ans;
	int num;
	cin>>n;
	while(n--){
		cin>>name>>num;
		while(num--){
			cin>>ans;
			v[name].pb(ans);
		}
	}
	for(auto &i:v){
		sort(all(v[i.fi]),cmp);
		//cout<<i.fi<<'\n';
		for(string s: v[i.fi]){
			string t = s;
			while(t.size()){
				if(m[i.fi].find(t) != m[i.fi].end()){
					m[i.fi].erase(t);
				}
				t.erase(t.begin());
			}
			m[i.fi].insert(s);
		}
	}
	cout<<m.size()<<'\n';
	for(auto i:m){
		cout<<i.fi;
		cout<<" "<<m[i.fi].size();
		for(auto j:m[i.fi]){
			cout<<" "<<j;
		}
		cout<<'\n';
	}

}

