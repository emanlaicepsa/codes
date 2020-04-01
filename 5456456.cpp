#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct a{
	int x,y;
};
vector<a> gogo;
int main()
{
	int a,b;
	cin>>a>>b;
	gogo.push_back({a,b}); 
	cout<<gogo[0].x<<endl;






}

