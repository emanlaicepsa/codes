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
pii arr[500005];
stack<int> s;
int pa[500005];
int r1[500005];
int r2[500005];
void merge(int a,int b){
	int arr[4]={r1[a],r2[a],r1[b],r2[b]};
	sort(arr,arr+4);
	r2[a]=arr[3];
	r1[a]=arr[2];
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].fi>>arr[i].se;
	} 
	sort(arr+1,arr+n+1);
	/*for(int i=1;i<=n;i++){
		cout<<arr[i].fi<<" "<<arr[i].se<<'\n';
	}*/
	for(int i=1;i<=n;i++){
		r2[i]=arr[i].se;
		if(s.empty()){
			s.push(i);	
		}	
		else{
			if(arr[i].fi>r2[s.top()]){
				cout<<"NO\n";
				return 0;
			}
			while(!s.empty()&&( (arr[i].se>r1[s.top()] &&arr[i].fi<r1[s.top()])||(arr[i].fi<r2[s.top()]&&arr[i].se>r2[s.top()]))){
				//cout<<i<<" "<<r1[s.top()]<<" "<<r2[s.top()]<<'\n';
				if(arr[i].fi<r1[s.top()]&&arr[i].se>r2[s.top()]){
					cout<<"NO\n";
					return 0;
				}
				merge(i,s.top());
				s.pop();
			}s.push(i);
			//cout<<i<<" "<<r1[s.top()]<<" "<<r2[s.top()]<<'\n';
			
		}
	}
	cout<<"YES\n";


}

