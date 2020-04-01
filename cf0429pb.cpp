#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_wiith_stdio(false);cin.tie(0);
using namespace std;
char flood[50][50]={0};
int n;
bool gogo(int a,int b){
	if(a>=n-2)return false;
	if(b==0||b==n-1)return false;
	flood[a][b]='#';
	for(int k=b-1;k<=b+1;k++){
		if(flood[a+1][k]!='.')return false;
		else{
			flood[a+1][k]='#';
		}
	}
	if(flood[a+2][b]!='.')return false;
	else{
		flood[a+2][b]='#';
	}
	return true;
}


int main(){
	
	cin>>n;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			cin>>flood[a][b];
		}
	}
	/*for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			cout<<flood[a][b];
		}
		cout<<endl;
	}*/
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(flood[a][b]=='.'){
				bool can=gogo(a,b);
				if(!can){
					cout<<"NO"<<endl; 
					return 0;
				}
			}
		}
	}
	cout<<"YES"<<endl;

}

