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
char arr[6][6];
int top[6][6];
int le[6][6];
int c1[6][6];
int c2[6][6];
int dn[6][6];
int ri[6][6];
int rc1[6][6];
int rc2[6][6];

int main(){
	IOS;
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='x'){
				top[i][j] = top[i-1][j]+1;
				le[i][j] = le[i][j-1]+1;
				c1[i][j] = c1[i-1][j-1]+1;
				c2[i][j] = c2[i-1][j+1]+1;
			}
		}
	}
	for(int i=4;i>=1;i--){
		for(int j=4;j>=1;j--){
			if(arr[i][j]=='x'){
				dn[i][j] = dn[i+1][j] + 1;
				ri[i][j] = ri[i][j+1] + 1;
				rc1[i][j] = rc1[i+1][j+1] + 1;
				rc2[i][j] = rc2[i+1][j-1] + 1;
			}
		}
	}
	bool ok = 0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(arr[i][j] == '.'){
				if(le[i][j-1] + ri[i][j+1] >= 2 || top[i-1][j] + dn[i+1][j]>= 2 || c1[i-1][j-1] + rc1[i+1][j+1] >= 2 || c2[i-1][j+1] + rc2[i+1][j-1] >= 2) ok = 1;
			}
			//if(arr[i-1][j] == 'x' && arr[i+1][j] == 'x')
		}
	}
	cout<<(ok?"YES\n":"NO\n"); 


}

