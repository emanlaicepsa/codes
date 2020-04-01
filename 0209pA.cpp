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
int main(){
	int t;
	cin>>t;
	while(t--){
		int csum = 0;
		int ze = 0;
		int n;
		cin>>n;
		for(int i=0,a;i<n;i++){
			cin>>a;
			if(a==0)ze ++;
			csum +=a;
		}
		csum += ze;
		cout<<ze+(csum==0)<<'\n';
	} 



}

