#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<stack>
using namespace std;
vector<string> strs;
struct voc{
	int vnum;
	char lastv;
	int index;
};
vector<voc> data;
int vc(string s){
	int count=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')count++;
	}
	return count;
}
char lv(string s){
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')return s[i];
	}
	return -1;
}
bool cmp(voc a,voc b){
	if(a.vnum!=b.vnum )return a.vnum >b.vnum;
	else return a.lastv >b.lastv ;
}
vector<int> f;
vector<int> l;
stack<voc> q;
int main(){
	int n;
	cin>>n;
	string s;
	int index=0;
	while(n--){
		cin>>s;
		strs.push_back(s);
		int v=vc(s);
		char c=lv(s);
		voc x={v,c,index};
		data.push_back(x);
		index++; 
	}
	sort(data.begin() ,data.end(),cmp );
	//for(int i=0;i<data.size();i++)cout<<data[i].vnum<<" "<<data[i].lastv<<" "<<data[i].index<<endl;
	int j=0;
	for(int k=data[0].vnum;k>=0;k--){
		while(!q.empty())q.pop();
		while(j<data.size()&&data[j].vnum==k){
			if(q.size()>=1&&q.top().lastv==data[j].lastv){
				l.push_back(data[j].index);
				l.push_back(q.top().index);
				q.pop();
			}
			else{
				q.push(data[j]);
			}
			j++;
		}
		int num=q.size()/2;
		for(int i=0;i<num*2;i++){
			f.push_back(q.top().index);
			q.pop();
		}
	}
	while(f.size()<l.size()){
		for(int i=0;i<2;i++){
			f.push_back(l[l.size()-1]);
			l.pop_back(); 
		}
	}
	int ans=l.size()/2;
	cout<<ans<<endl;
	for(int i=0,j=0;i<ans;i++,j+=2){
		cout<<strs[f[j]]<<" "<<strs[l[j]]<<endl;
		cout<<strs[f[j+1]]<<" "<<strs[l[j+1]]<<endl;
	}
	
	
}

