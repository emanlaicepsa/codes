#include <iostream>
#include <algorithm>
#include <vector>
#include<sstream>
#include<map>
#define ll long long
using namespace std;
map<string,int> dict;
vector<string> all;
vector<string> ans;

void findmap(string x){
	string z=x;
	for(int q=0;q<x.length();q++){
		x[q]=tolower(x[q]);	
	}
	sort(x.begin(),x.end());
	//cout<<x<<endl;
	if(!dict[x]){
		dict[x]=0;
	}
	dict[x]++;
}
string gogo(string x){
	for(int q=0;q<x.length();q++){
		x[q]=tolower(x[q]);	
	}
	sort(x.begin(),x.end());
	return x;
}
int main(){
	string in;
	stringstream ss;
	string out;
	dict.clear();
	all.clear();
	ans.clear();
	while(getline(cin,in)){
		if(in=="#"){
			break;
		}
		ss.str("");
		ss.clear();
		ss<<in;
		while(ss>>out){
			all.emplace_back(out);
			findmap(out);
		}
	}
	for(string q:all){
		if(dict[gogo(q)]==1){
			ans.emplace_back(q); 
		}
	}
	
	
	sort(ans.begin(),ans.end());
	for(string y:ans){
		cout<<y<<endl;
	}


}

