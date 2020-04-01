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
ll n,ti,a,b,ta;
vector<pii> v;
bool ish[200005];
int main(){
	IOS
	int t;
	cin>>t;
	while(t--){
		v.clear();
		cin>>n>>ti>>a>>b;
		ll ca=0,cb=0;
		for(int i=1;i<=n;i++)cin>>ish[i];
		for(int i=1;i<=n;i++){
			cin>>ta;
			if(ish[i])v.pb({ta,1}),cb++;
			else v.pb({ta,0}),ca++;
		}
		sort(all(v));
		//for(auto i:va)cout<<i<<"\n";
	//	for(auto i:vb)cout<<i<<'\n';
		int ida=0,idb=0;
		ll ans=0;
		if(ca*a+cb*b<=ti)ans=ca+cb;
		for(auto i:v){
			ll nt=i.fi;
			nt-=ida*a+idb*b;
			if(nt>0){
				ll at=0;
				ll lea=ca-ida;
				if(lea*a<nt){
					at+=lea;
					nt-=lea*a;
					ll leb=cb-idb;
					if(leb*b<nt){
						at+=leb;
					}
					else{
						at+=(nt-1)/b;
					}
				}
				else{
					at+=(nt-1)/a;
				}
				ans=max(ans,at+ida+idb);
			}
			if(i.se==0){
				ida++;
			}
			else{
				idb++;
			}
		}
		cout<<ans<<'\n';
	}



}

