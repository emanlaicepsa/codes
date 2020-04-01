#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
vector<int> a;
vector<int> b;
map<int,int> m;
int main(){
	IOS
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		m[x]=i;
	}	
	while(k--){
		b.clear();
		for(int i=0;i<n;i++){
			cin>>x;
			b.push_back(m[x]);
		}
		/*for(int i=0;i<n;i++){
			cout<<b[i]<<" "<<endl;
		}*/
		int index=0;
		int arr[10005];
		arr[0]=b[0];
		for(int i=1;i<n;i++){
			if(b[i]>arr[index]){
				arr[++index]=b[i];
			}
			else{
				int x=lower_bound(arr,arr+index,b[i])-arr;
				arr[x]=b[i]; 
			}
		}
		
		
		cout<<index+1<<'\n';
	}
	



}

