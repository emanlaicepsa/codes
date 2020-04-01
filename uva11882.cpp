#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
char arr[20][20];
bool vis[20][20];
bool flood[20][20];
string ans;
string tmp;
int cnt;
int r,c;
struct dir{
	int x,y;
}d[4]={{0,1},{0,-1},{1,0},{-1,0}};

inline string fmax(string &a,string &b){
	if(a.size()!=b.size()){
		if(a.size()>b.size())return a;
		else return b;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			if(a[i]>b[i])return a;
			else return b;
		}
	}
	return a;
}

int floodfill(int x,int y){
	
	int ans=1;
	flood[x][y]=1;
	for(int i=0;i<4;i++){
		if(x+d[i].x>0&&x+d[i].x<=r&&y+d[i].y>0&&y+d[i].y<=c){
			if(!vis[x+d[i].x][y+d[i].y]&&arr[x+d[i].x][y+d[i].y]!='#'&&!flood[x+d[i].x][y+d[i].y]){
				ans+=floodfill(x+d[i].x,y+d[i].y);
			}
		}
	}
	return ans;
}


void dfs(int x,int y){
	for(int i=1;i<20;i++){
		for(int j=1;j<20;j++){
			flood[i][j]=0;
		}
	}
	int num=floodfill(x,y);
	
	if(tmp.size()+num<ans.size())return;
	if(tmp.size()+num==ans.size()){
		for(int i=0;i<tmp.size();i++){
			if(tmp[i]>ans[i])break;
			if(tmp[i]<ans[i])return;
		}
	}
	
	vis[x][y]=1;
	tmp+=arr[x][y];
	if(ans.size()==cnt && ans[0]>tmp[0]){
		vis[x][y]=0;
		tmp.pop_back();
		return;
	}
	//cout<<tmp<<'\n';
	ans=fmax(ans,tmp);
	for(int i=0;i<4;i++){
		if(x+d[i].x>0&&x+d[i].x<=r&&y+d[i].y>0&&y+d[i].y<=c){
			if(!vis[x+d[i].x][y+d[i].y]&&arr[x+d[i].x][y+d[i].y]!='#'){
				dfs(x+d[i].x,y+d[i].y);
			}
		}
	}
	tmp.pop_back();
	vis[x][y]=0;
}



int main(){
	IOS;
	while(cin>>r>>c){
		tmp="";
		ans="0";
		cnt=0;
		if(r==0)break;
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
				arr[i][j]=0,vis[i][j]=0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>arr[i][j];
				if(arr[i][j]!='#')cnt++;
			}
		}
		
		for(int k=9;k>=1;k--){
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(arr[i][j]==(char)(k+'0')){
						dfs(i,j);
					}		
				}
			}	
		}
		cout<<ans<<'\n';
	}



}
/*
3 7
##9784#
##123##
##45###
5 6
123456
456789
987654
123456
564532
0 0
*/
