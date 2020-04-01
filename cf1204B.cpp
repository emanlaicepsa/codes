#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
int main(){
	ll n,l,r;
	cin>>n>>l>>r;
	ll minans=1,maxans=1;
	ll curmin=1,curmax=1;
	for(int i=2;i<=n;i++){
		if(i<=r){
			curmax<<=1;
		}
		if(n-i+2<=l){
			curmin<<=1;
		}
		minans+=curmin;
		maxans+=curmax;
	}
	cout<<minans<<" "<<maxans<<endl;


}

