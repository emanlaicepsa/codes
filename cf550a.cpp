#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
vector<int> ab;
vector<int> ba;
int main(){
	string s;
	cin>>s;
	bool can=false;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]=='A'&&s[i+1]=='B'){
			ab.emplace_back(i);
		}
		if(s[i]=='B'&&s[i+1]=='A'){
			ba.emplace_back(i);
		}
	}
	for(int i:ba){
		for(int j:ab){
			if(abs(i-j)>=2){
				can=1;
				break;
			}
		}
	}
	if(can)cout<<"YES\n";
	else cout<<"NO\n";


}

