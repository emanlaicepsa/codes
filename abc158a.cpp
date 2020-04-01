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
	string s;
	cin>>s;
	bool h1 = 0, h2 = 0;
	for(auto i:s){
		if(i=='A')h1 = 1;
		else h2 = 1;
	}
	cout<<((h1&&h2)?"Yes\n":"No\n");


}

