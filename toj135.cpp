#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll= long long;
set<int> s[20];
int main(){
	IOS
	int n;
	int t=0;
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<20;i++){
			s[i].clear();
		}
		int ye,a,b;
		for(int i=0;i<n;i++){
			cin>>ye>>a>>b;
			int x=b-a;
			while(ye<=10000){
				s[i].insert(ye);
				ye+=x;
			}
		}
		bool can=1;
		for(int i=0;i<n-1;i++){
			auto s1=s[i].begin();
			auto s2=s[i+1].begin();
			set<int> t;
			while(s1!=s[i].end()&&s2!=s[i+1].end()){
				if(*s1==*s2){
					t.insert(*s1);
					s1++;
				}
				else if(*s1>*s2){
					s2++;
				}
				else{
					s1++;
				}
			}
			if(t.size()==0){
				can=0;
				break;
			}
			swap(s[i+1],t);
		}
		cout<<"Case #"<<++t<<":\n";
		if(can)cout<<"The actual year is "<<*s[n-1].begin()<<".\n";
		else cout<<"Unknown bugs detected.\n";
		cout<<'\n';	
	}



}

