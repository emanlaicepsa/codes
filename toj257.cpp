#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int dp[2][5005];
map <char,char> m;
int main(){
	m['A']='T';
	m['T']='A';
	m['C']='G';
	m['G']='C';
	IOS
	string a,b;
	while(cin>>a>>b){
		int alen=a.length();
		int blen=b.length();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<alen;i++){
			for(int j=0;j<blen;j++){
				if(i==0||j==0){
					if(a[i]==b[j])dp[i&1][j]=1;
					else {
						dp[i&1][j]=0;
						if(i)dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]);
						if(j)dp[i&1][j]=max(dp[i&1][j],dp[i&1][j-1]);
					}
				}
				else{
					if(a[i]==b[j])dp[i&1][j]=1+dp[(i-1)&1][j-1];
					else{
						dp[i&1][j]=max(dp[i&1][j-1],dp[(i-1)&1][j]);
					}
				}
			//	cout<<i<<" "<<j<<" "<<dp[i&1][j]<<endl;
			}
		}
		int ans=2*dp[(alen-1)&1][blen-1];
		int ansm=alen+blen;
		memset(dp,0,sizeof(dp));
		for(char &i:a){
			i=m[i];
		}
		for(int i=0;i<alen;i++){
			for(int j=0;j<blen;j++){
				if(i==0||j==0){
					if(a[i]==b[j])dp[i&1][j]=1;
					else {
						dp[i&1][j]=0;
						if(i)dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j]);
						if(j)dp[i&1][j]=max(dp[i&1][j],dp[i&1][j-1]);
					}
				}
				else{
					if(a[i]==b[j])dp[i&1][j]=1+dp[(i-1)&1][j-1];
					else{
						dp[i&1][j]=max(dp[i&1][j-1],dp[(i-1)&1][j]);
					}
				}
			//	cout<<i<<" "<<j<<" "<<dp[i&1][j]<<endl;
			}
		}
		ans=max(ans,2*dp[(alen-1)&1][blen-1]);
		if(ans==0)cout<<ans<<"/"<<ansm<<'\n';
		else cout<<ans/__gcd(ans,ansm)<<"/"<<ansm/__gcd(ans,ansm)<<'\n';
	}



}

