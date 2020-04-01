#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[400005];
int main(){
	//IOS
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		reset(arr,0);
		rep1(i,n)cin>>arr[i];
		int cnt=n/2;
		int idx=1;
		while(cnt>=1&&arr[cnt]==arr[cnt+1])cnt--;
		if(cnt<5){
			cout<<"0 0 0"<<'\n';
		}
		else{
			while(idx<=cnt&&arr[idx]==arr[idx+1])idx++;
			int g=idx++;
			while(idx-g<=g)idx++;
			while(idx<=cnt&&arr[idx]==arr[idx+1])idx++;
			int s=idx-g;
			int b=cnt-idx;
			
			if(g>=s||g>=b)cout<<"0 0 0"<<'\n';
			else  cout<<g<<" "<<s<<" "<<b<<'\n';
		}
	}



}

