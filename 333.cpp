#include<iostream>
typedef long long ll;
using namespace std;

ll cl[10000005]={0};
ll fma[2]={0};
ll fmi[2]={0};
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int a=0;a<n;a++){
        cin>>cl[a];
    }
    fma[(n-1)%2]=cl[n-1];
    for(int i=n-2;i>=0;i--){
        fma[i%2]=max(fma[(i+1)%2],max(cl[i]-fmi[(i+1)%2],cl[i]));
        fmi[i%2]=min(fmi[(i+1)%2],min(cl[i]-fma[(i+1)%2],(ll)0));
        //cout<<fma[i]<<"  "<<fmi[i]<<endl;
    }
    cout<<fma[0]<<endl;
    
    return 0;
}

