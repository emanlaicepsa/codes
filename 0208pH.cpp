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
int arr1[100005];
int arr2[100005];
int main(){
	string a,b;
	cin>>a>>b;
	int idx = 0;
	int n = b.size();
	int m = a.size();
	ll mm = 0;
	int s1 = -1 ,s2 = -1;
	for(int i=0;i<n;i++){
		while(idx < m && a[idx] != b[i])idx++;
		arr1[i] = idx;
		if(idx<m && i+1 > mm){
			s1 = i;
			s2 = n;
			mm = i+1;
		}
		idx++;
	}
	//cout<<mm<<'\n';
	idx = m-1;
	for(int i = n-1;i>=0;i--){
		while(idx >= 0 && a[idx] != b[i]) idx--;
		arr2[i] = max(idx,-1);
		if(idx>-1 && n-i > mm){
			mm = n-i;
			s1 = -1;
			s2 = i;
		}
		idx--;
	}
	//cout<<mm<<'\n';
	idx = 0;
	for(int i=0;i<n;i++){
		if(idx <= i )idx = i+1;
		while(idx<n&&arr2[idx] <= arr1[i]) idx ++;
		if(idx<n && arr1[i] >=0 && arr2[idx] <m && n - (idx - i) + 1 > mm){
			mm = n - (idx - i) + 1;
			s1 = i;
			s2 = idx;
		}
	}
	//cout<<mm<<'\n';
	if(mm == 0)cout<<"-\n";
	else{
		for(int i=0;i<=s1;i++){
			cout<<b[i];
		}
		for(int i=s2;i<n;i++){
			cout<<b[i];
		}
		cout<<'\n';
	}


}

