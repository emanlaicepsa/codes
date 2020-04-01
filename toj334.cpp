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
ll X1,Y1,X2,Y2;

ll power3[50],p2[50];
map<pair<ll,ll>,ll> m;

ll ans(ll X , ll Y , ll num = 39){
	if(!X||!Y) return 0;
    if(m[{X,Y}]) return m[{X,Y}];
    if(X>Y) swap(X,Y);
    if( X == p2[num] ) return power3[num] * (Y/p2[num]) + ans(X,Y%p2[num]);
    ll mid = p2[num-1];
    if(X>mid && Y>mid) return m[{X,Y}] = ans(mid,mid,num-1) + ans(X-mid,mid,num-1) + ans(mid,Y-mid,num-1);
    if(X>mid) return m[{X,Y}] = ans(mid,Y,num-1) + ans(X-mid,Y,num-1);
    if(Y>mid) return m[{X,Y}] = ans(X,mid,num-1) + ans(X,Y-mid,num-1);
    return m[{X,Y}] = ans(X,Y,num-1);
}


int main(){
    IOS;    
    power3[0] = p2[0] = 1;
    for(int i=1;i<=40;i++) power3[i] = power3[i-1]*3 , p2[i] = p2[i-1]<<1;
    cin>>X1>>Y1>>X2>>Y2;
    cout<< ans(X2,Y2) - ans(X1-1,Y2) - ans(X2,Y1-1) + ans(X1-1,Y1-1) <<'\n';
}
