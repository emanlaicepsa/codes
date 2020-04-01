#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct ice{
	int w;
	int s;
	int e;
};
vector<ice> v;

bool used[800005];
int ans[200005];
void modify(int l,int r,int ql,int qr,int val,int idx){
	if(used[idx])return;
	if(l==r){
		used[idx]=1;
		ans[l]=val;
		return;
	}
	if(l>=ql&&r<=qr){
		used[idx]=1;
		for(int i=l;i<=r;i++)if(!ans[i])ans[i]=val;
		return;
	}
	int m=(l+r)>>1;
	if(ql<=m){
		modify(l,m,ql,qr,val,idx<<1);
	}
	if(qr>m){
		modify(m+1,r,ql,qr,val,idx<<1|1);
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	int t1,t2,t3;
	for(int i=0;i<n;i++){
		cin>>t1>>t2>>t3;
		v.push_back({t1,t2,t3});
	}
	sort(v.begin(),v.end(),[](ice &a,ice &b){
		return a.w>b.w;
	});
	for(auto &i:v){
	//	cout<<i.w<<'\n';
		modify(1,m,i.s,i.e,i.w,1);
	}
	for(int i=1;i<=m;i++){
		if(i>1)cout<<" ";
		cout<<ans[i];
	}
	cout<<'\n';
}

