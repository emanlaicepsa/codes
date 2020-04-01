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
	string s;
	while(t--){
		cin>>s;
		int cnt = 0;
		int fi =-1, la = -1;
		for(int i=0;i<s.size();i++){
			if(s[i] == '1'){
				if(fi<0)fi=i;
				la = i;
			}
		}	
		for(int i=0;i<s.size();i++){
			if(s[i] == '0' && i > fi && i < la){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	//for(int i=0;i<n;i++) 


}

