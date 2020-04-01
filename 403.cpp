#include <iostream>
#include <algorithm>
#include <vector>
#include<memory.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int dp[22][22][4]; 
int block[22][22];
bool visited[22][22];
int H,W,X,Y;
struct D{
	int x;
	int y;
}d[4];
int godp(int x,int y,int dir){
	cout<<x<<" "<<y<<" "<<dir<<endl;
	if(x==1&&y==1){
		cout<<'!'<<endl;
		return block[1][1];
	}
	if(x<=0||y<=0||x>H||y>W){
		cout<<'$'<<endl;
		return 10000000;
	}
	if(dp[x][y][dir]<10000000) {
		cout<<'%'<<dp[x][y][dir]<<endl;
		return dp[x][y][dir];
	}
	if(visited[x+d[dir].x][y+d[dir].y]){
		cout<<'#'<<endl;
		return 10000000;
	}
	visited[x][y]=1;
	dp[x][y][dir]=block[x][y]+min(godp(x+d[dir].x ,y+d[dir].y,(dir+1)%4),godp(x+d[dir].x ,y+d[dir].y,dir));
	visited[x][y]=0;
	cout<<"@"<<x<<" "<<y<<" "<<dir<<" "<<dp[x][y][dir]<<endl;
	return dp[x][y][dir];
}


int main(){
	d[0]={1,0};
	d[1]={0,1};
	d[2]={-1,0};
	d[3]={0,-1};
	for(int i=1;i<=22;i++)
		for(int j=1;j<=22;j++)
			for(int k=0;k<4;k++)
				dp[i][j][k]=10000000;
	cin>>H>>W>>X>>Y;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			cin>>block[i][j];
	int ans=2147483647;
	for(int i=0;i<4;i++){
		ans=min(ans,godp(X,Y,i));
	}
	cout<<ans<<endl;
	



}

