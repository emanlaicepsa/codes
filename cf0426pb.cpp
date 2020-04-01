#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<map>
using namespace std;
int table[10];
int main(){
	int n;
	cin>>n;
	string x;
	cin>>x;
	int k;
	for(int a=1;a<=9;a++){
		cin>>k;
		table[a]=k;
	}

	bool go=false;
	bool havegone=false;
	for(int a=0;a<x.length();a++){
		if(havegone==true&&go==false)break;
		if(x[a]<(table[int(x[a]-'0')]+'0')){
			x[a]=table[int(x[a]-'0')]+'0';
			havegone=true;
			go=true;
		}
		else if(x[a]>(table[int(x[a]-'0')]+'0')){
			go=false;
		}
	}
	cout<<x<<endl;


}

