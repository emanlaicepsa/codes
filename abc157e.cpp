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
ll n,q,ope,a,b;
char c;
string s;
ll bit[28][500005];
void add(int ar,int pos,int num){
	for(int i=pos;i<=n;i+=i&-i){
		bit[ar][i]+=num;
	}
}
int que(int ar,int pos){
	int ans = 0;
	for(int i=pos;i;i-=i&-i){
		ans += bit[ar][i];
	}
	return ans; 
}

int main(){
	IOS;
	cin>>n;
	cin>>s;
	s = " " + s;
	int siz = s.size();
	
	for(int i=1;i<siz;i++){
		add(s[i]-'a',i,1);
	}
	
	cin>>q;
	while(q--){
		cin>>ope;
		if(ope == 1){
			cin>>a>>c;
			add(s[a]-'a',a,-1);
			s[a] = c;
			add(s[a]-'a',a,1);
		}
		else{
			cin>>a>>b;
			int ans = 0;
			for(int i=0;i<26;i++){
				if(que(i,b) - que(i,a-1)) ans ++;
			}
			cout<<ans<<'\n';
		}
	}


}

