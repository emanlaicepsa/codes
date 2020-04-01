#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<memory.h>
using namespace std;
bool noprime[10000005]={0};
vector<int> factor[10000005];
void primelist(){
	for(int a=2;a<=10000005;a++){
		if(noprime[a]==true)continue;
		for(int b=a;b<10000005;b+=a){
			noprime[b]=1;
			factor[b].push_back(a); 
		}
	}
}
int main(){
	for(int a=1;a<=10000005;a++)factor[a].push_back(1);
	primelist();
	int N;
	cin>>N;
	int a;
	while(N--){
		cin>>a;
	 	cout<<factor[a][factor[a].size()-2]<<" "<<factor[a][factor[a].size()-1]<<"\n";
	}

}


