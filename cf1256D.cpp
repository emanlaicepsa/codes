#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	ll t,n,k;
	cin>>t;
	string s;
	while(t--){
		cin >>n>>k;
		cin>>s;
		int cnt1=0;
		int i;
		for(i=0;i<n;i++){
			if(s[i]=='0'){
				if(k<i-cnt1)break;
				k-=(i-cnt1);
				swap(s[cnt1],s[i]);
				cnt1++;
			}
		}
		int spe;
		if(i<n){
			spe=i-k;
			swap(s[spe],s[i]);
		}
		cout<<s<<'\n';
			
		
		
	} 



}

