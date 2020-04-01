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
int nex[1005];
int pre[1005];
bool ok[1005];
int main(){
	IOS;
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		nex[i] = i+1;
		pre[i] = i-1;
	}
	for(int i=0;i<n;i++){
		cin>>t;
		t%=m;
		int idx = 0;
		vector<int> wait; 
		wait.clear();
		while(idx!=m){
			//cout<<idx<<" "<<i<<'\n';
			if(idx==t)wait.pb(idx);
			if(ok[(idx - t + m)%m])wait.pb(idx);
			
			idx = nex[idx];
		}
		for(auto i:wait){
			ok[i] = 1;
			if(i == 0){
				cout<<"YES\n";
				return 0;
			}
			nex[pre[i]] = nex[i];
			pre[nex[i]] = pre[i];
		}	
	}
	cout<<"NO\n";
	



}

