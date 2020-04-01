#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define forn for(int i=0;i<n;i++)
using namespace std;
using ll= long long;
ll sum[500005];
vector<int> ans1;
vector<int> ans2; 


int main(){
	IOS;
	int n;
	cin>>n;
	forn{
		cin>>sum[i];
		if(i>0)sum[i]+=sum[i-1];
	}
	if(sum[n-1]%3){
		cout<<0<<'\n';
		return 0;
	} 
	ll ansnum=sum[n-1]/3;
	ll ans=0;
	for(int i=0;i<n-1;i++){
		if(sum[i]==ansnum*2)ans2.emplace_back(i);
		if(sum[i]==ansnum){
			ans1.emplace_back(i);
			ans-=ans2.size();
		}
		
	}
	ll a=ans1.size();
	ll b=ans2.size();
	ll c=a*b;
	ans+=c;
	cout<<ans<<'\n';
	



}

