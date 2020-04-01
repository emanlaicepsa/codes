#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct Matrix{
	ll T[2][2];
};
Matrix mul(Matrix a,Matrix b){
	Matrix c;
	for(ll i=0;i<2;i++){
		for(ll j=0;j<2;j++){
			c.T[i][j]=0;
			for(ll k=0;k<2;k++){
				c.T[i][j] += a.T[i][k] * b.T[k][j];
			}
		}
	}
	return c;
}
Matrix power(Matrix a,ll b){
	Matrix c=a;
	while(b>0){
		if(b&1){
			a=mul(a,c);
		}
		c=mul(c,c);
		b>>=1;
	}
	return a;
}



int main(){
	ll n;
	cin>>n;
	Matrix a;
	a.T[0][0]=1;
	a.T[0][1]=1;
	a.T[1][0]=1;
	a.T[1][1]=0;
	Matrix b;
	b=power(a,n-2);
	ll ans=b.T[0][0];
	cout<<ans<<endl;



}

