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
int arr[200005];
bool good[200005];
int pos[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		reset(arr,0);
		reset(good,0);
		reset(pos,0);
		rep1(i,n)cin>>arr[i],pos[arr[i]]=i;
		int cr=pos[1],cl=pos[1];
		cout<<1;
		for(int i=2;i<=n;i++){
			cr=max(cr,pos[i]);
			cl=min(cl,pos[i]);
			if(cr-cl+1==i)cout<<1;
			else cout<<0;
		}
		cout<<'\n';
	}



}

