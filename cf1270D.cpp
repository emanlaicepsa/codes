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
int side[505];
int fq,sq,fa,sa,ca,cb,ta,tb;
int main(){
	int n,k;
	cin>>n>>k;
	if(k==1){
		cout<<1<<'\n';
		return 0;
	}
	//first
	cout<<"? ";
	for(int i=1;i<k;i++){
		cout<<i<<" ";
	}
	cout<<k<<endl;
	cin>>fq>>fa;
	if(fq==k)ca=k-1;
	else ca=k;
	side[ca]=1;
	
	//second
	cout<<"? ";
	for(int i=1;i<=k;i++){
		if(i==ca)continue;
		cout<<i<<" ";
	}
	cout<<k+1<<endl;
	cin>>sq>>sa;
	if(sq==fq){
		side[k+1]=1;
	}
	else side[k+1]=2;
	
	for(int i=1;i<=k;i++){
		if(i==fq||i==ca)continue;
		cout<<"? ";
		for(int j=1;j<=k;j++){
			if(j==i)continue;
			cout<<j<<" ";
		}
		cout<<k+1<<endl;
		cin>>ta>>tb;
		if(ta==sq)side[i]=side[ca];
		else side[i]=3-side[ca];
	}
	
	for(int i=k+2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j==ca)continue;
			cout<<j<<" ";
		}
		cout<<i<<endl;
		cin>>ta>>tb;
		if(ta==fq)side[i]=side[ca];
		else side[i]=3-side[ca];
	}
	for(int i=1;i<=n;i++){
		cout<<side[i]<<'\n';
	}
}

