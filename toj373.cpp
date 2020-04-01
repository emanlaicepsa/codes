#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int x1,y1,x2,y2;
	int x,y;
	cin>>x1>>y1>>x2>>y2; 
	cin>>x>>y;
	if(x<x1)x=x2+(x1-x);
	if(y<y1)y=y2+(y1-y);
	double ans=0;
	ans+=(y2-y1)*(x2-x1);
	//cout<<x<<y<<endl;
	if(x>x2)ans+=(y2-y1)*(x-x2)/2.0;
	if(y>y2)ans+=(x2-x1)*(y-y2)/2.0;
	cout<<fixed<<setprecision(1)<<ans<<'\n';


}

