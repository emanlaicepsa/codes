#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	IOS
	string s;
	while(getline(cin,s)){
		int cnt=0;
		stringstream ss;
		ss<<s;
		int i;
		while(ss>>i){
			cnt++;
		}
		cout<<cnt<<'\n';
	}



}

