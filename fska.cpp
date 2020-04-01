#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
string a;
void add(int n,int mod){
	a[n]+=mod;
	if(a[n]-'0'>=10){
		a[n]-=10;
		add(n-1,1);
	}
}

int main(){
	int x;
	cin>>x;
	cin>>a;
	int n=a.length()-1;
	while(x>0){
		add(n,x%10);
		x/=10;
		n--;
	}
	cout<<a<<endl;


}

