#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<int> arr;
set<int> s;
unordered_map<int,int> m;
int cnt[80005];
int ans[1000][1000];
int bcnt[1000][80005];
int sqn;
int query(int l,int r){
	unordered_set<int> x;
	int rl=l%sqn==0 ? l/sqn : l/sqn+1;
	int rr=(r+1)%sqn==0?r/sqn:r/sqn-1;
	//cout<<rl<<rr<<endl;
	if(rl>rr){
		int nowans=0;
		int cnt2[80005]={0};
		for(int i=l;i<=r;i++){
			cnt2[arr[i]]++;
			if(cnt2[arr[i]]>nowans)nowans=cnt2[arr[i]];
		}
		return nowans;
	}
	int answ=ans[rl][rr];
	int cnt2[80005]={0};
	bool used[80005]={0};
	for(int i=l;i%sqn;i++){
		if(!used[arr[i]]){
			if(rl==0)cnt2[arr[i]]+=bcnt[rr][arr[i]];
			else cnt2[arr[i]]+=bcnt[rr][arr[i]]-bcnt[rl-1][arr[i]];
			used[arr[i]]=1;
		}
		cnt2[arr[i]]++;
		answ=max(answ,cnt2[arr[i]]);
	}
	for(int i=r;(i+1)%sqn;i--){
		if(!used[arr[i]]){
			if(rl==0)cnt2[arr[i]]+=bcnt[rr][arr[i]];
			else cnt2[arr[i]]+=bcnt[rr][arr[i]]-bcnt[rl-1][arr[i]];
			used[arr[i]]=1;
		}
		cnt2[arr[i]]++;
		answ=max(answ,cnt2[arr[i]]);
	}
	return answ;
}


int main(){
	IOS
	int n,q;
	cin>>n>>q;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	} 
	int t=0;
	for(auto i=s.begin();i!=s.end();i++){
		m[*i]=++t;
	}
	for(int &i:arr){
		i=m[i];
	}
	sqn=sqrt(n);
	for(int i=0,l=0;i<n;i+=sqn,l++){
		memset(cnt,0,sizeof(cnt));
		int nowcnt=0;
		for(int j=i;j<n;j++){
			cnt[arr[j]]++;
			if(cnt[arr[j]]>nowcnt)nowcnt=cnt[arr[j]];
			if((j+1)%sqn==0){
				if(i==0){
					for(int i=1;i<=n;i++){
						bcnt[j/sqn][i]=cnt[i];
					}
				}
				ans[i/sqn][j/sqn]=nowcnt;
				//cout<<i/sqn<<" "<<j/sqn<<" "<<nowcnt<<endl;
			}
		} 
	} 
	int d=0;
	int ql,qr;
	while(q--){
		cin>>ql>>qr;
		if(ql>qr)swap(ql,qr);
		int t1=query(ql-d-1,qr-d-1);
		cout<<t1<<'\n';
		d=t1;
	}
}

