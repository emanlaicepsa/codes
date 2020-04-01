#include<iostream>
#include<algorithm>
#include<memory.h>
#include<stack>
using namespace std;
int main()
{	
	string str;
	cin>>str;
	int count=0;
	int go=0;
	int index=1;
	stack<int> now;
	for(int a=0;a<str.length();a++) {
		if(str[a]==')'||str[a]=='}'||str[a]==']'||str[a]=='>'){
			go++;
			count++;
			if(go==2){
				index=a;
				now.push(count);
			}
		}
		if(str[a]=='('||str[a]=='{'||str[a]=='['||str[a]=='<'){
			go--;
		}
	}
	cout<<count-now.top()+1<<endl;
	






}

