#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
char a[502][502];
int x,y;
void flood(int q,int r){
	a[q][r]='.';
	for(int k=q+1;k<x;k++){
		if(a[k][r]!='*')break;
		a[k][r]='.';
	}
	for(int k=q-1;k>=0;k--){
		if(a[k][r]!='*')break;
		a[k][r]='.';
	}
	for(int k=r+1;k<y;k++){
		if(a[q][k]!='*')break;
		a[q][k]='.';
	}
	for(int k=r-1;k>=0;k--){
		if(a[q][k]!='*')break;
		a[q][k]='.';
	}
}
int main(){
	
	cin>>x>>y;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			cin>>a[i][j];
		
	bool plus=false;
	for(int i=1;i<x-1;i++)
		for(int j=1;j<y-1;j++)
			if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'){
			//	cout<<i<<" "<<j<<endl; 
				flood(i,j);
				plus=true;
				goto qq;	
			}
	qq:
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			//cout<<a[i][j];
			if(a[i][j]=='*'){
				plus=false;
				goto zz;
			}
		}
		//cout<<endl;
	}
	zz:
	if(plus)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}

