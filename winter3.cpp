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
string s[10] = {"fprFJT","bgzEG","hinULO","lquBC","coMPR","ajVKsX","dkDS","ytINZ","mvHQY","ewxAW"};
map<char,int> m;
int num[10000005];
bool np[10000005];
int minp[10000005];
vector<int> p;
int main(){ 
	IOS;
	for(int i=0;i<10;i++){
		for(auto j:s[i]) m[j] = i; 
	}
	num[1] = 1;
	for(ll i=2;i<=10000000;i++){
		if(!np[i])num[i] = 2, p.pb(i);
		else{
			int cnt = 0 ,tmp = i, mi = minp[i];
			while(tmp%mi==0) cnt++, tmp/=mi;
			num[i] = (cnt+1)* num[tmp];
		}
		for(auto j:p){
			if(i*j>10000000)break;
			minp[i*j]=j;
			np[i*j]=1;
			if(i%j==0)break;
		}
	}
	
	//for(int i=2;i<=10;i++)cout<<i<<" "<<num[i]<<"\n";
	for(int i=1;i<=10000000;i++)num[i] += num[i-1];
	string s;
	while(getline(cin,s)){
		int a=0,b=0,r=1;
		for(auto i:s){
			if(i>='0'&&i<='9')b+= (i-'0')*r, r*=10; 
			else if((i>='a'&&i<='z')||(i>='A'&&i<='Z'))a*=10 ,a+=m[i];
		}
		
		if(a<b) swap(a,b);
		assert(a<=10000000&&b<=10000000);
		cout<<num[a] - num[b-1]<<'\n';
	}
	
}

