#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define forn for(int i=0;i<n;i++)
using namespace std;
using ll= long long;
int pos[30][200005];
int cntmom[30];
int cntson[30];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string mom;
	cin>>mom;
	for(int i=0;i<n;i++){
		int x=mom[i]-'a';
		cntmom[x]++;
		pos[x][cntmom[x]]=i;
	}
	int q;
	cin>>q;
	string tofind;
	
	while(q--){
		memset(cntson,0,sizeof(cntson));
		int ans=-1;
		cin>>tofind;
		for(int i=0;i<tofind.length();i++){
			int x=tofind[i]-'a';
			cntson[x]++;
			ans=max(ans,pos[x][cntson[x]]);
		}
		cout<<ans+1<<'\n';
		
	} 



}

