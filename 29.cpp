#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<string>
#include<unordered_map>
using namespace std;
string x;
unordered_map<string, int> M; 
void go(int a){
	string str;
	for(int i=a,j=0;i<x.size();i++){
		str.assign(x,j,i);
	}
	cout<<str<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		M.clear();
		cin>>x;
		for(int i=1;i<=50&&i<=x.size();i++){
			go(i);
		}
		string y;
		cin>>y;
		if(M[y]>0)cout<<"y\n";
		else cout<<"n\n";
	}



}

