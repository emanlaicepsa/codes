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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		deque<char> dq;
		dq.pb(s[0]);
		bool used[30]={0};
		used[s[0]-'a'] = 1;
		int now = 0;
		bool nn = 0;
		for(int i=1;i<s.size();i++){
			bool ok = 0;
			if(now && s[i] == dq[now-1]) now--,ok = 1;
			else if(now+1 <dq.size() && s[i] == dq[now+1]) now++,ok = 1;
			else if(!used[s[i]-'a'] && now == 0){
				dq.push_front(s[i]);
				ok = 1;
			}
			else if(!used[s[i]-'a'] && now == dq.size()-1){
				dq.pb(s[i]);
				now++;
				ok = 1;
			}
			used[s[i]-'a'] = 1;
			if(!ok){
				nn=1;
				break;
			}
			/*for(auto i:dq){
				cout<<i;
			}
			cout<<now<<" ";
			cout<<'\n';*/
		}
		if(nn){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			for(auto i:dq){
				cout<<i;
				used[i-'a'] = 1;
			}
			for(int i=0;i<26;i++){
				if(!used[i]){
					cout<<(char)(i+'a');
				}
			}
			cout<<'\n';
		}
	}
	

}

