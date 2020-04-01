#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
struct side{
	int s;
	int e;
	int cost;
}; 
int f[100005];
vector<side> ss;
bool cmp(side x,side y){
	return x.cost<y.cost ;
}
int father(int x){
	//cout<<x<<endl;
	if(f[x]==x)return f[x];
	else return f[x]=father(f[x]);
	/////////////////f[father(x)];
}


void connect(int x,int y){
//	cout<<x<<" "<<y<<endl;
	f[y]=f[father(y)]=father(x);
}


int main(){
	int k; cin>>k;
	for(int i=0;i<k;i++)f[i]=i;
	int R; cin>>R;
	side a;
	for(int i=0;i<R;i++){
		cin>>a.s>>a.e>>a.cost;
		ss.push_back(a); 
	}
	sort(ss.begin() ,ss.end() ,cmp);
	/*for(int i=0;i<R;i++){
		cout<<ss[i].s<<" "<<ss[i].e<<" "<<ss[i].cost<<endl;
	}*/
	int num=0;
	bool ok=0;
	int total=0;
	for(int i=0;i<R;i++){
		if(father(ss[i].s)!=father(ss[i].e)){
			connect(ss[i].s,ss[i].e);
			num++;
			total+=ss[i].cost;
			if(num==k-1){
				ok=1;
				break;
			}
		}
	}
	if(ok)cout<<total<<endl;
	else cout<<-1<<endl;
	


}

