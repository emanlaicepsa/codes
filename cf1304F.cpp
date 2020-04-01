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
ll seg[40005];
ll tag[40005];
ll dp[55][20005];
ll arr[55][20005];
ll pre[55][20005];
ll n,m,k;
ll getsum(int x1,int y1,int x2,int y2){
	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<'\n';
	if(y2>m) y2 = m;
	if(x2>n) x2 = n; 
	//cout<<pre[x2][y2]<<" "<<pre[x1-1][y2]<<" "<<pre[x2][y1-1]<<" "<<pre[x1-1][x2-1]<<'\n';
	return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1]; 
} 

inline void push(int x){
	for(int i=__lg(x);i>=1;i--){
		ll tt = x>>i;
		tag[tt<<1] += tag[tt];
		tag[tt<<1|1] += tag[tt];
		seg[tt<<1] += tag[tt];
		seg[tt<<1|1] += tag[tt];
		tag[tt] = 0; 
	}
}

ll que(int l,int r){
	//cout<<l<<" "<<r<<'\n';
	ll ans = 0;
	r++;
	push(l+m);
	push(r+m);
	
	for(l+=m,r+=m;l<r;l>>=1,r>>=1){
		if(l&1){
			ans = max(ans,seg[l++]);
		}
		if(r&1){
			ans = max(ans,seg[--r]);
		}
	}
	//cout<<ans<<'\n';
	return ans;
}

inline void pull(int x){
	while(x>1){
		seg[x>>1] = max(seg[x],seg[x^1]) + tag[x>>1];
		x>>=1;
	}
}

void add(int l,int r,int val){
	//cout<<"$"<<l<<" "<<r<<" "<<val<<'\n';
	r++;
	int tl = l,tr = r;
	int x = 0;
	for(l+=m,r+=m;l<r;l>>=1,r>>=1,x++){
		if(l&1){
			tag[l]+=val;
			seg[l]+=val;
			l++;
		}
		if(r&1){
			r--;
			tag[r]+=val;
			seg[r]+=val; 
		}
	}
	pull(tl+m);
	pull(tr+m);
}

int main(){
	//IOS;
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + arr[i][j];
			//cout<<i<<" "<<j<<" "<<pre[i][j]<<'\n';
		}
	}
	
	for(int i=1;i<=m;i++){
		pre[n+1][i] = pre[n][i];
	}
	for(int i=1;i<=m-k+1;i++){
		dp[1][i] = getsum(1,i,2,i+k-1);
		//cout<<1<<" "<<i<<" "<<dp[1][i]<<'\n';
	}
	
	for(int i=2;i<=n;i++){
		memset(seg,0,sizeof(seg));
		memset(tag,0,sizeof(tag));
		for(int j=m+1;j<=2*m;j++){
			seg[j] = dp[i-1][j-m];
		}
		for(int j=m;j>=1;j--){
			seg[j] = max(seg[j<<1],seg[j<<1|1]);
		}
		for(int j=1;j<=k;j++){
			add(max(j-k+1,1LL),j,-arr[i][j]);
		} 
		/*for(int i=1;i<=m;i++){
			cout<<i<<" "<<que(i,i)<<'\n';
		}*/
		dp[i][1] = que(1,m) + getsum(i,1,i+1,k);
		
		for(int j=2;j<=m-k+1;j++){
			add(max(j-k,1LL),j-1,arr[i][j-1]);
			add(j,min(j+k-1,m-k+1),-arr[i][j+k-1]);
			dp[i][j] = que(1,m) + getsum(i,j,i+1,j+k-1);
			//cout<<i<<" "<<j<<" "<<i+1<<" "<<j+k-1<<" "<<getsum(i,j,i+1,j+k-1)<<'\n';
			
		}
		
		/*for(int j=1;j<=m-k+1;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}*/
	}
	
	ll ans = 0;
	for(int i=1;i<=m-k+1;i++){
		ans = max(ans,dp[n][i]);
	}
	cout<<ans<<'\n';
}

