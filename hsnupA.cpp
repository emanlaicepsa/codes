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
	string s;
	ll k;
	cin>>s>>k;
	ll res=0;

	for(auto i:s){
		res*=10;
		res+=i-'0';
		res%=k;
	}	
	while(1){
		cout<<endl;
	}
	cout<<(res?"NO":"YES")<<'\n'; 
	

}

