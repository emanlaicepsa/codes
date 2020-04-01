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

int arr[1005][1005];
int dp1[1005][1005];
int dp2[1005][1005];
int a1[1005][1005];
int a2[1005][1005];
int zx=-1,zy=-1;
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j] == 0){
				zx=i;
				zy=j;
				dp1[i][j] =dp2[i][j] = 1e9;
				continue;		
			}
			while(arr[i][j]%2==0){
				arr[i][j]/=2;
				a1[i][j] ++;
			}
			while(arr[i][j]%5==0){
				arr[i][j]/=5;
				a2[i][j] ++;
			}
		}
	}  
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(arr[i][j] == 0)continue;
			if(i==n-1 && j==n-1){
				dp1[i][j] = a1[i][j];
				dp2[i][j] = a2[i][j];
				continue;
			}
			dp1[i][j] = dp2[i][j] = 1e9;
			if(i<n-1){
				dp1[i][j] = min(dp1[i][j] , dp1[i+1][j] + a1[i][j]);
				dp2[i][j] = min(dp2[i][j] , dp2[i+1][j] + a2[i][j]);
			}
			if(j<n-1){
				dp1[i][j] = min(dp1[i][j] , dp1[i][j+1] + a1[i][j]);
				dp2[i][j] = min(dp2[i][j] , dp2[i][j+1] + a2[i][j]);
			}
		} 
	}
	//cout<<dp1[0][0]<<" "<<dp2[0][0]<<'\n';
	
	int x = 0 ,y = 0;
	
	if(min(dp1[0][0],dp2[0][0]) > 1 && zx>-1){
		cout<<1<<'\n';
		for(int i=0;i<zx;i++){
			cout<<"D";
		}
		for(int i=0;i<zy;i++){
			cout<<"R";
		}
		for(int i=zx+1;i<n;i++){
			cout<<"D";
		}
		for(int i=zy+1;i<n;i++){
			cout<<"R";
		}
		return 0;
	}
	if(dp1[0][0] < dp2[0][0]){
		cout<<dp1[0][0]<<'\n';
		while(x<n-1||y<n-1){
			if(x==n-1){
				cout<<"R";
				y++;
			}
			else if(y==n-1){
				cout<<"D";
				x++;
			}
			else{
				if(dp1[x+1][y] < dp1[x][y+1]){
					cout<<"D";
					x++;
				}
				else{
					cout<<"R";
					y++;	
				}
			}
		}
		cout<<'\n';
	}
	else{
		cout<<dp2[0][0]<<'\n';
		while(x<n-1||y<n-1){
			if(x==n-1){
				cout<<"R";
				y++;
			}
			else if(y==n-1){
				cout<<"D";
				x++;
			}
			else{
				if(dp2[x+1][y] < dp2[x][y+1]){
					cout<<"D";
					x++;
				}
				else{
					cout<<"R";
					y++;	
				}
			}
		}
		cout<<'\n';
	}
	

}

