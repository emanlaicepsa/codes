#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define forn for(int i=0;i<n;i++)
using namespace std;
using ll= long long;
set<pair<int,int>> place;
int main(){
	int n,x0,y0;
	cin>>n>>x0>>y0;
	int t1,t2;
	forn{
		cin>>t1>>t2;
		t1-=x0;
		t2-=y0;
		if(t1==0)place.insert({0,0});
		else if(t2==0)place.insert({-1,-1});
		else{
			if((t1<0&&t2<0)||(t1>0&&t2<0)){
				t1=-t1;
				t2=-t2;
			}
			int t=__gcd(abs(t1),abs(t2));
			t1/=t;
			t2/=t;
			place.insert({t1,t2});	
		}
		
		
	}
	cout<<place.size()<<'\n';


}

