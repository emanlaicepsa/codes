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
	ll nowl = 0 ,nowr = 1e9;
	int n;
	cin>>n;
	cout<<nowl<<" "<<0<<endl;
	n--;
	n--;
	string s;
	cin>>s;
	if(n==-1){
		cout<<10<<" "<<0<<" "<<10<<" "<<1<<endl;
		return 0;
	}
	string ans = s;
	while(n--){
		ll m = (nowl+nowr)/2;
		cout<<m<<" "<<0<<endl;
		cin>>s;
		if(s == ans){
			nowl = m+1;
		}
		else nowr = m;
	}
	ll m = (nowl+nowr)/2;
	cout<<m<<" "<<1<<endl;
	cin>>s;
	if(s==ans){
		cout<<m<<" "<<0<<" "<<m+1<<" "<<1<<endl;
	}
	else{
		cout<<m<<" "<<0<<" "<<m-1<<" "<<1<<endl;
	}
	//white

}

