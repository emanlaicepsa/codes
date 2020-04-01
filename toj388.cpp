#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<int> pos1;
int arr[4000005];
set<int> ans;
void tobi(char x,int p){
	int k;
	if(x>='0'&&x<='9'){
		k=x-'0';
	}
	else{
		k=10+x-'a';
	}
	//cout<<k<<'\n';
	for(int i=0;i<4;i++){
		if(k&1)arr[p-i]=1;
		else arr[p-i]=0;
		k>>=1;
	} 
} 
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		tobi(s[i],i*4+3);
	}
	/*for(int i=0;i<s.size()*4;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;*/
	for(int i=0;i<s.size()*4;i++){
		if(arr[i]==1){
			pos1.push_back(i);
		}
	}
	
	if(pos1.size()>=3){
		for(int i=0;i<pos1.size()-2;i++){
	//	cout<<pos1[i]<<'\n';
		if(pos1[i+1]-pos1[i]==pos1[i+2]-pos1[i+1]&&(s.size()*4-pos1[i+2]-1)%(pos1[i+1]-pos1[i])==0){
			ans.insert(pos1[i+1]-pos1[i]);
		}
	}
	}
	for(auto i:ans){
		cout<<i<<'\n';
	}

}

