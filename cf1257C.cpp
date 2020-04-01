#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<int> pos[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,te;
		cin>>n;
		for(int i=1;i<=n;i++){
			pos[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>te;
			pos[te].push_back(i);
		}
		int minn=21474456;
		for(int i=1;i<=n;i++){
			if(pos[i].size()<2)continue;
			for(int j=0;j<pos[i].size()-1;j++){
				minn=min(minn,pos[i][j+1]-pos[i][j]+1);
			}
		}
		if(minn==21474456)cout<<-1<<'\n';
		else cout<<minn<<'\n';
	}



}

