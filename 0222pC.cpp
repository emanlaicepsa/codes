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
struct node{
	int cnt;
	int nxt[2];
}trie[2000005];

int idx;
void add(int now,int pos,ll x){
	//cout<<now<<" "<<pos<<" "<<x<<'\n'; 
	if(pos>18)return;
	trie[now].cnt ++;
	ll num = x%10;
	if(num&1){
		if(!trie[now].nxt[1])trie[now].nxt[1] = ++idx;
		add(trie[now].nxt[1],pos+1,x/10);
	}
	else{
		if(!trie[now].nxt[0])trie[now].nxt[0] = ++idx;
		add(trie[now].nxt[0],pos+1,x/10);
	}
}

void sub(int now,int pos,ll x){
	//cout<<now<<" "<<pos<<" "<<x<<'\n'; 
	if(pos>18)return;
	trie[now].cnt --;
	ll num = x%10;
	if(num&1){
		//assert(trie[now].nxt[1]!=0);
		sub(trie[now].nxt[1],pos+1,x/10);
	}
	else{
		sub(trie[now].nxt[0],pos+1,x/10);
	}
}

ll query(ll now,string s){
	if(s==""){
		return trie[now].cnt;
	}
	char x = s[s.size()-1];
	s.pop_back();
	//cout<<s<<'\n';
	if(x=='0'){
		if(!trie[now].nxt[0])trie[now].nxt[0] = ++idx;
		return query(trie[now].nxt[0],s);
	}
	else{
		if(!trie[now].nxt[1])trie[now].nxt[1] = ++idx;
		return query(trie[now].nxt[1],s);
	}
}

int main(){
	//IOS;
	int t;
	char ope;
	string s;
	ll x;
	cin>>t;
	while(t--){
		cin>>ope;
		if(ope=='+'){
			cin>>x;
			add(0,0,x);
		}
		else if(ope=='-'){
			cin>>x;
			sub(0,0,x);
		}
		else{
			cin>>s;
			while(s.size()<18)s = '0' +s;
			cout<<query(0,s)<<'\n';
		}
	}


}

