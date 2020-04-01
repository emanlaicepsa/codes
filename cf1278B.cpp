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
	IOS
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		int ans=b-a;
		if(ans==0){
			cout<<0<<'\n';
			continue;
		}
		ll res=0;
		for(int i=1;i<=1000000;i++){
			res+=i;
			if(res>=ans&&(res-ans)%2==0){
				cout<<i<<'\n';
				break;
			}
		}
	
	}



}

