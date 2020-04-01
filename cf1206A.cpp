#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll a[105];
ll b[105];
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+m);
	cout<<a[n-1]<<" "<<b[m-1]<<'\n';

}

