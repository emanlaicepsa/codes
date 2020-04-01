#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll suma=0,sumb=0;
	a%=c;
	b%=c;
	ll sum=((a*b)%c)*((a-b)%c);
	sum%=c;
	while(sum<0)sum+=c;
	cout<<sum<<endl;


}

