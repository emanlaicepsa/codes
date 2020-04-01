#include<iostream>
#include<vector>
#include<memory.h>
#define ll long long
using namespace std;
ll const mod=100000007;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
    ll x,y;
    cin>>x>>y;
    vector<ll> X;
    vector<ll> Y;
    ll k;
    for(int i=0;i<x;i++){
        cin>>k;
        X.emplace_back(k%mod);
    }    
    for(int i=0;i<y;i++){
        cin>>k;
        Y.emplace_back(k%mod);
    }
    ll ans=1,p=1;
    for(int i=0;i<X.size();i++){
        p*=X[i];
        p%=mod;
    }
    for(int i=0;i<y;i++){
        ans*=p;
        ans%=mod;
    }
    p=1;
    for(int i=0;i<Y.size();i++){
        p*=Y[i];
        p%=mod;
    }
    for(int i=0;i<x;i++){
        ans*=p;
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}
