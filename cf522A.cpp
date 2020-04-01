#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
map<string,int> num;
vector<int> con[1000];
bool vis[1000];
int ans=0;
void dfs(int no,int de){
	vis[no]=1;
	ans=max(ans,de);
	for(int i:con[no]){
		if(!vis[i]){
			dfs(i,de+1); 
		}
	}
}


int main(){
	string a,b,c;
	int k=0;
	num["polycarp"]=0;
	int n;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		for(char &x:a){
			if(isupper(x)){
				x=tolower(x);
			}
		}
		for(char &x:c){
			if(isupper(x)){
				x=tolower(x);
			}
		}
		//cout<<a<<" "<<c<<endl;
		if(num.find(a)==num.end()){
			num[a]=++k;
		}
		if(num.find(c)==num.end()){
			num[c]=++k;
		}
		con[num[c]].emplace_back(num[a]);
		//cout<<num[a]<<" "<<num[c]<<endl;
	} 
	dfs(0,1);
	cout<<ans<<'\n';

}

