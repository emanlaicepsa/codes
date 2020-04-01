#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int arr[1000005];
bool isupper(char x){
	return (x<='Z'&&x>='A');
}
int main(){
	int n,k,l;
	char t;
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(isupper(t))arr[i]=1;
		else arr[i]=0;
	}
	
	for(int i=1;i<=n;i++)cout<<arr[i]<<'\n';



}

