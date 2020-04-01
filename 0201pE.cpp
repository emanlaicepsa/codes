#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int add[5005];
int main(){
	for(int i=1;i<=5000;i++){
		add[i] = add[i-1] + i;
	}
	ll k;
	cin>>k;
	if(k==0){
		cout<<'a';
		return 0;
	}
	char now = 'a';
	while(k){
		int x = upper_bound(add,add+5000,k) - 1 - add;
		for(int i=0;i<x+1;i++){
			cout<<now;
		}
		k -= add[x];
		now++;
	}



}

