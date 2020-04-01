#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==1){
			if(b==1)cout<<"yes\n";
			else cout<<"no\n";
		}
		else if(a<=3){
			if(b<=3)cout<<"yes\n";
			else cout<<"no\n";
		}
		else cout<<"yes\n";
	}



}

