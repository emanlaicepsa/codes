#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#include<queue>
using namespace std;
vector<int>x;
vector<char>go;


int main(){
	int n;
	cin>>n;
	int b;
	for(int a=0;a<n;a++) {
		cin>>b;
		x.push_back(b);
	}
	int left=0,right=x.size()-1,now=0,count=0;
	for(;left<=right&&left<x.size()&&right>0;){
		if(x[left]>now&&x[right]>now){
			if(x[left]<x[right]){
				now=x[left];
				left++;
				
				go.push_back('L');
			}
			else{
				now=x[right];
				right--;
				
				go.push_back('R');
			}
		}
		else if(x[left]>now){
			now=x[left];
			left++;
			
			go.push_back('L');
		}
		else if(x[right]>now){
			now=x[right];
			right--;
			go.push_back('R');
		}
		else break;
		//cout<<now<<endl;
		count++;
	}
		
	
	cout<<count<<endl;
	for(char i:go){
		cout<<i;
	}
	cout<<endl;
}

