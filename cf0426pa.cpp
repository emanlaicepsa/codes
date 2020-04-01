#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<set>

using namespace std;
set <ll> found;
ll f(ll x){
	x+=1;
	while(x%10==0){
		x/=10;
	}
	return x;
}
int main(){
	ll n;
	cin>>n;
	found.insert(n);
	while(1){
		n=f(n);
		if(found.count(n))break;
		found.insert(n);
	} 
	cout<<found.size()<<endl;


}

