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
int cnt[200005];
int arr[200005];
ll ans[30];
int main(){
	IOS;
	int t,n,m;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>s;
		s = " " + s;
		fill(ans,ans+30,0);
		for(int i=0;i<m;i++){
			cin>>arr[i];
			cnt[arr[i]+1] --;
		}
		
		int now = m+1;
		for(int i=1;i<=n;i++){
			now += cnt[i];
			ans[s[i]-'a']+=now;	
		}
		
		for(int i=0;i<m;i++){
			cnt[arr[i]+1]++;
		}
		
		for(int i=0;i<26;i++){
			cout<<ans[i]<<" \n"[i==25];
		}
	}


}

