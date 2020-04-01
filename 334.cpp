#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
ll power2[40];
ll power3[40];
ll findans(ll x,ll y,ll number){
	//cout<<x<<" "<<y<<" "<<number<<endl; 
	ll q=power2[number];
	if(x==y&&x==q)return power3[number];
	else if(x<=0||y<=0)return 0;
	q>>=1;
	if(x<=q&&y<=q)return findans(x,y,number-1);
	else if(x>q&&y>q)return findans(q,q,number-1)+findans(x-q,q,number-1)+findans(q,y-q,number-1);
	else if(x>q)return findans(q,y,number-1)+findans(x-q,y,number-1);
	else return findans(x,q,number-1)+findans(x,y-q,number-1);
}



int main(){
	IOS;
	power2[0]=1;
	power3[0]=1;
	ll k=1,q=1;
	for(int i=1;i<=39;i++){
		k*=2;
		q*=3;
		power2[i]=k;
		power3[i]=q;
	}
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll ans=findans(c,d,39)-findans(a-1,d,39)-findans(c,b-1,39)+findans(a-1,b-1,39);
	cout<<ans<<endl;
	



}

