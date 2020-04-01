#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
long double t1[3],t2[3],t3[3],t4[3];
int main(){
	for(int i=0;i<3;i++){
		cin>>t1[i]>>t2[i]>>t3[i]>>t4[i];
	}
	long double t5=max({t1[0],t1[1],t1[2]});
	long double t6=max({t2[0],t2[1],t2[2]});
	long double t7=min({t3[0],t3[1],t3[2]});
	long double t8=min({t4[0],t4[1],t4[2]});
	long double ans1=0;
	if(t7<t5||t8<t6)cout<<"0.00 ";
	else {
		ans1=(t7-t5)*(t8-t6);
		cout<<fixed<<setprecision(2)<<ans1<<' ';
	}
	t5=max(t1[0],t1[1]);
	t6=max(t2[0],t2[1]);
	t7=min(t3[0],t3[1]);
	t8=min(t4[0],t4[1]);
	long double ans2=0;
	if(t7>=t5&&t8>=t6){
		ans2+=(t7-t5)*(t8-t6);
	}
	t5=max(t1[2],t1[1]);
	t6=max(t2[2],t2[1]);
	t7=min(t3[2],t3[1]);
	t8=min(t4[2],t4[1]);
	if(t7>=t5&&t8>=t6){
		ans2+=(t7-t5)*(t8-t6);
	}
	t5=max(t1[0],t1[2]);
	t6=max(t2[0],t2[2]);
	t7=min(t3[0],t3[2]);
	t8=min(t4[0],t4[2]);
	if(t7>=t5&&t8>=t6){
		ans2+=(t7-t5)*(t8-t6);
	}
	ans2-=3*ans1;
	cout<<fixed<<setprecision(2)<<ans2<<' ';
	long double ans3=0;
	for(int i=0;i<3;i++){
		ans3+=(t3[i]-t1[i])*(t4[i]-t2[i]);
	}
	ans3-=2*ans2;
	ans3-=3*ans1;
	cout<<fixed<<setprecision(2)<<ans3<<'\n';
}

