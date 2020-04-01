#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define rep(k,n) for(int k=0;k<(n);k++)
#define rep1(k,n) for(int k=1;k<=(n);k++)
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
#define vi vector<int>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[100005];
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a<=1&&b==0&&c==0&&d==0){
		cout<<"YES\n";
		cout<<0<<'\n';
		return 0;
	}
	if(a==0&&b==0&&c==0&&d==1){
		cout<<"YES\n";
		cout<<3<<'\n';
		return 0;
	}
	if(a==b+1&&c==0&&d==0){
		cout<<"YES\n";
		cout<<0<<" ";
		for(int i=0;i<b;i++){
			cout<<1<<" "<<0<<" \n"[i==b-1];
		}
		return 0;
	}
	if(d==c+1&&a==0&&b==0){
		cout<<"YES\n";
		cout<<3<<" ";
		for(int i=0;i<c;i++){
			cout<<2<<" "<<3<<" \n"[i==c-1];
		}
		return 0;
	}
	int n=a+b+c+d;
	if(a>b||d>c)cout<<"NO\n";
	else{
		b-=a;
		c-=d;
		int x=b-c;
		if(x>1||x<-1)cout<<"NO\n";
		else{
			cout<<"YES\n";
			int idx=1;
			int ridx=n;
			if(x==1){
				arr[1]=1;
				idx++;
				b--;
			}
			if(x==-1){
				arr[ridx]=2;
				ridx--;
				c--;
			}
			for(int i=0;i<a;i++){
				arr[idx++]=0;
				arr[idx++]=1;
			}
			
			for(int i=0;i<d;i++){
				arr[ridx--]=3;
				arr[ridx--]=2;
			}
			for(int i=0;i<b;i++){
				arr[idx++]=2;
				arr[idx++]=1;
			}
			rep1(i,n){
				cout<<arr[i]<<" \n"[i==n];
			}
		}
		
	}



}

