#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define int long long
using namespace std;
int s[200005]={0};
main(){
	int n;
	cin>>n;
	int sum=0;
	int x;
	s[0]=0;
	for(int k=1;k<=n;k++){
		cin>>x;
		sum+=x;
		s[k]=sum;
	}
	int q;
	cin>>q;
	int a,b;
	while(q--){
		cin>>a>>b;
		if(a>b){
			swap(a,b);
		}
			cout<<s[b]-s[a-1]<<endl;
		
	}


}

