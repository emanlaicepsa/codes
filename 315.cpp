#include <iostream>
#include <algorithm>
#include <vector>
#define ll unsigned long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
	ll T,a,b,M;
	cin>>T;
	while(T--){
		cin>>a>>b>>M; 
		ll k=1;
		ll ans=1;
		a%=M;
		while(k<=b){
			//cout<<k<<endl;
			if(k&b){
				ans*=a;
				ans%=M;
			}
			a=a*a;
			a%=M;
			k<<=1;
		}
		ans%=M;
		cout<<ans<<endl;
	}
	 



}

