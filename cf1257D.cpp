#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
stack<pii,vector<pii>> ts;
queue<int,list<int>> mons;
pii arr[200005];
vector<pii> heroes;
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		while(!mons.empty())mons.pop();
		memset(arr,0,sizeof(arr));
		int mn,n,te;
		cin>>mn;
		for(int i=0;i<mn;i++){
			cin>>te;
			mons.push(te);
		}
		cin>>n;
		for(int i=0;i<n;i++)cin>>arr[i].fi>>arr[i].se;
		sort(arr,arr+n);
		
		for(int i=0;i<n;i++){
			while(!ts.empty()&&arr[i].se>=ts.top().se){
				ts.pop();
			}
			if(ts.empty())ts.push(arr[i]);
			else{
				if(ts.top().fi!=arr[i].fi)ts.push(arr[i]);
			}
		}
		
		heroes.clear();
		heroes.resize(ts.size());
		for(int i=ts.size()-1;i>=0;i--)heroes[i]=ts.top(),ts.pop();
		//for(auto i:heroes) cout<<i.first<<" "<<i.second<<'\n';
		int ans=0;
		while(!mons.empty()){
			ans++;
			if(heroes[heroes.size()-1].fi<mons.front())break;
			int l=0,r=heroes.size()-1;
			while(l<r){
				int m=(l+r)>>1;
				if(heroes[m].fi>=mons.front())r=m;
				else l=m+1;
			}
			int cur=0;
			for(int i=l;i<heroes.size();i++){
				if(heroes[i].se<=cur)break;
				while(!mons.empty()&&heroes[i].fi>=mons.front()&&cur<heroes[i].se){
					//cout<<mons.front()<<'\n';
					cur++;
					mons.pop();
				}
			}
		}
		if(!mons.empty())cout<<-1<<'\n';
		else cout<<ans<<'\n';
	}
 
 
 
}
