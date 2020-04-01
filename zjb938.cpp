#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct node{
	int val;
	node *next;
};
void add(node *&ptr,int i){
	node *newnode= new node;
	newnode->val =i;
	newnode->next = NULL;
	ptr->next=newnode;
	ptr=ptr->next;
}

int del(int i,node* head){
	node *x=head;
	x->val =0;
	while(x->val<i&&x->next !=NULL){
		x=x->next ;
	}
	if(x->val!=i)return -1;
	else if(x->next==nullptr )return -1;
	else{
		node *temp=x->next ;
		x->next =temp->next ;
		x=x->next;
		return temp->val;
	}
}

int deleted[1000005];

int main(){
	IOS;
	node *head=new node;
	head->val =0;
	node *ptr=head;
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)add(ptr,i);
	
	int q;
	for(int i=0;i<m;i++){
		cin>>q;
		if(deleted[q])cout<<"0u0 ...... ?"<<endl;
		else {
			int x=del(q,head);
			if(x==-1)cout<<"0u0 ...... ?"<<endl;
			else {
				cout<<x<<endl;
				deleted[x]=true;
			}
		}
	}


}

