#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
map<int,int> go;
int main(){
	IOS;
	int n;
	cin>>n;
	int x;
	while(n--){
		cin>>x;
		if(!go[x])go[x]=0;
		go[x]++;
	}
	int m;
	cin>>m;
	while(m--){
		cin>>x;
		cout<<go[x]<<'\n';
	}
}

