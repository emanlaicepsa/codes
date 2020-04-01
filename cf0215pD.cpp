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
int bit[200005];
int n;
void add(int x,int val){
	for(int i=x;i<=n;i+=(i&-i))bit[i]+=val;
}
int que(int x){
	int ans = 0;
	for(int i=x;i;i-=(i&-i))ans += bit[i];
	return ans;
}
int smallest(int x){
	int l = 1,r = n;
	while(l<r){
		int m = (l+r)>>1;
		int aa = que(m);
		if(aa>=x)r=m;
		else l=m+1;
	}
	return l;
}
int c0[200005];
int c1[200005];

int main(){
	IOS;
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			bit[i] = c0[i] = c1[i] = 0;
		}
		for(int i=1;i<=n;i++){
			add(i,1);
		}
		cin>>s;
		s = ")" + s;
		for(int i=1;i<s.size();i++){
			if(s[i] == '<'){
				c0[i+1] = 0;
				c1[i+1] = c1[i] + 1;
			}
			else{
				c0[i+1] = c0[i] + 1;
				c1[i+1] = 0;
			}
		}
		vector<int> a1,a2;
		for(int i=n;i>=1;i--){
			if(c0[i]){
				int x = smallest(1);
				a1.pb(x);
				add(x,-1);
			}
			else{
				int x = smallest(c1[i]+1);
				a1.pb(x);
				add(x,-1);
			}
		}
		reverse(all(a1));
		for(auto i:a1){
			cout<<i<<" ";
			add(i,1);
		}
		cout<<'\n';
		int now = n;
		for(int i=n;i>=1;i--){
			if(c1[i]){
				int x = smallest(now);
				a2.pb(x);
				add(x,-1);
			}
			else{
				int x = smallest(now-c0[i]);
				a2.pb(x);
				add(x,-1);
			}
			now--;
		}
		reverse(all(a2));
		for(auto i:a2){
			cout<<i<<" ";
			add(i,1);
		}
		cout<<'\n';
	}


}

