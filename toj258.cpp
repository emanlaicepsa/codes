#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> arr;
bool cmp(pii &a,pii &b){
	return a.first==b.first?a.second<b.second:a.first>b.first;
} 
int main(){
	int n;
	cin>>n;
	arr.resize(n);
	ll x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		arr[i]={x,y};
	}
	sort(arr.begin(),arr.end(),cmp);
	ll ans=(ll)1<<60;
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
			if((arr[j].first-arr[i].first)*(arr[j].first-arr[i].first)>=ans)break;
			ans=min(ans,(arr[j].first-arr[i].first)*(arr[j].first-arr[i].first)+(arr[j].second-arr[i].second)*(arr[j].second-arr[i].second)) ;
		}
	}
	cout<<fixed<<setprecision(6)<<sqrt(ans)<<'\n';
}

