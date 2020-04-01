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
bool neg[35];
int main(){
	ll m,n,x;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cout<<m<<endl;
		cin>>x;
		if(x==-1){
			neg[i] = 1;
		}
		else{
			if(x==0){
				return 0;
			}
		}
	}
	int l = 1 ,r = m;
	for(int i=0;i<30;i++){
		int mid = (l+r)>>1;
		cout<<mid<<endl;
		cin>>x;
		if(neg[i%n])x=-x;
		if(x==0){
			return 0;
		}
		else if(x==1){
			r = mid-1;
		}
		else {
			l = mid + 1;
		}
	}


}

