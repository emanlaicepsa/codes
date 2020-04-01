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
	string a,b,c;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		bool yes = 1;
		for(int i=0;i<a.size();i++){
			if(!(a[i] == c[i] || b[i] == c[i])) {
				yes = 0;
				break;
			}
		}
		if(yes){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}


}

