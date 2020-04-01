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
	string a,b,ta,tb;
	cin>>a>>b;
	bool ok = 0;
	for(auto &i:a){
		if(i>'0')ok=1;
		if(ok)ta+=i;
	}
	ok = 0;
	for(auto &i:b){
		if(i>'0')ok=1;
		if(ok)tb+=i;
	}
	
	if(ta.size()<tb.size()){
		cout<<"<\n";
	}
	else if(ta.size()>tb.size()){
		cout<<">\n";
	}
	else{
		if(ta<tb){
			cout<<"<\n";
		}
		else if(ta>tb){
			cout<<">\n";
		}
		else cout<<"=\n";
	}

}

