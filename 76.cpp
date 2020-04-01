#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include "Pikachu.h"
using namespace std;
vector<int> num1[20];
vector<int> num0[20];
int lack[20]={0};
bool is1 =true;
int main(){
	int num=Init();
	//int num=16;
	int q=num;
	int k=-1;
	while(q%2==0){
		q/=2;
		k++;
	}
	//cout<<k<<endl;
	for(int x=0;x<num-1;x++){
		 //int q;
		 //cin>>q;
		 int q=GetBit(x,0);
		 if(q==1)num1[0].emplace_back(x);
		 else num0[0].emplace_back(x);
	}
	is1=(num1[0].size()<num0[0].size())?true:false;
	//cout<<is1<<endl;
	lack[0]=is1? true:false;
	for(int x=1;x<=k;x++){
		if(is1){
	   		for(int y:num1[x-1]){
	   			//cout<<y<<endl;
				int q=GetBit(y,x);
				//int q;
		 		//cin>>q;
				if(q==1)num1[x].emplace_back(y);
				else num0[x].emplace_back(y);
	  		}	
	  	is1=(num1[x].size()<num0[x].size())?true:false;
	  	lack[x]=is1? 1:0;
		}
	else{
		for(int y:num0[x-1]){
			//cout<<y<<endl;
			int q=GetBit(y,x);
			//int q;
		 	//cin>>q;
			if(q==1)num1[x].emplace_back(y);
			else num0[x].emplace_back(y);
	  	}
		is1=(num1[x].size()<num0[x].size())?true:false;
		lack[x]=is1?1:0;		
	}	
	
	
	}
	int ans=0;
	for(int x=0;x<=k;x++){
		ans+=pow(2,x)*lack[x];
	}
	/*for(int x=0;x<=k;x++){
		cout<<lack[x]<<endl;
	}*/
	//cout<<ans<<endl;
	Answer(ans);

}

