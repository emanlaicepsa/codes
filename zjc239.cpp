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
ll dpmin[70000][20];
ll dpmax[70000][20];
ll E[20][20];
int main(){
	int n;
	while(cin>>n){
		reset(dpmin,0x3f);
		reset(dpmax,0);
		reset(E,0);
		rep(i,n){
			for(int j=i+1;j<n;j++){
				cin>>E[i][j];
				E[j][i]=E[i][j];
			}
		}
		n--;
		for(int i=1;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					if(i==(1<<(j-1))){
						dpmin[i][j]=E[0][j];
						dpmax[i][j]=E[0][j]; 
					}
					else{
						for(int k=1;k<=n;k++){
							if((i^(1<<(j-1)))&(1<<(k-1))){
								dpmin[i][j]=min(dpmin[i][j],dpmin[i^(1<<(j-1))][k]+E[k][j]);
								dpmax[i][j]=max(dpmax[i][j],dpmax[i^(1<<(j-1))][k]+E[k][j]);
							}
						}	
					}
					
				}
			}
		}
		ll mi=(ll)1e18;
		ll ma=0;
		rep1(i,n){
			mi=min(mi,dpmin[(1<<n)-1][i]+E[0][i]),ma=max(ma,dpmax[(1<<n)-1][i]+E[0][i]);
		}
		ll gg=__gcd(ma,mi);
		ma/=gg;
		mi/=gg;
		if(mi==1)cout<<ma<<"\n";
		else cout<<ma<<"/"<<mi<<'\n';
	}
	 



}

