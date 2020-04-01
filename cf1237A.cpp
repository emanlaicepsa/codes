#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int odnum=0;
	IOS;
	int n,tem;
	cin>>n;
	while(n--){
		cin>>tem;
		if(tem%2==0)cout<<tem/2<<'\n';
		else{
			odnum++;
			if(tem<0&&odnum&1){
				cout<<tem/2<<'\n';
			}
			else if(tem<0)cout<<(tem-1)/2<<'\n';
			else if(odnum&1)cout<<(tem+1)/2<<'\n';
			else cout<<tem/2<<'\n';
		}
	}



}

