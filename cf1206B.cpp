#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
int cnt=0;
int inus=0;

int main(){
	ll ans=0;
	int n;
	cin>>n;
	ll temp;
	while(n--){
		cin>>temp;
		if(temp>0)ans+=temp-1;
		if(temp<0)ans+=-1-temp,inus++;
		if(temp==0)cnt++,ans+=1;
	}
	if((inus&1)&&cnt==0){
		ans+=2;
	}
	cout<<ans<<endl;


}

