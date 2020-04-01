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
int a[10];
int cnt[10];
int main(){
	int n;
	cin>>n;
	int mx = 1e9 , mnum;
	for(int i=1;i<=9;i++){
		cin>>a[i];
		if(a[i] <= mx) mx =a[i] ,mnum = i;
	}
	int ans = n/mx , le = n%mx;
	if(ans == 0){
		cout<<-1<<'\n';
		return 0;
	}
	cnt[mnum] = ans;
	for(int i=1;i<=9;i++){
		a[i] -= mx;
		//cout<<a[i]<<'\n';
	}
	
	for(int i=9;i>mnum;i--){
		//cout<<a[i]<<'\n';
		cnt[i] += le/a[i];
		le %= a[i];
		cnt[mnum] -= cnt[i];
	}
	for(int i=9;i>=1;i--){
		for(int j=0;j<cnt[i];j++){
			cout<<i;
		}
	}
	cout<<'\n';



}

