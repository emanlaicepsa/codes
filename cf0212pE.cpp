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
string a;
int dp[405][405];
int sa;

bool ok(string &b1,string &b2){
	memset(dp,0,sizeof(dp));
	int s1 = b1.size() , s2 = b2.size();
	b1 = "^" + b1;
	b2 = "&" + b2;
	dp[0][0] = 0;
	//cout<<a<<'\n';
	//cout<<b1<<'\n';
	//cout<<b2<<'\n';
	for(int i=0;i<=s1;i++){
		for(int j=0;j<=s2;j++){
			if(!i&&!j)continue;
			if(!i){
				int k = dp[i][j-1]+1;
				while(k<=sa && a[k]!=b2[j]) k++;
				dp[i][j] =  k;
			}
			else if(!j){
				int k = dp[i-1][j]+1;
				while(k<=sa && a[k]!=b1[i]) k++;
				dp[i][j] =  k;
			}
			else{
				int k = dp[i][j-1]+1;
				while(k<=sa && a[k]!=b2[j]) k++;
				int l = dp[i-1][j]+1;
				while(l<=sa && a[l]!=b1[i]) l++;
				dp[i][j] = min(l,k);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}
	}
	return dp[s1][s2]<=sa;
}

int main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		string b;
		cin>>a;
		sa = a.size();
		a = "%" +a;
		cin>>b;
		bool qq = 0;
		for(int i=0;i<b.size();i++){
			string b1 = "";
			string b2 = "";
			for(int j=0;j<i;j++)b1 += b[j];
			for(int j=i;j<b.size();j++) b2 += b[j];
			if(ok(b1,b2)){
				qq = 1;
				break;
			}
		}
		if(qq){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}


}

