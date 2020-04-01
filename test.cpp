#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int aoi[40]={1};

int akari(int x,int a,int b,int o)
{	
	cout<<x<<" "<<a<<" "<<b<<" "<<o<<'\n';
    int u=x>>1;
    if(a&&b==0)
        return 0;
    if(a>b)
        swap(a,b);
    /*if(a==x)
        return aoi[o];*/
    if(b<=u)
        return akari(u,a,b,o-1);
    if(b==x)
    {
        if(a<=u)
            return akari(u,a,u,o-1)*2;
        return aoi[o-1]*2+akari(u,a-u,u,o-1);
    }
    if(a<=u)
        return akari(u,a,u,o-1)+akari(u,a,b-u,o-1);
    return aoi[o-1]+akari(u,u,b-u,o-1)+akari(u,a-u,u,o-1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,c,d,i,w=(int)1<<39;
    for(i=1;i<=39;i++)
        aoi[i]=aoi[i-1]*3;
    cin>>a>>b>>c>>d;
    a--,b--;
    cout<<akari(w,1,10000000000,39)<<'\n';
    
    return 0;
}

