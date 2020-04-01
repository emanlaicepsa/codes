#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
double eps=1e-7;
int main(){
 double a,b,c;
 double x=58.6;
 cout<<"請輸入你的平時成績"<<endl; 
 cin>>a;
 cout<<"請輸入你的一段成績"<<endl; 
 cin>>b;
 cout<<"請輸入你的二段成績"<<endl; 
 cin>>c;
 double ans=(x-a*2.0/5.0-b/5.0-c/5.0)*5.0;
 cout<<"你這次段考要考"<<ceil(ans+eps)<<"分才會及格"<<endl; 
}

