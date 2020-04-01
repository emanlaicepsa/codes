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
int cnt01;
int cnt10;
set<string> all;
vector<pair<string,int>> v;
vector<int> ans;
string rev(string s){
	reverse(all(s));
	return s;
}
inline bool is10(string &s){
	return s[0]=='1'&&s[s.size()-1]=='0';
}
inline bool is01(string &s){
	return s[0]=='0'&&s[s.size()-1]=='1';
}
int main(){
	IOS;
	string s;
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cin>>s;
			cout<<0<<'\n'<<'\n';
			continue;
		} 
		cnt01 = cnt10 = 0;
		all.clear();
		v.clear();
		ans.clear();
		for(int i=1;i<=n;i++){
			cin>>s;
			if(is10(s))cnt10++;
			if(is01(s))cnt01++;
			v.pb({s,i});
		}
		bool ok = 1;
		int re = 0;
		if(!cnt10&&!cnt01){
			int cnt1 =0,cnt0 = 0;
			for(auto i:v){
				if(i.fi[0]=='1')cnt1++;	
				else cnt0++;
			}
			if(cnt1&&cnt0){
				ok=0;
			}
			if(ok)cout<<0<<'\n'<<'\n';
			else cout<<-1<<'\n';
			continue;
		}
		else{
			for(int i=0;i<n;i++){
				all.insert(v[i].fi);
			}
			int nd;
			if(cnt01>cnt10){
				nd = (cnt01 - cnt10)/2;
				for(auto i:v){
					if(!nd)break;
					if(is01(i.fi) && all.find(rev(i.fi)) == all.end()){
						ans.pb(i.se);
						re++;
						nd--;
					}
				}
			}
			else{
				nd = (cnt10 - cnt01)/2;
				for(auto i:v){
					if(!nd)break;
					if(is10(i.fi) && all.find(rev(i.fi)) == all.end()){
						ans.pb(i.se);
						re++;
						nd--;
					}
				}
			}
			cout<<re<<'\n';
			for(auto i:ans)cout<<i<<" ";
			cout<<'\n';
		}
			
	}



}

