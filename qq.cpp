#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define lowbit(x) ((x) & -(x))
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define YEE ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define PB push_back
#define maxn 1005
using namespace std;
typedef long long loli;
typedef pair<int, int> pii;
typedef pair<loli, loli> pll;
 
const loli mod = 998244353LL;
 
loli power(loli a, loli n) {
    loli ret = 1;
    while(n) {
        if(n & 1) {
            ret = ret * a % mod;
        }
        n >>= 1;
        a = a * a % mod;
    }
    return ret;
}
 
loli arr[maxn], pre[maxn], inv[maxn], dp[maxn] = {};
int n;
 
loli C(int a, int b) {
    return (pre[a] * inv[b] % mod) * inv[a - b] % mod;
}
 
int main() {
    pre[0] = 1;
    for(int i = 0; i < maxn; i++) {
        if(i) pre[i] = pre[i - 1] * i % mod;
        inv[i] = power(pre[i], mod - 2);
    }
    YEE;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = n; i > 0; i--) {
        if(arr[i] > 0 && n - i >= arr[i]) {
            // C(n - i, arr[i]);
            dp[i] = (dp[i] + C(n - i, arr[i])) % mod;
            for(int j = i + arr[i] + 1; j <= n; j++) {
                dp[i] += C(j - i - 1, arr[i]) * dp[j] % mod;
                if(dp[i] >= mod) dp[i] -= mod;
            }
        }
        //printf("%lld\n", dp[i]);
    }
    loli ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[i]) % mod;
    cout << ans << '\n';
    return 0;
}

