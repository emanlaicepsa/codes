#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define pii pair<int,int>
#pragma GCC optimize ("O3")
using namespace std;
bool ok[65537][1605];
int sum[65537];
int area[20];
vector<int> divi[20];
int main(){
	IOS;
	int n,w,h,tx,ty,tz;
	cin>>n>>w>>h;
	for(int i=0;i<n;i++){
		cin>>area[i];
		for(int j=1;j<=area[i];j++){
			if(area[i]%j==0) divi[i].pb(j);
		}
	}
	for(int i=1;i<=1600;i++){
		ok[0][i]=1;
	}
	int all = (1<<n);
	for(int i=0;i<all;i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			int tmp = i^(1<<j);
			sum[i] = sum[tmp] + area[j];
			//cout<<i<<" "<<j<<'\n';
			for(auto k:divi[j]){
				if(ok[tmp][k]) ok[i][k]=1;
				int y = area[j]/k;
				if(sum[tmp]%y==0&&ok[tmp][sum[tmp]/y]){
					int nx = sum[tmp] / y;
					ok[i][nx + k] = 1;
				}
			}
			
		}
	}
	if(ok[all-1][w]){
		cout<<"Yes\n";
		int x = all-1 , narea = sum[all-1] ,nx = w;
		while(x){
			//cout<<x<<" "<<nx<<" "<<ny<<'\n';
			for(int i=0;i<n;i++){
				if(x&(1<<i)){
					int ny = narea/nx;
					if(area[i]%nx == 0 && ok[x^(1<<i)][nx]){
						cout<<i+1<<" "<<nx<<" "<<area[i]/nx<<'\n';
						narea -= area[i];
						x^=(1<<i);
						break;
					}
					else if(area[i]%ny ==0 && nx-area[i]/ny>=0&&ok[x^(1<<i)][nx-area[i]/ny]){
						int qq = area[i]/ny;
						cout<<i+1<<" "<<qq<<" "<<area[i]/qq<<'\n';
						nx -= qq;
						narea -= area[i];
						x^=(1<<i);
						break;
					}
				}
			}
		}
	}
	else{
		cout<<"No\n";
	}
}
