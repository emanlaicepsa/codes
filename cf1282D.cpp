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
ll an,bn;
ll anum,bnum;
int main(){
	string s;
	for(int i=1;i<=300;i++){
		s+="a";
	}
	cout<<s<<endl;
	cin>>an;
	anum=300-an;
	s="";
	for(int i=1;i<=300;i++){
		s+="b";
	}
	cout<<s<<endl;
	cin>>bn;
	bnum=300-bn;
	int nidx=0;
	string as="";
	for(int i=1;i<=anum;i++)as+="a";
	ll pre=bnum;
	if(pre==0){
		cout<<as<<endl;	
		cin>>pre;
		return 0;
	}
	for(int i=0;i<=anum;i++){
		string t1=as.substr(0,nidx);
		string t3=as.substr(nidx,as.size()-nidx);
		string t2="";
		while(1){
			t2+="b";
			string ta=t1+t2+t3;
			cout<<ta<<endl;
			ll xx;
			cin>>xx;
			if(xx>=pre)break;
			pre=xx;
			if(xx==0){
				return 0;
			}
		}
		t2.pop_back();
		as=t1+t2+t3;
		nidx=t1.size()+t2.size()+1;
	}


}

