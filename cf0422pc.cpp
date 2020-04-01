#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<cmath>
using namespace std;
vector <ll> Time;
vector<ll> ans;
ll gcd(ll a,ll b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	ll k;
	for(int x=0;x<n;x++){
		cin>>k;
		Time.emplace_back(k); 
	}
	for(int x=0;x<m;x++){
		cin>>k;
		ans.emplace_back(k); 
	}
	ll interval=Time[1]-Time[0];
	
	for(int x=0;x<n-1;x++){
		//cout<<x<<endl;
		if((Time[x+1]-Time[x])%interval!=0){
			interval=gcd(interval,(Time[x+1]-Time[x]));
		}	
		//cout<<interval<<endl;
	}
	 
	
	for(int x=0;x<m;x++){
		//cout<<x<<endl;
		if(interval%ans[x]==0){
			cout<<"YES"<<endl;
			cout<<Time[0]<<" "<<x+1<<endl; 
			return 0;
		}
	}
	cout<<"NO"<<endl;

}

