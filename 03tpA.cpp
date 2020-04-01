#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define forn for(int i=0;i<n;i++)
#define int ll
using namespace std;
using ll= long long;
ll arr[200005];
ll tree[1000000];
ll tag[1000000];
void build(int l,int r,int index){
	if(l==r)tree[index]=arr[l];
	else {
		int mid=(l+r)>>1;
		build(l,mid,index<<1);
		build(mid+1,r,index<<1|1);
		tree[index]=tree[index<<1]+tree[index<<1|1];
	}
}
void add(int l,int r,ll val,int il,int ir,int index){
	if(il>r||ir<l)return;
	
	if(il>=l&&ir<=r){
		tag[index]+=val;
		tree[index]+=val*(ir-il+1);
		//cout<<tag[index]<<endl;
		//cout<<il<<" "<<ir<<" "<<tag[index]<<'\n';
	}
	else{
		int mid=(il+ir)>>1;
		tag[index<<1]+=tag[index];
		tree[index<<1]+=tag[index]*(mid-il+1);
		tag[index<<1|1]+=tag[index];
		tree[index<<1|1]+=tag[index]*(ir-mid);
		tag[index]=0;
		add(l,r,val,il,mid,index<<1);
		add(l,r,val,mid+1,ir,index<<1|1);
		tree[index]=tree[index<<1]+tree[index<<1|1];
	}
//	cout<<tree[index]<<" "<<il<<" "<<ir<<endl; 
}
ll query(int l,int r,int il,int ir,int index){
//	cout<<tag[index]<<'\n';
	if(il>r||ir<l)return 0;
	
	
	if(il>=l&&ir<=r){
	//	cout<<il<<" "<<ir<<" "<<tree[index]<<'\n';
		return tree[index];
	}
	
	int mid=(il+ir)>>1;
	tag[index<<1]+=tag[index];
	tree[index<<1]+=tag[index]*(mid-il+1);
	tag[index<<1|1]+=tag[index];
	tree[index<<1|1]+=tag[index]*(ir-mid);
	tag[index]=0;
	
	return query(l,r,il,mid,index<<1)+query(l,r,mid+1,ir,index<<1|1);
	
}


signed main(){
	IOS
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(0,n-1,1);
	int q;
	cin>>q;
	int a,b,c,d;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			cout<<query(b,c-1,0,n-1,1)<<'\n';
		}
		if(a==0){
			cin>>b>>c>>d;
			add(b,c-1,d,0,n-1,1);	
		}
	}
	
}

