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
vector<pii> v;
bool cmp(pii a,pii b){
	if(a.fi<b.fi)return a.fi<b.fi;
	return a.se<b.se;
}

ll val[100005];
bool used[100005];

int main(){
	IOS;
	
	vector<char> ans;
	stack<pair<char,int>> stk;
	
	string s;
	cin>>s;
	int siz = s.size();
	for(int i=0;i<siz;i++){
		v.pb({s[i]-'a',i});
	}
	sort(all(v));
	for(int i=0;i<siz;i++){
		val[v[i].se] = i;
	}
	int nfind = 0,nidx = 0;
	while(nidx<siz){
		while(nidx<siz && val[nidx] > nfind) {	
			used[val[nidx]]=1;
			stk.push({s[nidx],val[nidx]});
			nidx++;
		}
		if(nidx>=siz)break;
		used[val[nidx]] = 1;
		ans.pb(s[nidx]);
		nfind++;
		nidx++;
		while(nfind<siz&&used[nfind])nfind++;
		if(nfind>=siz)break;
		while(!stk.empty() && stk.top().se < nfind){
			ans.pb(stk.top().fi);
			stk.pop();
		}
	}
	while(!stk.empty()){
		ans.pb(stk.top().fi);
		stk.pop();
	}
	for(auto i:ans)cout<<i;
	cout<<'\n';
}

