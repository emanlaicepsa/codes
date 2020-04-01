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
vector<string> v1;
vector<string> v2;
string a3="";
multiset<string> ss;
bool pal(string s){
	int l = 0;
	int r = s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])return 0;
		l++;
		r--;
	}
	return 1;
}
int main(){
	IOS;
	int n,m;
	cin>>n>>m;
	string s;
	
	for(int i=0;i<n;i++){
		cin>>s;
		string tmp = s;
		reverse(all(tmp));
		if(ss.find(tmp) != ss.end()){
			v1.push_back(s);
			v2.push_back(tmp);
			ss.erase(ss.find(tmp));
		}
		else{
			ss.insert(s);
		}
	}
	
	for(auto i:ss){
		if(pal(i)){
			a3 = i;
		}
	}
	
	reverse(all(v2));
	string ans = "";
	for(auto i:v1){
		ans += i;
	}
	ans += a3;
	for(auto i:v2){
		ans += i;
	}
	cout<<ans.size()<<'\n';
	cout<<ans<<'\n';

}

