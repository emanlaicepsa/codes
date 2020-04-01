#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	long long ans=x*a/b;
	double k=double(double(x)*double(a)/double(b));
	if(double(k-double(ans))!=0){
		cout<<"No"<<endl;
		return 0;
	}
	int y;
	while(n--){
		cin>>y;
		if(y==ans){
			cout<<"Yes"<<endl;
			return 0;
		}
	} 
	cout<<"No"<<endl;






}

