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
int go(string s){
	int cur = 0;
	int mn = 0;
	int num = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '(')cur++;
		else{
			cur--;
			if(cur<mn){
				mn = cur;
				num = 1;
			}
			else if(cur == mn){
				num++;
			}
		}
	}
	//cout<<s<<" "<<num<<'\n';
	return num;
}
int main(){
	IOS;
	int al,ar,ans=-1;
	int n; string s;
	cin>>n;
	cin>>s;
	int cnt = 0;
	for(auto i:s)cnt+=(i=='(');
	if( (n&1) || cnt!=n/2){
		cout<<0<<'\n'<<1<<" "<<1<<'\n';
		return 0; 
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(s[i],s[j]);
			ll tmp = go(s);
			if(tmp > ans){
				al = i;
				ar = j;
				ans = tmp;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<'\n';
	cout<<al+1<<" "<<ar+1<<'\n';



}

