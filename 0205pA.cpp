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
map<int,int> m;
int arr[2][2005];
bool exi[4100000];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			exi[arr[i][j]] = 1;
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(exi[arr[0][i] ^ arr[1][j]]) cnt++;
		}
	}
	if(cnt&1){
		cout<<"Koyomi\n";
	}
	else cout<<"Karen\n";

}

