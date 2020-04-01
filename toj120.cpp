#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll arr[2000005];
ll ans[20005];
struct Que{
	ll s;
	ll e;
	ll id;
};
vector<Que> querys;
ll sqr;
bool cmp(Que &a,Que &b){
	return a.s/sqr==b.s/sqr?a.e<b.e:a.s/sqr<b.s/sqr; 
}
int main(){
	IOS;
	ll n;
	cin>>n;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll q;
	cin>>q;
	if(q>20000){
		while(1){
		}
	}
	ll t1,t2;
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		if(t1>t2)swap(t1,t2);
		querys.push_back({t1,t2,i});
	}
	ll nowans=0,l=0,r=0;
	sqr=sqrt(n);
	sort(querys.begin(),querys.end(),cmp);
	for(auto i:querys){
		while(r<i.e){
			r++;
			nowans+=arr[r];
		}
		while(r>i.e){
			nowans-=arr[r];
			r--;
		}
		while(l>i.s){
			l--;
			nowans+=arr[l];
		}
		while(l<i.s){
			nowans-=arr[l];
			l++; 
		}
		ans[i.id]=nowans;
	}
	

	for(int i=0;i<q;i++){
		cout<<ans[i]<<'\n';
	}

}

