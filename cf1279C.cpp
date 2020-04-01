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
ll arr[100005];
ll pos[100005];
bool used[100005];

int main(){
	IOS;
	int t,n,m,ta;
	cin>>t;
	while(t--){
		reset(pos,0);
		reset(used,0);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=m;i++){
			cin>>ta;
			pos[ta]=i;
		}
		for(int i=1;i<=n;i++){
			arr[i]=pos[arr[i]];
		//	cout<<arr[i]<<" ";
			
		}
	//	cout<<'\n';
		ll ncnt=0,nnum=1,ans=0;
		for(int i=1;i<=n;i++){
			ncnt++;
			if(arr[i]==0)continue;
			if(!used[arr[i]] && arr[i]!=nnum){
				used[arr[i]]=1;
				ans+=1;
			}
			else{
				//cout<<arr[i]<<" "<<ncnt<<'\n';
				ans+=2*ncnt-1;
				ncnt--;
				nnum++;
				while(nnum<=m&&used[nnum]){
					ncnt--;
					nnum++;
				}
			}
			if(nnum>m)break;
		}
		cout<<ans<<'\n';
	}



}

