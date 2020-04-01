#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<ll> mem;
ll go[2000000];
int main(){
	int N;
	cin>>N;
	ll k;
	for(int i=0;i<N;i++){
		cin>>k;
		mem.push_back(k); 
	}
	ll siz=mem.size()-1;
	for(int i=0;i<siz;i++)mem.push_back(mem[i]);
	//for(ll i:mem)cout<<i<<" ";
	ll ans=0;
	go[0]=1;
	for(int i=1;i<mem.size();i++){
		go[i]=1;
		if(mem[i]>go[i-1])go[i]=go[i-1]+1;
		else go[i]=mem[i];
		ans=max(ans,go[i]);
		cout<<go[i]<<endl;
	}
	if(ans>N)ans=N;
	cout<<ans<<endl;
}

