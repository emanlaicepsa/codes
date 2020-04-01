#include<iostream>
#include<algorithm>
#include <vector>
#include <cmath> 
using namespace std;
vector<int> prime;
void primelist(int x){
	bool nprime[x];
	for(int a=2;a<=sqrt(x);a++){
		if(!nprime[a]){
			prime.emplace_back(a); 
			for(int q=2*a;q<=x;q+=a){
				nprime[a]=true;
			}
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		prime.clear();
		int N,L;
		vector<int> ori;
		vector<int> ansdigit;
		vector<char> anschar;
		
		cin>>N>>L;
		int k;
		while(L--){
			cin>>k;
			ori.emplace_back(k); 
		}
		primelist(N);
		int tempa,tempb;
		for(int j=0;j<prime.size();j++){
			if(ori[0]%prime[j]==0){
				tempa=prime[j];
				tempb=ori[0]/prime[j];
				break;
			}
		} 
		cout<<tempa<<' '<<tempb<<endl;
		tempa=ori[1]%tempb==0?tempa:tempb;
		ansdigit.emplace_back(tempa);
		for(int k=0;k<ori.size();k++){
			ansdigit.emplace_back(ori[k]/ansdigit[k]);
		} 
		for(int k=0;k<ansdigit.size();k++){
			cout<<ansdigit[k]<<" ";
		} 
		cout<<endl;
		vector<int> ansdigitcpy;
		ansdigitcpy.emplace_back(ansdigit[0]); 
		for(int k=1;k<ansdigit.size();k++){
			if(ansdigit[k]==ansdigit[k-1])continue;
			ansdigitcpy.emplace_back(ansdigit[k]); 
		}
		for(int k=0;k<ansdigitcpy.size();k++){
			cout<<ansdigitcpy[k]<<" ";
		} 
		sort(ansdigitcpy.begin(),ansdigitcpy.end());
	}







}

