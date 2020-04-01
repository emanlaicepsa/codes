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
	IOS;
	int n,a,b;
	int ca = 0;
	cin>>n>>a>>b;
	int cnt = 0;
	for(int i=0,x;i<n;i++){
		cin>>x;
		if(x==2){
			if(b==0)cnt+=2;
			else b--;
		} 
		else{
			if(a>0) a--;
			else if(b>0) b--,ca++;
			else if(ca>0) ca--;
			
			else cnt++;
		}
	}
	cout<<cnt<<'\n';

}

