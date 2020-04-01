#include<iostream>
#include<algorithm>
using namespace std;
struct BB{
    int s;
    int e;
}bb[1005];
bool cmp(BB x,BB y){
    return x.s<y.s;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(cin>>N){
    for(int i=0;i<N;i++)cin>>bb[i].s>>bb[i].e;
    sort(bb,bb+N,cmp);
    /*for(int i=0;i<N;i++){
        cout<<bb[i].s<<" "<<bb[i].e<<endl;;
    }*/
    int index=0;
    int timex=bb[0].s-1;
    int num=0;
    while(index<N){
    	int q=-1;
    	for(;bb[index].s<=timex+1&&index<N;index++){
    		q=max(q,bb[index].e);
		}
		if(q==-1){
			cout<<"NO"<<endl;goto qq;
		}
		if(q>timex)num++;
		timex=q;
		
		
		//cout<<timex<<" "<<index<<endl;
	}
    cout<<num<<endl;
    qq:;
    
    }
    return 0;
}
