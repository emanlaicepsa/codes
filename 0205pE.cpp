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
int arr[200005];
deque<int> now;
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int cnt = 0;
	for(int i=0;i<n;i++){
		while(!now.empty() && arr[i] - now[0] >=m )now.pop_front();
		now.pb(arr[i]);
		if(now.size() >= k){
			cnt++;
			now.pop_back();
		}
	}
	cout<<cnt<<'\n';


}

