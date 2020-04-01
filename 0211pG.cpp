#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
ll arr[1000005];
pii tr[2000005];
pii tr2[2000005];
int n;
pii q1(int l,int r){
	l+=n;
	r+=n;
	ll ans = 0;
	ll aid = 0;
	for(;l<r;l>>=1,r>>=1){
		if(l&1){
			if(tr[l].fi > ans){
				aid = tr[l].se;
				ans = tr[l].fi;
			}
			l++;
		}
		if(r&1){
			r--;
			if(tr[r].fi > ans){
				aid = tr[r].se;
				ans = tr[r].fi;
			}
		}
	}
	return {aid,ans};
}

pii q2(int l,int r){
	l+=n;
	r+=n;
	ll ans = 1e18;
	ll aid = 0;
	for(;l<r;l>>=1,r>>=1){
		if(l&1){
			if(tr2[l].fi < ans){
				aid = tr2[l].se;
				ans = tr2[l].fi;
			}
			l++;
		}
		if(r&1){
			r--;
			if(tr2[r].fi < ans){
				aid = tr2[r].se;
				ans = tr2[r].fi;
			}
		}
	}
	return {aid,ans};
}

ll solve(ll l ,ll r){
	//cout<<l<<" "<<r<<'\n';
	if(l>r)return 0;
	pii mx = q1(l,r+1);
	ll mxid = mx.fi, mxn = mx.se;
	ll ans = mxn * (mxid - l + 1) * (r - mxid + 1);
	//cout<<mxid<<" "<<l<<" "<<r<<" "<<ans<<'\n';
	return ans + solve(l,mxid-1) + solve(mxid+1,r);
}

ll solve2(ll l,ll r){
	if(l>r)return 0;
	pii mi = q2(l,r+1);
	ll miid = mi.fi, mii = mi.se;
	ll ans = mii * (miid-l+1) * (r-miid+1);
	return ans + solve2(l,miid-1) + solve2(miid+1,r);
}
int main(){
	IOS;
	
	cin>>n;
	memset(tr2,0x3f,sizeof(tr2));
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		tr[i+n].fi = tr2[i+n].fi = arr[i];
		tr[i+n].se = tr2[i+n].se = i;
 	}	
	for(int i=n;i>=1;i--){
		tr[i].fi = max(tr[i<<1].fi,tr[i<<1|1].fi);
		tr2[i].fi = min(tr2[i<<1].fi,tr2[i<<1|1].fi);
		if(tr[i].fi == tr[i<<1].fi) tr[i].se = tr[i<<1].se;
		else tr[i].se = tr[i<<1|1].se;
		if(tr2[i].fi == tr2[i<<1].fi) tr2[i].se =  tr2[i<<1].se;
		else tr2[i].se =  tr2[i<<1|1].se;
 	}
	cout<<solve(1,n) - solve2(1,n) <<'\n';
}

