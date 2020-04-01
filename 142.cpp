#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	string x;
	vector<char> go;
	for(int a=0;a<3;a++){
		cin>>x;
		for(int b=0;b<3;b++){
			go.push_back(x[b]); 
		}
	}
	for(int a=0;a<9;a+=3){
		if(go[a]==go[a+1]&&go[a+1]==go[a+2]){
			if(go[a]=='O'){
				cout<<"A wins."<<endl;
				return 0;
			}
			else if(go[a]=='X'){
				cout<<"B wins."<<endl;
				return 0;
			}
		}
	}
	for(int a=0;a<3;a++){
		if(go[a]==go[a+3]&&go[a+3]==go[a+6]){
			if(go[a]=='O'){
				cout<<"A wins."<<endl;
				return 0;
			}
			else if(go[a]=='X'){
				cout<<"B wins."<<endl;
				return 0;
			}
		}
	}
	if(go[0]==go[4]&&go[4]==go[8]){
		if(go[0]=='O'){
				cout<<"A wins."<<endl;
				return 0;
			}
			else if(go[0]=='X'){
				cout<<"B wins."<<endl;
				return 0;
			}
	}
	if(go[2]==go[4]&&go[4]==go[6]){
		if(go[2]=='O'){
				cout<<"A wins."<<endl;
				return 0;
			}
			else if(go[2]=='X'){
				cout<<"B wins."<<endl;
				return 0;
			}
	}
	for(int a=0;a<=8;a++){
		if(go[a]=='#'){
			cout<<"Playing"<<endl;
			return 0;
		}
	}
	cout<<"Draw"<<endl;
	return 0;

}

