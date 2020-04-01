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
map<pii,int> m; 
int main(){
	int t;
	cin>>t;
	while(t--){
		m.clear();
		int x = 0,y = 0;
		int n;
		int l, r=100000000;
		char c;
		cin>>n;
		m[{0,0}] =1;
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='U')y++;
			if(c=='D')y--;
			if(c=='L')x--;
			if(c=='R')x++;
			if(m[{x,y}]){
				if(i-m[{x,y}] < r-l){
					l = m[{x,y}];
					r = i;
				}	
			} 
			m[{x,y}] = i+1;
		}
		if(r>10000000)cout<<-1<<'\n';
		else cout<<l<<" "<<r<<'\n';
	}



}

