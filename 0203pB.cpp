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
struct movie{
	int num;
	int aud;
	int sub;
}; 
vector<movie> v;
vector<int> qq;
int arr[200005];
int main(){
	IOS;
	int n,t,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		qq.pb(arr[i]);
	}
	sort(all(qq));
	cin>>m;
	v.resize(m);
	for(int i=0;i<m;i++){
		v[i].num = i+1;
		cin>>v[i].aud;
	}
	for(int i=0;i<m;i++){
		cin>>v[i].sub;
	}
	int n1 = -1,n2= -1, nn=-1; 
	for(int i=0;i<m;i++){
		int ta = upper_bound(all(qq),v[i].aud)-lower_bound(all(qq),v[i].aud);
		int tb = upper_bound(all(qq),v[i].sub)-lower_bound(all(qq),v[i].sub);
		if(ta>n1){
			n1 = ta;
			n2 = tb;
			nn = v[i].num;
		}
		else if(ta == n1 && tb > n2){
			n2 = tb;
			nn = v[i].num;
		}
	}
	cout<<nn<<'\n';



}

