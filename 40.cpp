#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll gcd(ll x,ll y){
	if(y==0)return x;
	else return gcd(y,x%y);
}

int main(){
	ll x,y;
	while(cin>>x>>y){
		cout<<x/gcd(x,y)*y<<endl;
	}



}

