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
bool need[65];
int num[65];
int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		reset(need,0);
		reset(num,0);
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<63;i++){
			if(n&(1LL<<i))need[i] = 1;
		}
		for(ll i=1,a;i<=m;i++){
			cin>>a;
			for(int i=0;i<63;i++){
				if(a&(1LL<<i))num[i] ++;
			}
		}
		bool ok = 1;
		int cnt = 0;
		for(ll i=0;i<63;i++){
			if(need[i]){
				if(num[i]){
					num[i] --;
				}
				else{
					//cout<<1<<'\n';
					bool f = 0;
					for(int j=i+1;j<63;j++){
						if(num[j]){
							//cout<<j<<'\n';
							f = 1;
							num[j] --;
							for(int k = i;k<j;k++){
								num[k] ++;
								cnt++;
							}
							break;
						}
					}
					if(!f){
						ok = 0;
						break;
					}
				}
			}
			num[i+1] += num[i]/2;
			num[i] %=2;
		}
		if(!ok){
			cout<<-1<<'\n';
		}
		else{
			cout<<cnt<<'\n';
		}
	}
	
	
	

}

