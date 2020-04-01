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
int t,n;
string s1,s2;
int cnt[26];
int tcnt[26];
int main(){
	cin>>t;
	while(t--){
		reset(cnt,0);
		cin>>s1>>s2;
		if(s1.size()>s2.size())cout<<"NO\n";
		else{
			
			for(auto i:s1){
				cnt[i-'a']++;
			}
			bool ok=0;
			for(int i=0;i<=s2.size()-s1.size();i++){
				reset(tcnt,0);
				for(int j=i;j<i+s1.size();j++){
					tcnt[s2[j]-'a']++;
				}
				bool flag=1;
				for(int i=0;i<26;i++){
					if(cnt[i]!=tcnt[i])flag=0;
				}
				if(flag){
					ok=1;
					break;
				}
			}
			if(ok)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}



}

