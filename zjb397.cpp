#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) (n).begin(),(n).end()
#define pb emplace_back

using namespace std;
using ll=long long;
using pii=pair<int,int>;


ll dp[35][35];
vector<string> ans[35][35];

string a,b;
int siza,sizb;

int main(){
	IOS
	int t;
	int kas=0;
	cin>>t;
	while(t--){
		reset(dp,0);
		rep(i,35){
			rep(j,35){
				ans[i][j].clear();
			}
		}
		cin>>a>>b;
		siza=a.size();
		sizb=b.size();
		rep1(i,siza){
			rep1(j,sizb){
				//cout<<i<<j<<'\n';
				if(a[i-1]==b[j-1]){
					dp[i][j]=1+dp[(i-1)][j-1];
					if(!dp[(i-1)][j-1]){
						string s="";
						s+=a[i-1];
						ans[i][j].pb(s);
					}
					else{
						for(auto &str:ans[(i-1)][j-1]){
							ans[i][j].pb(str+a[i-1]);
						}
					}
				}
				
				else {
					dp[i][j]=max(dp[(i-1)][j],dp[i][j-1]);
					if(dp[i][j]==0)continue;
					if(dp[i][j]==dp[i-1][j]&&dp[i][j]==dp[i][j-1]){
						ans[i][j].resize(ans[i-1][j].size()+ans[i][j-1].size());
						//cout<<1<<'\n';
						//for(auto it:ans[i-1][j])cout<<it<<'\n';
						//for(auto it:ans[i][j-1])cout<<it<<'\n';
						merge(all(ans[i-1][j]),all(ans[i][j-1]),ans[i][j].begin());
						//sort(all(ans[i][j]));
						ans[i][j].resize(unique(all(ans[i][j]))-ans[i][j].begin());
						//for(auto it:ans[i][j])cout<<it<<'\n';
					}
					else if(dp[i][j]==dp[i-1][j]){
						ans[i][j]=ans[i-1][j];
					}
					else{
						ans[i][j]=ans[i][j-1];
					}
					
				}
				
				
			}
		}
		//cout<<dp[a.size()-1][b.size()-1]<<'\n';
		
		cout<<"Case #"<<++kas<<": ";
		if(dp[siza][sizb]==0){
			cout<<1<<'\n';
		}
		else{
			cout<<ans[siza][sizb].size()<<'\n';
			//sort(ans[siza][sizb].begin(),ans[siza][sizb].end());
			for(auto i:ans[siza][sizb])cout<<i<<'\n';
		}
		
	}



}

