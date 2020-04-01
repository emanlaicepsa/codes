#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
string str1[30],str2[30];

int main(){
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++)cin>>str1[i];
	for(int i=0;i<b;i++)cin>>str2[i];
	int t,x;
	cin>>t;
	while(t--){
		cin>>x;
		x--;
		int an=x%a;
		int bn=x%b;
		//an ++;
		//aan%=a;
		cout<<str1[an]<<str2[bn]<<'\n';
	}



}

