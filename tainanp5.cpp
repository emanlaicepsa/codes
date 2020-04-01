#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
bool used[100005];

int main(){
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	int g1=-1,g2=n;
	int cnt=0;
	int left=n;
	while(left){
		int c1=a,c2=b;
		while(c1--){
			++g1; g1%=n;
			while(used[g1]){g1=(g1+1)%n;}
		}
		while(c2--){
			--g2; g2=(g2+n)%n;
			while(used[g2]){g2=(g2-1+n)%n;}
		}
		if(left!=n)cout<<',';
		if(g1==g2){
			used[g1]=1;
			cout<<g1+1;
			left--;
		}
		else{
			used[g1]=1;
			used[g2]=1;
			cout<<g1+1<<" "<<g2+1;
			left-=2;
		}
	
	}	
	cout<<'\n';

}

