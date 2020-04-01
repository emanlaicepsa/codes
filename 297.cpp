#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<map> 
using namespace std;

map<int,int,greater<int>> pmax;
map<int,int> pmin;
map<int,int>::iterator iter;
vector<int>ans;
void printmin(){
	//for(iter=pmax.begin();iter!=pmax.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
	iter=pmin.begin();
	int q=iter->first;
	ans.emplace_back(q);
	iter->second--; 
	//cout<<iter->second<<endl;
	if(iter->second==0)pmin.erase(iter);
	iter=pmax.find(q);
	iter->second--;
	if(iter->second==0)pmax.erase(iter);
}
void printmax(){
	//for(iter=pmax.begin();iter!=pmax.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
	iter=pmax.begin();
	int q=iter->first;
	ans.emplace_back(q);
	iter->second--; 
	//cout<<iter->second<<endl;
	if(iter->second==0)pmax.erase(iter);
	iter=pmin.find(q);
	iter->second--;
	if(iter->second==0)pmin.erase(iter);
}

int main(){
	IOS;
	int x;
	int num=0;
	while(cin>>x){
		if(x==0){
			if(ans.size()>0){
				for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl; 
			}
			
			return 0;
		}
		if(x==-1){
			if(num==0)continue;
			printmin();
			num--;
			/*for(iter=pmin.begin();iter!=pmin.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
			cout<<endl;*/
		}
		else if(x==-2){
			if(num==0)continue;
			printmax();
			num--;
			/*for(iter=pmin.begin();iter!=pmin.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
			cout<<endl;*/
		}
		else{
			num++;
			if(pmax[x])pmax[x]++;
			else pmax[x]=1;
			if(pmin[x])pmin[x]++;
			else pmin[x]=1;
		}
	}
	


}

