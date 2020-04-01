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
int arr1[200005],arr2[200005],di[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,k;
	cin>>n>>k;
	ll nowans = 0;
	for(int i=0;i<n;i++){
		cin>>arr1[i] , nowans += arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i] , di[i] = arr1[i] - arr2[i];
	}
	sort(di,di+n,cmp);
	for(int i=0;i<n-k;i++){
		if(di[i]<0)break;
		nowans -= di[i];
	}
	cout<<nowans<<'\n';

}

