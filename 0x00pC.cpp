#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define all(n) (n).begin(),(n).end()
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<'\n';

using namespace std;
const ll mod = 1000000007;
namespace Gen {
    uint32_t S0, S1, S2, S3, mx;
 
    void Init() {
        cin >> S0 >> S1 >> S2 >> S3;
        if (S0 == 1) mx = 31;
        else if (S0 == 2) mx = (1 << 20) - 1;
        else mx = ((uint64_t)1 << 32) - 1;
    }
 
    inline uint32_t rot(const uint32_t x, int k) {
        return (x << k) | (x >> (32 - k));
    }
 
    uint32_t Rand() {
        uint32_t s0 = S0, s1 = S1, res = s0 + s1;
        s1 ^= s0;
        s0 = rot(s0, 24) ^ s1 ^ (s1 << 16);
        s1 = rot(s1, 17);
        S0 = s1, S1 = S2, S2 = S3, S3 = s0;
        return res & mx;
    }
}
 
ll t,x0,x1,a,b;
ll f[20000005];
 
struct mat{
    ll a[2][2];
    mat(){
        memset(a,0,sizeof(a));
    }
    mat operator*(const mat &b ){
        mat c;
        for(int i=0;i<2;i++){
            for(int k=0;k<2;k++){
                for(int j=0;j<2;j++){
                    c.a[i][j] += a[i][k] * b.a[k][j];
                    c.a[i][j] %= mod;
                }
            }
        }
        return c;
    }
};

mat trans[35];
void init(){
	trans[0].a[0][0] = b;
    trans[0].a[1][0] = a;
    trans[0].a[0][1] = 1;
    trans[0].a[1][1] = 0;
    for(int i=1;i<35;i++){
    	trans[i] = trans[i-1] * trans[i-1];
	}
}

ll fib(ll n){
	mat ori;
    ori.a[0][0] = x1;
    ori.a[0][1] = x0;
    n--;
    int cnt = 0;
    while(n){
        if(n&1) {
            mat c;
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    c.a[0][j] += ori.a[0][k] * trans[cnt].a[k][j];
                    c.a[0][j] %= mod;
                }
            }
            ori = c;
        }
        n>>=1;
        cnt++;
		//cout<<ori.a[0][0]<<'\n';
    }
    
    return ori.a[0][0];
}
 
int main(){
    IOS;
    cin>>t>>x0>>x1>>a>>b;
    Gen::Init();
    f[0] = x0;
    f[1] = x1;
    for(int i=2;i<=20000000;i++){
        f[i] = (a*f[i-2] + b*f[i-1]) %mod;
    }
    ll ans = 0;
    init();
    while(t--){
        ll now = Gen::Rand();
        if(now <= 20000000) ans ^= f[now];
        else ans ^= fib(now);
    }
    cout<<ans<<'\n';
}
