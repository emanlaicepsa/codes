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
string s[500005];

int main(){
	IOS;
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=n-1;i>=1;i--){
		if(s[i] > s[i+1]){
			for(int j=0;j<s[i+1].size();j++){
				if(s[i][j] > s[i+1][j]){
					while(s[i].size() > j)s[i].pop_back();
					break;
				}
			}
		} 
		if(s[i] > s[i+1]){
			while(s[i].size() > s[i+1].size()) s[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]<<"\n";
	}


}

