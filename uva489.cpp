#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
 	int n;
  	while(cin>>n){
  	int has[26]={0};  
  	if(n==-1)return 0;
 	cout<<"Round "<<n<<endl;
 	string ans,guess;
 	cin>>ans>>guess;
 	int hangcount=0;
 	int anscount=0;
 	for(int x=0;x<ans.length();x++){
 		if(!has[ans[x]-'a']){
 			has[ans[x]-'a']=1;
 			anscount++;
		 }
	 }
	/*for(int x=0;x<26;x++){
		if(has[x]==1)cout<<(char)(x+'a');
	}*/
 	for(int x=0;x<guess.length();x++){
 		if(!has[guess[x]-'a']){
 			//cout<<1;
 			has[guess[x]-'a']=2;
 			hangcount++;
 			if(hangcount==7){
 				cout<<"You lose."<<endl;
 				goto qqq;
			 }
		}
		if(has[guess[x]-'a']==1){
			//cout<<2;
			anscount--;
			has[guess[x]-'a']=2;
			if(anscount==0){
				cout<<"You win."<<endl;
				goto qqq;
				
			}
		}
	 }
 	cout<<"You chickened out."<<endl;
 	
 	
 	
 	qqq:;
 	} 



}

