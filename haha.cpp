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
 cout<<"�п�J�A�����ɦ��Z"<<endl; 
 cin>>a;
 cout<<"�п�J�A���@�q���Z"<<endl; 
 cin>>b;
 cout<<"�п�J�A���G�q���Z"<<endl; 
 cin>>c;
 double ans=(x-a*2.0/5.0-b/5.0-c/5.0)*5.0;
 cout<<"�A�o���q�ҭn��"<<ceil(ans+eps)<<"���~�|�ή�"<<endl; 
}

