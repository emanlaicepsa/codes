#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
using pii=pair<int,int>;
const int maxn=200005;
vector<int> con[maxn];
int top[maxn];
int cnt[maxn];
int maxson[maxn];
int tree[maxn];
int pa[maxn];
int segment_tree[maxn*4];
int pos[maxn];
int depth[maxn];
int arr[maxn];
int stamp;
int N;
inline void clean(){
	stamp=0;
	for(int i=0;i<200005;i++)con[i].clear();
	memset(top,0,sizeof(top));
	memset(cnt,0,sizeof(cnt));
	memset(maxson,0,sizeof(maxson));
	memset(tree,0,sizeof(tree));
	memset(pa,0,sizeof(pa));
	memset(pos,0,sizeof(pos));
	memset(depth,0,sizeof(depth));
	memset(segment_tree,0,sizeof(segment_tree));
	memset(arr,-0x3f3f3f,sizeof(arr));
}

void dfs(int nd,int p,int d){
	cnt[nd]=1;
	maxson[nd]=-1;
	pa[nd]=p;
	depth[nd]=d;
	for(int i:con[nd]){
		if(i==p)continue;
		dfs(i,nd,d+1);
		cnt[nd]+=cnt[i];
		if(maxson[nd]==-1||cnt[i]>cnt[maxson[nd]]){
			maxson[nd]=i;
		}
	}	
}

void decomp(int nd,int t){
	tree[++stamp]=nd;
	pos[nd]=stamp;
	top[nd]=t;
	if(maxson[nd]!=-1){
		decomp(maxson[nd],t);
	}
	for(int i:con[nd]){
		if(i==pa[nd]||i==maxson[nd])continue;
		decomp(i,i);
	}
}

inline void pull(int x){
	segment_tree[x]=max(segment_tree[x<<1],segment_tree[x<<1|1]);
}

void build(int l,int r,int index){
	if(l==r){
		segment_tree[index]=arr[tree[l]];
		return;
	} 
	int m=(l+r)/2;
	build(l,m,index<<1);
	build(m+1,r,index<<1|1);
	pull(index);
}

void change(int l,int r,int p,int v,int index){
	if(l>p||r<p)return;
	if(l==r&&l==p){
		segment_tree[index]=v;
		return;
	}
	int m=(l+r)/2;
	change(l,m,p,v,index<<1);
	change(m+1,r,p,v,index<<1|1);
	pull(index);
}

int query(int l,int r,int fl,int fr,int index){
	if(r<fl||l>fr)return -100000000;
	if(l>=fl&&r<=fr)return segment_tree[index];
	int m=(l+r)/2;
	return max(query(l,m,fl,fr,index<<1),query(m+1,r,fl,fr,index<<1|1));
}

int LCA(int x,int y){
	//cout<<x<<" "<<top[x]<<" "<<y<<" "<<top[y]<<'\n'; 
	int ans=-100000000;
	while(top[x]!=top[y]){
		if(depth[top[x]]<depth[top[y]])swap(x,y);
		ans=max(ans,query(1,2*N-1,pos[top[x]],pos[x],1));
		x=pa[top[x]];
	}
	if(depth[x]<depth[y])swap(x,y);
	ans=max(ans,query(1,2*N-1,pos[y],pos[x],1));
	return ans;
}


int main(){
	IOS 
	int T;
	cin>>T;
	while(T--){
		clean();
		cin>>N;
		int ai,bi,ci;
		for(int i=1;i<N;i++){
			cin>>ai>>bi>>ci;
			con[ai].emplace_back(i+N);
			con[bi].emplace_back(i+N);
			con[i+N].emplace_back(ai);
			con[i+N].emplace_back(bi);
			arr[i+N]=ci;
		}
		dfs(1,-1,0);
		decomp(1,1);
		build(1,2*N-1,1);
		//for(int i=1;i<=2*N-1;i++)cout<<tree[i]<<endl;
		string s;
		int t1,t2;
		while(cin>>s){
			if(s=="DONE")break;
			if(s=="CHANGE"){
				cin>>t1>>t2;
				int p=pos[N+t1];
				change(1,2*N-1,p,t2,1); 
			}
			if(s=="QUERY"){
				cin>>t1>>t2;
				cout<<LCA(t1,t2)<<'\n';			
			}
			//for(int i=N+1;i<=2*N-1;i++)cout<<query(1,2*N-1,pos[i],pos[i],1)<<endl;
		}
	} 
}

