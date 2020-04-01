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
string s;
int num;
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>num;
		cin>>s;
		string ans = "";
		int cnt = 0;
		for(int i=0;i<s.size();i++){
			ans += s[i];
			if((s[i]-'0')&1) cnt++;
			if(cnt==2)break;
		}
		if(cnt==2)cout<<ans<<'\n';
		else cout<<-1<<'\n';
	}



}

