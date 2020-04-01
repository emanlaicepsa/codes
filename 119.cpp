#include <iostream>
#include<algorithm>
using namespace std;
#define maxN 200005
int d[maxN];
int main()
{
    int a,b,c,g,n,e,f;
    bool x=0;
    cin>>n;
    for(a=1;a<=n;a++){
        cin>>d[a];}  
    cin>>b;
    for(g=0;g<b;g++){
        cin>>e>>f;
        if(e>f){swap(e,f);}
        if(f-e>8){
			cout<<"I QUIT!"<<endl;
			x=1;
			break;
		} 
		else swap(d[e],d[f]);   	                      
    }
        if(!x){cout<<"SORTED!"<<endl;}
        for(c=1;c<n;c++){
          cout<<d[c]<<" ";}
          cout<<d[n]<<endl;                
    return 0;
}
