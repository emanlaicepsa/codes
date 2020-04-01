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
	int ml=1e9,mr=0,mt=1e9,md=0;
	IOS;
	int n,m;
	char c;
	cin>>n>>m;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='B'){
				ml = min(ml,j);
				mr = max(mr,j);
				mt = min(mt,i);
				md = max(md,i);
				cnt++;
			}
		}
	} 
	int w = mr-ml+1;
	int h = md-mt+1;
	if(cnt==0){
		cout<<1<<'\n';
	}
	else if(w > h){
		if(n<w){
			cout<<-1<<'\n';
		}
		else{
			cout<<w*w-cnt<<'\n';
		}
	}
	else{
		if(m<h){
			cout<<-1<<'\n';
		}
		else{
			cout<<h*h-cnt<<'\n';
		}
	}

}

