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
int arr[500005];
int pos[500005];
set<int> s;
int main(){
	IOS;
	int n,q,a,b,c;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		pos[i] = arr[i] = i;
	}
	while(q--){
		cin>>a>>b>>c;
		if(a==1){
			if(b==c)continue;
			if(b != arr[b]){
				s.erase(b);
			}
			if(c != arr[c]){
				s.erase(c);
			}
			swap(arr[b] , arr[c]);
			swap(pos[arr[c]] , pos[arr[b]]);
			if(b != arr[b]){
				s.insert(b);
			}
			if(c != arr[c]){
				s.insert(c);
			}
		}
		else{
			int cnt = 0;
			while(1){
				auto it = s.lower_bound(b);
				if(it == s.end())break;
				int p = *it;
				if(p > c)break;
				
				int x = pos[p],y = arr[p];
				s.erase(x);
				s.erase(p);
				
				swap(arr[p],arr[x]);
				pos[y] = x;
				pos[p] = p;
				if(x!=y){
					s.insert(x);
				}
				cnt++;
			}
			cout<<cnt<<'\n';
		}
		/*for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<'\n';
		for(int i=1;i<=n;i++){
			cout<<pos[i]<<" ";
		}
		cout<<'\n';*/
	} 


}

