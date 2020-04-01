#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int t;
	cin>>t;
	while(t--){
		bool ok=1;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(i&&s[i]==s[i-1]){
				cout<<-1<<'\n';
				ok=0;
				break;
			}
			if(s[i]=='?'){
				bool used[3]={0};
				if(i)used[s[i-1]-'a']=1;
				if(i<s.size()-1&&s[i+1]!='?')used[s[i+1]-'a']=1;
				
				for(int j=0;j<3;j++){
					if(!used[j]){
						s[i]='a'+j;
						break;
					}
				}
				
			}
		}
		if(ok)cout<<s<<'\n';
	}
	
	



}

