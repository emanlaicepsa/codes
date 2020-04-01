#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
ll n;
vector<ll> v;
stack<pii> stk;
int main(){
	IOS;
	cin>>n;
	v.resize(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		int cnt=1;
		while(!stk.empty()){
			if(stk.top().first<v[i])
				sum+=stk.top().second,stk.pop();
			else if(stk.top().first==v[i])
				sum+=stk.top().second, cnt+=stk.top().second, stk.pop();
			else
				break;
		}
		if(!stk.empty())sum++;
		stk.push({v[i],cnt});
		//cout<<sum<<'\n';
	}
	
	reverse(v.begin(),v.end());
	
	while(!stk.empty())stk.pop();
	
	for(int i=0;i<n;i++){
		int cnt=1;
		while(!stk.empty()){
			if(stk.top().first<v[i])
				sum+=stk.top().second,stk.pop();
			else if(stk.top().first==v[i])
				sum+=stk.top().second, cnt+=stk.top().second, stk.pop();
			else
				break;
		}
		if(!stk.empty())sum++;
		stk.push({v[i],cnt});
		//cout<<sum<<'\n';
	}
	
	cout<<sum<<'\n';
}

