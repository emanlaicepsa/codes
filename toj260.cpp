#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[23010];
int nowans,n,q,nnum;
set<int> s;
unordered_map<int,int> m;
struct qus{
	int s;
	int e;
	int n;
};
int ans[200005];
vector<qus> queries;
int sqr;
bool cmp(qus &a,qus &b){
	return (a.s/sqr)==(b.s/sqr)?a.e<b.e:(a.s/sqr)<(b.s/sqr);
}
int bit[23010];

int qu(int p){
	//cout<<p<<" "<<5<<'\n';
	int ans=0;
	while(p){
		ans+=bit[p];
		p-=p&-p;
	}
	return ans;
}

void ad(int p,int v){
	//cout<<p<<" "<<v<<endl;
	while(p<=n){
		bit[p]+=v;
		//cout<<p<<" "<<bit[p]<<'\n';
		p+=p&-p;
	}
}

inline void addr(int &r){
	r++;
	//cout<<r<<'\n';
	nowans+=nnum-qu(arr[r]);
	//cout<<nowans<<' '<<1<<'\n';
	ad(arr[r],1);
	nnum++;
}

inline void addl(int &l){
	l--;
	nowans+=qu(arr[l]-1);
	//cout<<nowans<<' '<<2<<'\n';
	ad(arr[l],1);
	nnum++;
}

inline void subr(int &r){
	nowans-=nnum-qu(arr[r]);
	//cout<<nowans<<' '<<3<<'\n';
	ad(arr[r],-1);
	r--;
	nnum--;
}

inline void subl(int &l){
	nowans-=qu(arr[l]-1);
	//cout<<nowans<<' '<<4<<'\n';
	ad(arr[l],-1);
	l++;
	nnum--;
}

int main(){
	//IOS
	cin>>n>>q;
	//discretization
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	int k=0;
	for(auto i=s.begin();i!=s.end();i++){
		m[*i]=++k;
	}
	for(int i=1;i<=n;i++){
		arr[i]=m[arr[i]];
		//cout<<arr[i]<<'\n';
	}
	//
	int t1,t2;
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		if(t1>t2)swap(t1,t2);
		queries.push_back({t1,t2,i});
	}
	sqr=sqrt(n);
	sort(queries.begin(),queries.end(),cmp);
	int l=1,r=1;
	ad(arr[1],1);
	nnum=1;
	for(auto i:queries){
		//cout<<i.s<<" "<<i.e<<" "<<i.n<<'\n';
		while(r<i.e)addr(r);
		while(r>i.e)subr(r);
		while(l<i.s)subl(l);
		while(l>i.s)addl(l);
		/*for(int i=1;i<=n;i++){
			cout<<bit[i]<<endl;
		}*/
		ans[i.n]=nowans;
		//cout<<nowans<<'\n';
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]+1<<'\n';
	}

}

