#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll dp[1005][1005];
int main(){
	
	string s,t;
	cin>>s>>t;
	int sizs=s.size();
	int sizt=t.size();
	rep1(i,sizs)dp[i][0]=i;
	rep1(i,sizt)dp[0][i]=i;
	rep1(i,sizs){
		rep1(j,sizt){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]})+1;
			}
		}
	}
	cout<<dp[sizs][sizt]<<'\n';
	int idx1=sizs,idx2=sizt;
	while(idx1||idx2){
		//cout<<idx1<<" "<<idx2<<'\n';
		if(!idx1){
			cout<<"INSERT "<<idx1+1<<" "<<t[idx2-1]<<'\n';
			idx2--;
			
		}
		else if(!idx2){
			cout<<"DELETE "<<idx1<<'\n';
			idx1--;
		}
		else if(s[idx1-1]==t[idx2-1]){
			idx1--;
			idx2--;
		}
		else{
			if(dp[idx1][idx2]==dp[idx1-1][idx2-1]+1){
				cout<<"REPLACE "<<idx1<<" "<<t[idx2-1]<<'\n'; 
				idx1--;
				idx2--;
			}
			else if(dp[idx1][idx2]==dp[idx1-1][idx2]+1){
				cout<<"DELETE "<<idx1<<'\n';
				idx1--;
			}
			else if(dp[idx1][idx2]==dp[idx1][idx2-1]+1){
				cout<<"INSERT "<<idx1+1<<" "<<t[idx2-1]<<'\n';
				idx2--;
			}
		}
	}

}

