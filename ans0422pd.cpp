#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define ff first
#define ss second
#define pb push_back
#define PII pair<ll,ll>
#define mset(A) memset(A,0,sizeof(A))
#define fio ios_base::sync_with_stdio (false); cin.tie (NULL); cout.tie(NULL)
#define inout freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout)
using namespace std;
const ll inf = 8e18;
const ll mod = 1e9 + 7;
const ll ze = 0;

int main()
{
	fio;
	ll n,x;

	cin >> n >> x;
	ll a[n+1];
    ll dp[n+1][4];
    mset(dp);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n; i++)
	{
		dp[i][0] = max (dp[i][0], max (ze, dp[i - 1][0] + a[i]));
		dp[i][1] = max (dp[i][1], max (ze, dp[i - 1][0] + x * a[i]));
		dp[i][1] = max (dp[i][1], max (ze, dp[i - 1][1] + x * a[i]));
		dp[i][2] = max (dp[i][2], max (ze, dp[i - 1][1] + a[i]));
		dp[i][2] = max (dp[i][2], max (ze, dp[i - 1][0] + a[i]));
		dp[i][2] = max (dp[i][2], max (ze, dp[i - 1][2] + a[i]));
	}
	ll ans = -inf;
	for (ll i = 1; i <= n; i++)
	{
		ans = max (ans, dp[i][0]);
		ans = max (ans, dp[i][1]);
		ans = max (ans, dp[i][2]);
	}
	cout << ans;
	return 0;
}
