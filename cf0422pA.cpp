#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
	int k;
	cin>>k;
	string a;
	cin>>a;
	int current=-1;
	for(int x=0;x<a.length();x++){
		//cout<<(int)(a[x]-'a');
		if((int)(a[x]-'a')<current){
			cout<<"YES"<<endl;
			cout<<x<<" "<<x+1<<endl;
			return 0;
		}
		current=(int)(a[x]-'a');
	}
	cout<<"NO"<<endl;
		
		
		
		
}
	





