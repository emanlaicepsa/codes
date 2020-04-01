#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,ll>;
vector<int> arr[1000005];
pii ori[1000005];
ll a[1000005];
vector<int> d;
ll n,m;
bool cmp(pii &a, pii &b){
	return a.second>b.second;
}
map<pii,ll> ta;
ll go(int pos,ll num){
	//cout<<pos<<" "<<num<<'\n';
	if(num==0||pos<0)return 0;
	if(num>=n){
		//cout<<a[pos]<<'\n';
		return a[pos];
	}
	if(ta.find({pos,num})!=ta.end()){
		
		//cout<<'@'<<ta[{pos,num}] <<'\n';
		return ta[{pos,num}];
	} 
	int dif=0;
	if(pos)dif=d[pos]-d[pos-1];
	ll ans=go(pos-1,num*((ll)1<<dif));
	ll t=0;
	int idx=0;
	int k=num;
	while(k>0&&idx<arr[pos].size()){
		k--;
		t+=arr[pos][idx++];
		ans=max(ans,t+go(pos-1,k*((ll)1<<dif)));
	}
	//cout<<ans<<'\n';
	return ta[{pos,num}]=ans;
}



int main(){
	IOS;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ori[i].first>>ori[i].second;
		d.emplace_back(ori[i].first);
	}
	sort(d.begin(),d.end());
	sort(ori,ori+n,cmp);
	d.resize(unique(d.begin(),d.end())-d.begin());
	int siz=d.size();
	for(int i=0;i<n;i++){
		auto j=lower_bound(d.begin(),d.end(),ori[i].first)-d.begin();
		arr[j].emplace_back(ori[i].second);
		a[j]+=ori[i].second;
	}
	for(int i=1;i<siz;i++){
		a[i]+=a[i-1];
	}

	auto n=upper_bound(d.begin(),d.end(),m)-1;
//	cout<<n-d.begin()<<'\n'; 
	ll x=m-*n;
	ll ans=go(n-d.begin(),(ll)1<<x);
	cout<<ans<<'\n';
}

