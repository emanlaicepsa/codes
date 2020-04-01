#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
	long double a,b;
	cin>>a>>b;
	b=b*b;
	int count=0;
	while(a<b){
		b/=2;
		count++;
	}
	cout<<count<<endl;



}

