#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
//#define endl '\n'
using namespace std;
int num[2000010]={0};
int tree[8500000]={0};
/*void build(int left,int right,int index){
	if(left==right){
		tree[index]=num[left];
	}
	else{
		int mid=(left+right)/2;
		build(left,mid,index*2);
		build(mid+1,right,index*2+1);
		tree[index]=max(tree[index*2],tree[index*2+1]);
	}
}*/
int query(int left,int right,int finda,int findb, int index){
	//cout<<left<<" "<<right<<" "<<index<<endl;
	if(left>findb||right<finda){
		//cout<<0<<endl;
		return 0;
	}
	if(finda<=left&&findb>=right){
		//cout<<1<<endl;
		return tree[index];
	}
	int mid=(left+right)/2;
	return max(query(left,mid,finda,findb,index*2),query(mid+1,right,finda,findb,index*2+1));
}
/*void change(int left,int right,int aim,int val,int index){
	if(left==right){
		if(left!=aim){
			cout<<"ERR"<<endl;
		}
		tree[index]=val;
		index/=2;
		while(index>=1&&tree[index]!=max(tree[index*2],tree[index*2+1])){
			tree[index]=max(tree[index*2],tree[index*2+1]);
			index/=2;
		}
	}
	else{
		int mid=(left+right)/2;
		if(mid>=aim){
			change(left,mid,aim,val,index*2);
		}
		if(mid<aim){
			change(mid+1,right,aim,val,index*2+1);
		}
	}
	
}*/
int main(){
	IOS;
	int n,t;
	char A;
	int B,C;
	cin>>n;
	int tsize=1;
	while(tsize<=n) {
		tsize<<=1;
		//cout<<tsize;
	}
	for(int x=0;x<n;x++){
		cin>>tree[x+tsize];
	}
	int temp=tsize;
	while(temp>=2){
		temp/=2;
		for(int X=temp;X<temp*2;X++){
			tree[X]=max(tree[X*2],tree[X*2+1]);
		}
	}
	//build(0,n-1,1);
	/*for(int x=1;x<16;x++){
		cout<<tree[x]<<" ";
		if(x==1||x==3||x==7||x==15)cout<<endl;
	}*/
	cin>>t;
	while(t--){
		cin>>A>>B>>C;
		if(A=='Q'){
			if(B>C)swap(B,C);
			int Y=1;
			while(Y<n)Y<<=1;
			cout<<query(0,Y-1,B-1,C-1,1)/2<<endl;	
		}
		if(A=='C'){
			tree[tsize+B-1]=C;
			int index=tsize+B-1;
			index/=2;
			while(index>=1&&tree[index]!=max(tree[index*2],tree[index*2+1])){
			tree[index]=max(tree[index*2],tree[index*2+1]);
			index/=2;
			}
			for(int x=1;x<32;x++){
				cout<<tree[x]<<" ";
				if(x==1||x==3||x==7||x==15||x==31)cout<<endl;
			}
		}
	}

}

