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
multiset<ll> s;
deque<ll> pri;
vector<int> ta;
bool np[2765000];
ll md[2765000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	IOS;
	
	for(ll i=2;i<=2760000;i++){
		if(!np[i]) pri.pb(i);
		for(auto j:pri){
			if(i*j > 2760000)break;
			np[i*j] = 1;
			md[i*j] = j;
			if(i%j==0)break;
		}
	}
	pri.push_front(0);
	ll n;
	cin>>n;
	deque<int> ans;
	for(int i=1,a;i<=2*n;i++){
		cin>>a;
		if(np[a])ans.pb(a);
		s.insert(a);
	}
	
	sort(all(ans),cmp);
	
	while(!ans.empty()){
		int x = ans[0]; ans.pop_front();
		if(s.find(x) != s.end()){
		 	ta.pb(x);
			s.erase(s.find(x));
			s.erase(s.find(x/md[x]));	
		}
	}
	
	
	while(!s.empty()){
		int x = *s.begin();
		ta.pb(x);
		s.erase(s.find(x));
		s.erase(s.find(pri[x]));
	}
	
	for(auto &i:ta){
		cout<<i<<" ";
	}
	
	cout<<'\n';
}

