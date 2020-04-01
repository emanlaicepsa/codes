#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main(){
	ll a,b;
	while(cin>>a>>b){
		ll x=gcd(a,b);
		cout<<x<<endl;
	} 



}

