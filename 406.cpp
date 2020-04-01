#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#include<memory.h>
using namespace std;
ll ans=0;
ll num[4][8]={0};
int main(){
	IOS;
	int N;
	while(cin>>N){
		ans=0;
		memset(num,0,sizeof(num));
		int a,b,c,d;
		while(N--){
			cin>>a>>b>>c>>d;
			num[a][b*4+c*2+d*1]++;
		}
		/*for(int Q=0;Q<8;Q++)
			cout<<num[1][Q]<<endl;*/
		for(int Q=0;Q<8;Q++)
			for(int R=0;R<8;R++)
				for(int S=0;S<8;S++){
					if((Q|R|S)==7){
						//cout<<Q<<" "<<R<<" "<<S<<endl;
						//cout<<1<<endl;
						//if(num[1][Q]*num[2][R]*num[3][S])cout<<Q<<R<<S<<endl;
						ans+=num[1][Q]*num[2][R]*num[3][S];
					}
					
				}
		cout<<ans<<endl;
		
	}



}

