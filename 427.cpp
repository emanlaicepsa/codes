#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<memory.h>
using namespace std;
bool noprime[1000005]={0};
long long ans[1000005]={0};
long long phi[1000005]={0};
vector<int> factor[1000005];
void primelist(){
	for(int a=2;a<=1000005;a++){
		if(noprime[a]==true)continue;
		for(int b=2*a;b<1000005;b+=a){
			noprime[b]=1;
			factor[b].push_back(a); 
		}
	}
}
long long findphi(int x){
	if(phi[x])return phi[x];
	else if (noprime[x]==false)return phi[x]=x-1;
	else {
		ll num=x;
		for(int q=0;q<factor[x].size();q++){
			num/=factor[x][q];
			num*=(factor[x][q]-1);
		}
		return phi[x]=num;
	}
}
int main(){
	primelist();
	ans[1]=0;
	for(int a=2;a<=1000005;a++){
		ans[a]=ans[a-1]+findphi(a);
	}
	/*for(int a=1;a<=100;a++){
		cout<<a<<" ";
		for(int x:factor[a])cout<<x<<" ";
		cout<<endl;
		cout<<ans[a]*2+3<<endl;
	}*/
	int N;
	while(cin>>N){
		if(N==0)cout<<0<<"\n";
		else cout<<ans[N]*2+3<<"\n";
	}

}

