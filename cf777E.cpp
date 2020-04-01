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
struct hanoi{
	ll in;
	ll out;
	ll val;
};
vector<hanoi> v;
bool cmp(hanoi a,hanoi b){
	return (a.out!=b.out)?(a.out>b.out):(a.in>b.in);
}
vector<int> dis;
int n,ta,tb,tc;
ll bit[100005];
void mod(int pos,ll val){
	//if(bit[pos]>=val)return;
	for(int i=pos;i<=n;i+=(i&-i))bit[i]=max(bit[i],val);
}
ll que(int pos){
	ll ans=0;
	for(int i=pos;i>=1;i-=(i&-i))ans=max(ans,bit[i]);
	return ans;
}
int main(){
	IOS
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ta>>tb>>tc;
		v.pb({ta,tb,tc});
	}
	sort(all(v),cmp);
	dis.pb(0);
	for(auto x:v){
		dis.pb(x.in);		
	}
	sort(all(dis));
	dis.resize(unique(all(dis))-dis.begin());
	ll ans=0;
	for(auto x:v){
		ll pos=lower_bound(all(dis),x.out)-1-dis.begin();
		ll ta;
		if(pos){
			ta=que(pos)+x.val;
		}
		else{
			ta=x.val;
		}
		mod(lower_bound(all(dis),x.in)-dis.begin(),ta);
		ans=max(ans,ta);
	}
	cout<<ans<<'\n';
	


}

