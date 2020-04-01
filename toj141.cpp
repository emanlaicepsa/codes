#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<string> cut;
stack<string> stk;
vector<string> post;
unordered_map <string,int> pri;
stack<int> calc;

inline bool isdigit(char c){
	if(c>='0'&&c<='9')return true;
	return false;
}

inline int toint(string s){
	int ans=0;
	int neg=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='-'){
			neg=-1;
			continue;
		}
		else{
			ans*=10;
			ans+=s[i]-'0';
		}
	}
	return ans*neg;
}

int main(){
	//IOS;
	pri["~"]=3;
	pri["&"]=2;
	pri["|"]=1;
	
	int t;
	string s;
	string tem;
	cin>>t;
	
	while(t--){
		cin>>s;
		cut.clear();
		while(!stk.empty())stk.pop();
		post.clear();
		while(!calc.empty())calc.pop();
		tem="";
		for(int i=0;i<s.size();i++){
			tem+=s[i];
			if((!isdigit(s[i])&&s[i]!='-')||i==s.size()-1)cut.push_back(tem),tem="";
			else if(!isdigit(s[i+1]))cut.push_back(tem),tem="";
		}
		for(auto i:cut){
			if(isdigit(i[0])||i[0]=='-')post.push_back(i);
			else if(i=="(")stk.push(i);
			else if(i==")"){
				while(stk.top()!="(")post.push_back(stk.top()),stk.pop();
				stk.pop();
			}	
			else{
				while(!stk.empty()&&stk.top()!="("&&pri[stk.top()]>=pri[i])post.push_back(stk.top()),stk.pop();
				stk.push(i);
			}
		}
		while(!stk.empty())post.push_back(stk.top()),stk.pop();
		for(auto i:post){
			//cout<<i<<'\n';
			if(isdigit(i[0])||i[0]=='-')calc.push(toint(i));
			else{
				if(i=="~"){
					int ta=calc.top();calc.pop();
					calc.push(~ta);
				}
				else if(i=="|"){
					
					int ta=calc.top();calc.pop();
					int tb=calc.top();calc.pop();
					//cout<<ta<<" "<<tb<<'\n';
					calc.push(ta|tb);
				}
				else{
					int ta=calc.top();calc.pop();
					int tb=calc.top();calc.pop();
					calc.push(ta&tb);
				}
			}
		}
		cout<<calc.top()<<'\n';
	}	



}

