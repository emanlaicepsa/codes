#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
	int n;
	string tel;
	cin>>n;
	cin>>tel;
	int del=(n-11)/2;
	int count8=0,countother=0;
	for(int x=0;x<tel.length();x++){
		if((int)(tel[x]-'0')==8){
			count8++;
			if(count8==del+1){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		else{
			countother++;
			if(countother==del+1){
				cout<<"NO"<<endl;
				return 0;
			} 
		}
	}
	



}

