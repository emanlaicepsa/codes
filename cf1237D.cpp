#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
multiset<int,greater<int>> s; 
int arr[300005];
int ans[300005];
int main(){
	int n;
	cin>>n;
	auto iter=s.begin();
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]*=2;
		arr[n+i]=arr[2*n+i]=arr[i];
	}	
	int l=1,r=1;
	while(l<=n){
		while(s.empty()||((*s.begin())/2<=arr[r])){
			if(r==3*n&&l==1){
				for(int i=0;i<n;i++){
					cout<<-1<<" ";
				}
				cout<<'\n';
				return 0;
			}
			s.insert(arr[r]);
		//	cout<<l<<" "<<*s.begin()<<'\n';
			r++;
		}
		while(!s.empty()&&(*s.begin())/2>arr[r]){
			ans[l]=r-l;
			s.erase(s.find(arr[l]));
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<'\n';

}

