#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T,count=0;
	int N;
	string a;
	cin>>T;
	while(T--){
		count++;
		cin>>N;
		cin>>a;
		cout<<"Case #"<<count<<": ";
		for(int x=0;x<a.length();x++){
			if(a[x]=='S')cout<<'E';
			else cout<<'S';
		}
		cout<<endl;
	}







}

