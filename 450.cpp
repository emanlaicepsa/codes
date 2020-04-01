#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
	ll c;
	ll x[3],y[3];
	cin>>c;
	if(c==0){
		cout<<0<<endl;
		return 0;
	}
	ll maxx=-2147483647,minx=2147483647,maxy=-2147483647,miny=2147483647;
	for(int k=0;k<3;k++){
		cin>>x[k]>>y[k];
		maxx=max(maxx,x[k]);
		minx=min(minx,x[k]);
		maxy=max(maxy,y[k]);
		miny=min(miny,y[k]);
	}
	ll ans=(maxx-minx)*(maxy-miny)*2;
	ll minus=0;
	minus+=abs((x[0]-x[1])*(y[0]-y[1]));
	minus+=abs((x[2]-x[0])*(y[2]-y[0]));
	minus+=abs((x[2]-x[1])*(y[2]-y[1]));
	ans-=minus;
	ans=ans*c/2;
	cout<<ans<<endl;



}

