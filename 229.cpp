#include<iostream>
#include<algorithm>
#include<memory.h>
int xbase[100001];
int ybase[100001];
int xplusybase[200001];
int xminusybase[200001];

using namespace std;
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int find=-1;
		bool hasfind=false;
		memset(xbase,0,sizeof(xbase));
		memset(ybase,0,sizeof(ybase));
		memset(xplusybase,0,sizeof(xplusybase));
		memset(xminusybase,0,sizeof(xminusybase));
		int n,k;
		cin>>n>>k;
		int cropx,cropy;
		for(int i=1;i<=n;i++){
			cin>>cropx>>cropy;
			xbase[cropx]++;
			ybase[cropy]++;
			xplusybase[cropx+cropy]++;
			xminusybase[cropx-cropy+100000]++;
			if(xbase[cropx]==k||ybase[cropy]==k||xplusybase[cropx+cropy]==k||xminusybase[cropx-cropy+100000]==k){
				if(hasfind==false){
					find=i;
					hasfind=true;
				}
			}
		}
		cout<<find<<endl;
	}
		







}

