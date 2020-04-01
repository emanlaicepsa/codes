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
int main(){
	IOS;
	int a,b;
	cin>>a>>b;
	int ans;
	for(ans=b*10;ans<b*10+10;ans++){
		if(ans * 8 / 100 == a){
			cout<<ans<<'\n';
			return 0;
		}
	}
	cout<<-1<<'\n';


}

