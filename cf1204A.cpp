#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
using pii=pair<int,int>;
int main(){
	string s;
	cin>>s;
	int k=1;
	int cnt1=0;
	int cnt2=0;
	int ans=0;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='1'){
			ans=(k+1)/2;
			if(k&1)cnt1++;
			else cnt2++;
		}
		k++;
	}
	if(cnt1==1&&cnt2==0){
		ans--;
	}
	cout<<ans<<endl;
	
}

