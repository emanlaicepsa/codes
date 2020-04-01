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
vector<int> tr[800005];
int arr[200005];
vector<int> v;
void build(int l,int r,int idx){
	if(l==r){
		tr[idx].clear();
		tr[idx].pb(arr[l]);
		return;
	}
	int m = (l+r)>>1;
	build(l,m,idx<<1);
	build(m+1,r,idx<<1|1);
	tr[idx].clear();
	int siz1 = tr[idx<<1].size(),siz2 = tr[idx<<1|1].size(),lx=0,rx=0;
	while(lx<siz1&&rx<siz2){
		if(tr[idx<<1][lx]<tr[idx<<1|1][rx]){
			tr[idx].pb(tr[idx<<1][lx++]);
		}
		else if(tr[idx<<1][lx]>tr[idx<<1|1][rx]){
			tr[idx].pb(tr[idx<<1|1][rx++]);
		}
		else{
			tr[idx].pb(tr[idx<<1][lx++]);
			rx++;
		}
	}
	while(lx<siz1){
		tr[idx].pb(tr[idx<<1][lx++]);
	}
	while(rx<siz2){
		tr[idx].pb(tr[idx<<1|1][rx++]);
	}
}
vector<int> qq(int ql,int qr,int l,int r,int idx){
	if(ql<=l&&qr>=r){
		return tr[idx];
	}
	int m = (l+r)>>1;
	if(ql>m)return qq(ql,qr,m+1,r,idx<<1|1);
	if(qr<=m)return qq(ql,qr,l,m,idx<<1);
	vector<int> ans;
	vector<int> a = qq(ql,qr,l,m,idx<<1) , b = qq(ql,qr,m+1,r,idx<<1|1);
	int siz1 = a.size() ,siz2 = b.size() ,lx=0,rx = 0;
	while(lx<siz1&&rx<siz2){
		if(a[lx] < b[rx]){
			ans.pb(a[lx++]);
		}
		else if(a[lx]>b[rx]){
			ans.pb(b[rx++]);
		}
		else {
			ans.pb(a[lx++]);
			rx++;
		}
	}
	while(lx<siz1)ans.pb(a[lx++]);
	while(rx<siz2)ans.pb(b[rx++]);
	//for(auto i:ans)cout<<i<<"#";
	//cout<<'\n';
	return ans;
}
int main(){
	//IOS;
	int a,b;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		arr[i+1] = s[i] -'a' +1;
	}
	v.pb(1);
	int siz = s.size();
	for(int i=2;i<=siz;i++){
		if(arr[i]!=arr[i-1]){
			v.pb(i);
		}
	}
	
	build(1,siz,1);
	int q;
	cin>>q;
	while(q--){
		cin>>a>>b;
		vector<int> que = qq(a,b,1,siz,1);
		//for(auto i:que)cout<<i<<" ";
		//cout<<'\n';
		if(a==b){
			cout<<"Yes\n";
		}
		else if(que.size() >= 3){
			cout<<"Yes\n";
		}
		else if(que.size() == 2){
			if(arr[a]!=arr[b])cout<<"Yes\n";
			else cout<<"No\n";
		}
		else cout<<"No\n";
	}


}

