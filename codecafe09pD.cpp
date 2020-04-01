#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<ll> anti;
bool na[10000005];
int m[10000005];
int cnt[10000005];
vector<int> tp;
bool cmp(int &a,int &b){
	return cnt[a]==cnt[b]?a>b:cnt[a]>cnt[b];
}

int main(){
	
	for(ll i=3;i<=10000005;i++){
		if(!na[i]){
			m[i]=i;
			anti.emplace_back(i);
		}
		for(ll &j:anti){
			if(i*j>10000005)break;
			na[i*j]=1;
			m[i*j]=j;
			if(i%j==0)break;
		}
	}	
	for(int i=3;i<=10000005;i++){
		//cout<<m[i]<<'\n';
		int j=i;
		while(j>1){
			j/=m[j];
			cnt[i]++;
		}
	}
	
	int t,m,n;
	cin>>t>>m;
	while(t--){
		cin>>n;
		//cout<<n<<'\n';
		tp.clear();
		tp.resize(n);
		for(int i=0;i<n;i++)cin>>tp[i];
		sort(tp.begin(),tp.end(),cmp);
		for(int i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<tp[i];
		}
		cout<<'\n';
	}

}

