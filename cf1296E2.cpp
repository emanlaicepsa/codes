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
int nowm[30];
int ans[200005];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		int nmax = 0;
		for(int j=s[i]+1-'a';j<26;j++){
			nmax = max(nmax,nowm[j]);
		}
		nowm[s[i]-'a'] = max(nowm[s[i]-'a'],nmax + 1); 
		ans[i] = nmax + 1;
	}
	int amax = 0;
	for(int i=0;i<n;i++)amax = max(amax,ans[i]);
	cout<<amax<<'\n';
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" \n"[i==n-1];
	}



}

