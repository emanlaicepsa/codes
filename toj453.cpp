#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int main(){
	int n;
	cin>>n;
	for(int i=0,l=n+1,r=n+1;i<n+1;i++,l--,r++){
		for(int j=0;j<i+n+2;j++){
			if(j==l||j==r){
				cout<<"*";
				continue;
			}
			cout<<" "; 
		}
		cout<<"\n";
	}
	int row=n*2+3;
	for(int i=0;i<row;i++)cout<<"*";
	cout<<'\n';
	for(int j=0;j<n;j++){
		for(int i=0;i<n+1;i++)cout<<" ";
		cout<<"*\n";
	}
	for(int i=0;i<row;i++)cout<<"*";
	cout<<'\n';
	for(int i=0,l=1,r=1+2*n,m=n+1;i<n;i++,l++,r--){
		for(int j=0;j<2*n+2-i;j++){
			if(j==l||j==m||j==r){
				cout<<"*";
			}
			else cout<<" ";
		}
		cout<<'\n';
	}
	for(int i=0;i<row;i++)cout<<"*";
		cout<<'\n';
	}

