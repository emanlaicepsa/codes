#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
struct node{
	int val,maxn,pri,siz;
	node *l,*r;
	node(int k){
		val=maxn=k;
		pri=rand();
		siz=1;
		l=r=nullptr;	
	}
	~node(){
		if(l)delete l;
		if(r)delete r;
	}
}*root;

inline void pull(node *&a){
	a->siz=1;
	a->maxn=a->val;
	if(a->l){
		a->siz+=a->l->siz;
		a->maxn=max(a->maxn,a->l->maxn);
	}
	if(a->r){
		a->siz+=a->r->siz;
		a->maxn=max(a->maxn,a->r->maxn);
	}
}

inline int findsiz(node *&a){
	return a?a->siz:0;
} 


node *merge(node *a,node *b){
	if(!a)return b;
	if(!b)return a;
	if(a->pri>b->pri){
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
	else{
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
}

void split(node *a,node *&b,node *&c,int k){
	if(!a){
		b=c=nullptr;
		return;
	}
	if(k<=findsiz(a->l)){
		c=a;
		split(a->l,b,c->l,k);
		pull(c);
	}
	else{
		b=a;
		split(a->r,b->r,c,k-findsiz(a->l)-1);
		pull(b);
	}
} 
void change(int x,int y){
	node *t1,*t2,*t3;
	split(root,t1,t2,x-1);
	split(t2,t2,t3,1);
	t2->maxn=t2->val=y;
	root=merge(t1,merge(t2,t3));
}
void ask(int x,int y){
	node *t1,*t2,*t3;
	split(root,t1,t2,x-1);
	split(t2,t2,t3,y-x+1);
	cout<<t2->maxn;
	root=merge(t1,merge(t2,t3));
}
void add(int x,int y){
	node *t1,*t2;
	split(root,t1,t2,x-1);
	root=merge(t1,merge(new node(y),t2));
}
void del(int x){
	node *t1,*t2,*t3;
	split(root,t1,t2,x-1);
	split(t2,t2,t3,1);
	delete t2;
	root=merge(t1,t3);
}

int main(){
	IOS
	int n,q;
	while(cin>>n>>q){
		delete root;
		root=nullptr;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			root=merge(root,new node(temp));
			//cout<<findsiz(root)<<endl;
		}
		int si=n;
		/*for(int i=1;i<=si;i++){
				ask(i,i);
				cout<<" ";
			}
		cout<<'\n';*/
		int ty,x,y;
		while(q--){
			cin>>ty;
			if(ty==1){
				cin>>x>>y;
				change(x,y);	
			}
			if(ty==2){
				cin>>x>>y;
				ask(x,y);
				cout<<'\n';
			}
			if(ty==3){
				cin>>x>>y;
				add(x,y);
				si++;
			}
			if(ty==4){
				cin>>x;
				del(x);
				si--;
			}
			/*for(int i=1;i<=si;i++){
				ask(i,i);
				cout<<" ";
			}
			cout<<'\n';*/
		}
	} 
}

