#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
string s;
vector<int> a;
vector<int> b;
 
 
int main(){
	ll n;
	cin>>n;
	if(n==1){
		cout<<'0'<<'\n';
		return 0;
	}
	cin>>s;
	ll cnt=0,ans=n*(n-1)/2;
	a.push_back(-1);
	b.push_back(-1);
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='A')a.push_back(i);
		else b.push_back(i);
		if(i&&s[i]!=s[i-1])cnt--;
	}
	
	a.push_back(n);
	b.push_back(n);
	//for(auto i:a)cout<<i<<" ";cout<<'\n';
	//for(auto i:b)cout<<i<<" ";cout<<'\n';
	for(int i=1;i<a.size()-1;i++){
		cnt+=a[i]-a[i-1]-1;
		cnt+=a[i+1]-a[i]-1;
	}
	for(int i=1;i<b.size()-1;i++){
		cnt+=b[i]-b[i-1]-1;
		cnt+=b[i+1]-b[i]-1;
	}
	ans-=cnt;
	
	cout<<ans<<'\n';
 
 
 
}

