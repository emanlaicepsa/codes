#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll arr[500005];
ll sum[500005];
int main(){
	int n;
	cin>>n;
	int idx=0;
	int x=1;
	for(int i=0;i<n;i++){
		arr[idx]=x++;
		idx=(idx+n)%(2*n);
		arr[idx]=x++;
		idx+=1;
		idx%=(2*n);
	}
	for(int i=0;i<n;i++){
		arr[i+2*n]=arr[i];
	}	 
	/*for(int i=0;i<3*n;i++){
		cout<<arr[i]<<" ";
	}*/
	sum[0]=arr[0];
	for(int i=1;i<3*n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	ll ans1=sum[n-1];
	ll ans2=sum[n]-sum[0];
	//cout<<ans1<<" "<<ans2<<endl;
	bool can=1;
	for(int i=0;i<2*n;i++){
		if(sum[i+n]-sum[i]!=ans1&&sum[i+n]-sum[i]!=ans2){
			can=0;
			break;
		}
	}
	if(can){
		cout<<"YES"<<endl;
		for(int i=0;i<2*n;i++){
			cout<<arr[i]<<" ";
		}
	}
	else cout<<"NO"<<endl;
}

