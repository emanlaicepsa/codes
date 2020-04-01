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
set<pii> s;
int cnt[400005];
int main(){
	IOS;
	int n,x,t;
	cin>>n>>x;
	for(int i=0;i<x;i++){
		s.insert({0,i});
	}
	while(n--){
		cin>>t;
		t%=x;
		s.erase(s.find({cnt[t],t}));
		cnt[t] ++;
		s.insert({cnt[t],t});
		auto ans = *s.begin();
		cout<<ans.fi*x + ans.se<<'\n';
	}
	



}

