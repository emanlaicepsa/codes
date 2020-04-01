#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define all(n) (n).begin(),(n).end()
#define reset(n,k) memset((n),(k),sizeof(n));
#define pb push_back
using namespace std;
int to[300005][65];
int arr[300005];
int ans[300005];
ll qq[63];
vector<int> go;
ll n,k;

int main() {
    IOS;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    for(int i=1;i<=n;i++){
        cin>>to[i][0];
    }

    for(int j=1;j<=62;j++){
        for(int i=1;i<=n;i++){
            to[i][j] = to[to[i][j-1]][j-1];
        }
    }
    
    cin>>k;
    int cur = 0;
    while(k){
    	if(k&1) go.pb(cur);
    	cur++;
    	k>>=1;
	}
    qq[0] = 1;
    for(int i=1;i<=62;i++){
    	qq[i] = qq[i-1] <<1;
	}
    for(int i=1;i<=n;i++){
        ll now = i;
        for(auto &x:go) now = to[now][x];	
        ans[now] = arr[i];
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" \n"[i==n];
    }
    
    return 0;
}
