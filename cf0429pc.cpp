#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_wiith_stdio(false);cin.tie(0);
using namespace std;
int num[3]={0};
int main(){
	int n;
	cin>>n;
	int T;
	for(int a=0;a<n;a++){
		cin>>T;
		if(T==1)num[1]++;
		else num[2]++;
	}
	if(num[2]==0){
		for(int a=0;a<num[1];a++){
			cout<<1;
			if(a!=num[1]-1)cout<<" ";
		}
		cout<<endl;
	}
	else if(num[1]==0){
		for(int a=0;a<num[2];a++){
			cout<<2;
			if(a!=num[2]-1)cout<<" ";
		}
		cout<<endl;
	}
	else{
		num[1]--;
		num[2]--;
		cout<<2<<" "<<1<<" ";
		for(int a=0;a<num[2];a++){
			cout<<2;
			cout<<" ";
		}
		for(int a=0;a<num[1];a++){
			cout<<1;
			if(a!=num[1]-1)cout<<" ";
		}
		cout<<endl;
	}

}

