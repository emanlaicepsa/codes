#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
double lge[50005];
double arr[50005];
int kase=0;
int main(){
	int t;
	cin>>t;
	for(int i=1;i<50005;i++){
		lge[i]=log(2)*i;
	}
	
	while(t--){
		double ans=0;
		int n;
		cin>>n;
		
		double l=1.0;
		double r=(n-1)*1.0;
		
		double temp=0;
		
		
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]==0)continue;
			else if(arr[i]>0){
				double ex=log(arr[i])+temp-lge[n-1];
				ans+=exp(ex);
			}
			else{
				double ex=log(-arr[i])+temp-lge[n-1];
				ans-=exp(ex);
			}
			temp=temp+log(r)-log(l);
			r-=1.0;
			l+=1.0; 
		}
		
		cout<<"Case #"<<++kase<<": ";
		cout<<fixed<<setprecision(3)<<ans<<'\n';
	}
	

	



}

