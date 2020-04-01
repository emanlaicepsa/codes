#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
ll ans[10][10];
ll cnt[10];
int fdig;
inline long long power(ll x,ll po){
	ll t=x;
	ll ans=1;
	while(po){
		if(po&1)ans*=t;
		t*=t;
		po>>=1;
	}
	return ans;
}
int cntd(ll x){
	int ans=0;
	while(x){
		x/=10;
		ans++;
	}
	return ans;
}


void solve(ll x){
	if(x==0)return;
	ll t=1;
	while(t<=x)t*=10;
	t/=10;
	//cout<<t<<'\n';
	int dig=x/t;
	int re=x%t;
	//cout<<dig<<"¡@"<<re<<endl; 
	int digcntx=cntd(x);
	int zerocnt=cntd(x)-cntd(re)-1;
	cnt[dig]+=re+1;
	cnt[0]+=zerocnt*(re+1);
	for(int i=0;i<dig;i++){
		if(!i&&fdig)continue;
		cnt[i]+=power(10,(digcntx-1));
		if(digcntx>=2){
			for(int j=0;j<10;j++){
			cnt[j]+=(digcntx-1)*power(10,digcntx-2);
			}
		}	
	}
	fdig=0;
	solve(re);
}


int main(){
	for(int i=0;i<=9;i++){
		for(int j=1;j<=9;j++){
			ans[j][i]+=power(10,i);
		}
		if((i-1)>=0){
		for(int k=0;k<10;k++){
			ans[k][i]+=9*i*power(10,i-1);
			}
		}
	}
	int n;
	cin>>n;
	ll temp;
	while(n--){
		fdig=1;
		memset(cnt,0,sizeof(cnt));
		cin>>temp;
		ll k=10;
		ll q=0;
		while(temp>=k){
			for(int i=0;i<=9;i++){
				cnt[i]+=ans[i][q];
			}
			k*=10;
			q++;
		}
		solve(temp);
		for(int i=0;i<10;i++){
			if(i)cout<<" ";
			cout<<cnt[i];
		}
		cout<<'\n';
	} 


}

