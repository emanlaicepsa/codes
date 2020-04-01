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
bool isvowel(char c){
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')return 1;
	return 0;
}
int main(){
	string s;
	cin>>s;
	int siz = s.size();
	long double cur = siz;
	long double ans = 0;
	long double mi = 0;
	for(auto i:s)if(isvowel(i))ans += siz;
	for(int i=1;i<=siz;i++){
		mi += 1.0/i;
	}
	long double tmp = mi; 
	for(int i=0;i<siz;i++){
		cur -= mi;
		mi -= 1.0 / (i+1);
		if(isvowel(s[i])){
			ans -= cur;
		}	
	}
	cur = siz;
	mi = tmp;
	reverse(all(s));
	for(int i=0;i<siz;i++){
		cur -= mi;
		mi -= 1.0 / (i+1);
		if(isvowel(s[i])){
			ans -= cur;
		}	
	}
	cout<<fixed<<setprecision(7)<<ans<<'\n';


}

