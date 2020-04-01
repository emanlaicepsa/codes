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
bool has[30];
bool exi[30];
int num[100005];
int arr[100005];
int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	bool ok = 1;
	for(int i=1;i<n;i++){
		int t = i;
		if(s[t] < s[t-1]){
			num[i] = 1;
			arr[i] = 1; 
			while(t && s[t] < s[t-1]){
				if(arr[t-1] == 1){
					ok = 0;
					break;
				}
				swap(s[t],s[t-1]);
				swap(arr[t],arr[t-1]);
				t--;
			}	
		}
		if(!ok)break;
	}
	if(!ok)cout<<"NO"<<'\n';
	else{
		cout<<"YES\n";
		for(int i=0;i<n;i++){
			cout<<num[i];
		}
		cout<<'\n';
	}


}

