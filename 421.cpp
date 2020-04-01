#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll tree[50000000]={0};
ll findmax(int a,int b,int left,int right,int index){
	if(left>=a&&right<=b)return tree[index];
	if(a>right||b<left)return 0;
	return max(findmax(a,b,left,(left+right)/2,index*2),findmax(a,b,(left+right)/2+1,right,index*2+1));
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,Q;
	cin>>N>>Q;
	int k=1;
	while(k<=N)k*=2;
	int go=k;
	for(int x=0;x<N;x++){
		cin>>tree[k+x];
	}
	while(k>=2){
		k/=2;
		for(int x=k;x<k*2;x++){
			tree[x]=max(tree[x*2],tree[x*2+1]);
		}
	}
	int a,b;
	while(Q--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		ll ans=findmax(a,b,1,go,1);
		cout<<ans<<endl;
	}
	







}

