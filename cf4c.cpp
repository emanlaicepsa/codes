#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
map<string,int> words;

int main(){
	int n;
	cin>>n;
	string temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(words.find(temp)!=words.end()){
			cout<<temp<<words[temp]<<"\n";
			words[temp]++;
		}
		else {
			cout<<"OK"<<"\n";
			words[temp]=1;
		}
	}	



}

