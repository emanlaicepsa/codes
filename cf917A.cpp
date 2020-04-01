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
bool ok1[5005][5005];
bool ok2[5005][5005];
int main(){
	IOS;
	string s;
	cin>>s;
	int siz = s.size();
	s = " "+s;
	ll ans = 0;
	for(int i=1;i<=siz;i++){
		bool ok = 1;
		int cnt = 0;
		for(int j=i;j<=siz;j++){
			if(s[j] == ')')cnt--;
			else cnt++;
			if(cnt<0) ok = 0;
			ok1[i][j] = ok;
		}
	}
	for(int j=siz;j>=1;j--){
		bool ok = 1;
		int cnt = 0;
		for(int i=j;i>=1;i--){
			if(s[i]=='(')cnt--;
			else cnt++;
			if(cnt<0)ok = 0;
			ok2[i][j] = ok;
		}
	}
	for(int i=1;i<=siz;i++){
		for(int j=1;j<=siz;j++){
			if(((j-i)&1)&&ok1[i][j]&&ok2[i][j])ans++;
		}
	}
	cout<<ans<<'\n';

}

