#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<string> sep;
inline bool isdig(char x){
	return (x>='0'&&x<='9');
}
int toint(string x){
	int tot=0;
	for(int i=0;i<x.size();i++){
		tot*=10;
		tot+=x[i]-'0';
	}
	return tot;
}
struct wt{
	string name;
	int stknum;
	int nownum;
};
map<string,int> tal;
vector<wt> wtline;

int main(){
	wtline.resize(500);
	string ori;
	cin>>ori;
	cout<<ori<<'\n';
	string temp="";
	ori+=' ';
	for(int i=0;i<ori.size()-1;i++){
		temp+=ori[i];
		if(ori[i]=='('||ori[i]==')'){
			sep.emplace_back(temp);
			temp="";
		}
		else if(isdig(ori[i])&&(!isdig(ori[i+1]))){
			sep.emplace_back(temp);
			temp="";
		}
		else if(!isdig(ori[i])&&isdig(ori[i+1])){
			sep.emplace_back(temp);
			temp="";
		}
		else if(isupper(ori[i+1])){
			sep.emplace_back(temp);
			temp="";
		}
		else if(ori[i+1]=='('||ori[i+1]==')'){
			sep.emplace_back(temp);
			temp="";
		}
		else if(i==ori.size()-2){
			sep.emplace_back(temp);
			temp="";
		}
	}
	
	/*for(auto i:sep){
		cout<<i<<'\n';
	}*/
	
	int stk=0;
	int idx=0;
	sep.emplace_back(" ");
	for(int i=0;i<sep.size()-1;i++){
		//cout<<sep[i]<<'\n';
		if(sep[i]=="("){
			stk++;
		}
		else if(sep[i]==")"){
			int mul;
			if(isdigit(sep[i+1][0])){
				mul=toint(sep[i+1]);
				i++;
			}
			else mul=1;
			//cout<<stk
			for(int j=idx-1;wtline[j].stknum==stk&&j>=0;j--){
				//cout<<wtline[j].name<<" "<<wtline[j].stknum<<" "<<wtline[j].nownum<<'\n';
				wtline[j].nownum*=mul;
				wtline[j].stknum--;
				if(wtline[j].stknum==0){
					if(tal.find(wtline[j].name)==tal.end()){
						tal[wtline[j].name]=wtline[j].nownum;
					}
					else tal[wtline[j].name]+=wtline[j].nownum;
					idx--;
				}
			}
		/*	for(int i=0;i<idx;i++){
				cout<<wtline[i].name<<" "<<wtline[i].stknum<<" "<<wtline[i].nownum<<'\n';
			}*/
			stk--;
		}
		else if(!isdigit(sep[i][0])&&isdigit(sep[i+1][0])){
			if(stk==0){
				if(tal.find(sep[i])==tal.end())tal[sep[i]]=toint(sep[i+1]);
				else tal[sep[i]]+=toint(sep[i+1]);
			}
			else{
				wtline[idx++]={sep[i],stk,toint(sep[i+1])};
			}
			i++;
		}
		else if((!isdigit(sep[i][0]))&&(!isdigit(sep[i+1][0]))){
			//cout<<sep[i]<<'\n';
			if(stk==0){
				if(tal.find(sep[i])==tal.end())tal[sep[i]]=1;
				else tal[sep[i]]+=1;
			}
			else{
				wtline[idx++]={sep[i],stk,1};
				//cout<<sep[i]<<' '<<stk<<'\n';
			}
		}
	}
	
	for(auto &i:tal){
		cout<<i.first<<":"<<i.second<<'\n';
	}

}

