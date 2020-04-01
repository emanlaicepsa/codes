#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;

struct Side{
	int x;
	int y;
	int w;
}side[100]={0,0,0};

bool cmp(Side x,Side y){
	return x.w<y.w;
}


int main(){
	for(int i=0;i<3;i++){
		cin>>side[i].x >>side[i].y >>side[i].w;
	}
	sort(side,side+3,cmp);
	for(Side j:side){
		cout<<j.x<<j.y<<j.w<<endl;
	}


}

