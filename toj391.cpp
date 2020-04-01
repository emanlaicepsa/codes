#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct tree{
	int maxx;
	int val;
}t[800005];
int arr[200005];

void build(int l,int r,int idx){
	if(l==r){
		t[idx].maxx=t[idx].val=arr[l];
		return;
	}	
	int m=(l+r)>>1;
	build(l,m,idx<<1);
	build(m+1,r,idx<<1|1);
	t[idx].maxx=max(t[idx<<1].maxx,t[idx<<1|1].maxx);
}

void add(int l,int r,int num,int aim,int idx){
	if(l==r){
		t[idx].val+=num;
		t[idx].maxx=t[idx].val; 
		//cout<<idx<<'\n';
		return;
	}
	int m=(l+r)>>1;
	if(aim<=m){
		add(l,m,num,aim,idx<<1);
	}
	else{
		add(m+1,r,num,aim,idx<<1|1);
	}
	t[idx].maxx=max(t[idx<<1].maxx,t[idx<<1|1].maxx);
//	cout<<idx<<" "<<t[idx].maxx<<'\n';
}

void pack(int l,int r,int ql,int qr,int mod,int idx){
	if(l>qr||r<ql||t[idx].maxx<mod)return;
	if(l==r){
		t[idx].val%=mod;
		t[idx].maxx=t[idx].val;
		return;
	}
	int m=(l+r)>>1;
	pack(l,m,ql,qr,mod,idx<<1);
	pack(m+1,r,ql,qr,mod,idx<<1|1);
	t[idx].maxx=max(t[idx<<1].maxx,t[idx<<1|1].maxx);
}

int main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(0,n-1,1);
	int q,tt,t1,t2,t3;
	cin>>q;
	while(q--){
		cin>>tt;
		if(tt==1){
			cin>>t1>>t2;
			add(0,n-1,t1,t2,1);
		}
		if(tt==2){
			cin>>t1>>t2>>t3;
			pack(0,n-1,t1,t2,t3,1);
		}
		if(tt==3){
			cout<<t[1].maxx<<'\n';
		}
	} 
}

