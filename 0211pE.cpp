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
string arr[105];
vector<int> E[30];
int in[30];
bool used[30];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		bool f = 0;
		if(i){
			int siz = min(arr[i].size(),arr[i-1].size());
			for(int j=0;j<siz;j++){
				if(arr[i][j] != arr[i-1][j]){
					f = 1;
					E[arr[i-1][j]-'a'].pb(arr[i][j]-'a');
					in[arr[i][j]-'a']++;
					break;
				}
			}
			if(!f&&arr[i].size() < arr[i-1].size()){
				cout<<"Impossible\n";
				return 0;
			}
		}
	}
	vector<char> ans;
	queue<int> q;
	for(int i=0;i<26;i++){
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int x = q.front();q.pop();
		ans.pb(x+'a');
		for(auto i:E[x]){
			in[i] --;
			if(!in[i])q.push(i);
		}
	}
	if(ans.size() < 26){
		cout<<"Impossible\n";
	}
	else{
		for(auto i:ans){
			cout<<i;
		}
		cout<<'\n';
	}

}

