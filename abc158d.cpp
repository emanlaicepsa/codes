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
int ope,q,ta;
deque<char> dq;
string s;
char c;
bool rev= 0;

int main(){
	IOS;
	
	cin>>s;
	for(auto i:s) dq.pb(i);
	
	cin>>q;
	while(q--){
		cin>>ope;
		if(ope == 1) rev^=1;
		else{
			cin>>ta>>c;
			if(rev){
				if(ta == 1){
					dq.pb(c);
				}
				else{
					dq.push_front(c);
				}
			}
			else{
				if(ta==1){
					dq.push_front(c);
				}
				else{
					dq.pb(c);
				}
			}
		}
	}
	if(rev) reverse(all(dq));
	for(auto i:dq)cout<<i;
	cout<<'\n';

}

