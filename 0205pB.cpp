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
int n;
string s;
int check(int x){
	for(int i=x;i<x*2;i++){
		if(s[i] != s[i-x])return 0;
	}
	return x;
}
int main(){
	
	cin>>n;
	
	cin>>s;
	int ans = 0;
	for(int i=1;i<=n/2;i++){
		ans = max(ans,check(i));
	}
	cout<<n-ans+(ans != 0)<<'\n';



}

