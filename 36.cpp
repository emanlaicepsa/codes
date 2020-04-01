#include<iostream>
using namespace std;
int main()
{
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 unsigned long long int a,b,c;
	 cin>>a>>b>>c;
	 if(c==1){
	 	cout<<0<<endl;
	 	return 0;
	 }
	 b%=(c-1);
	 long long int e=a%c;
	 for(int d=0;d<b-1;d++){
	 	a%=c;
		a*=e;
	 }
	 a%=c;
	cout<<a<<endl;






}

