#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n%2!=0)cout<<0<<endl;
	else{
	ll ans=pow(2,n/2);
	cout<<ans<<endl;
	}



}

