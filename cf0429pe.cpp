#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_wiith_stdio(false);cin.tie(0);
using namespace std;
vector <char> yay;

int main(){
//	IOS;
	int a,b;
	cin>>a>>b;
	char T;
	int count=0,maxcount=0;
	int place=0;
	for(int x=0;x<(a-1)*2;x++){
		cin>>T;
		yay.emplace_back(T);
		if(T=='(')count++;
		if(T==')')count--;
		if(count>=maxcount){
			maxcount=count;
			place=x;
		}
	}
	for(char y:yay){
		cout<<y; 
	}
	cout<<maxcount<<" "<<place<<endl;
	int c,d; 
	while(b--){
		cin>>c>>d;
		c--;
		d--;
		if(yay[c]==yay[d]){
			cout<<maxcount<<endl;
		}
		else if(yay[c]=='('&&yay[d]==')'){
			swap(yay[c],yay[d]);
			if(c==place){
				maxcount-=2;
				place=
			}
		}
	}

}

