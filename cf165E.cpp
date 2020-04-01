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
ll mask[5000005];
ll arr[1000005];
int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mask[arr[i]] = arr[i];
	}
	int all = (1<<22)-1;
	for(int i=1;i<all;i++){
		for(int j=1;j<=22;j++){
			if(i&(1<<(j-1)))mask[i] = max(mask[i],mask[i^(1<<(j-1))]);
		}
	}
	for(int i=0;i<n;i++){
		ll trans = arr[i]^all;
		//cout<<trans<<'\n';
		if(mask[trans])cout<<mask[trans]<<' ';
		else cout<<-1<<' ';
	}


}

