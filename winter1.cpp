#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define fi first
#define se second
#define reset(n,k) memset((n),k,sizeof(n))
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int n,cnt;
struct team{
	string name;
	int sol;
	int pen;
};
vector<team> v;
bool cmp(team a,team b){
	if(a.sol!=b.sol)return a.sol>b.sol;
	if(a.pen!=b.pen)return a.pen<b.pen;
	if(a.name.size()!=b.name.size()) return a.name.size()<b.name.size();
	return a.name<b.name;
}
int rk[100005]; 
const double eps = 1e-5;
int maxsol;
int maxpen;
int maxname;
int maxrk;

int main(){
	//cout<<(int)'+'<<'\n';
	IOS;
	while(cin>>n){
		maxsol = 0;
		maxpen = 0;
		maxname = 0;
		maxrk = 0;
		reset(rk,0);
		v.clear();
		v.resize(n);
		cin.ignore();
		if(cnt)cout<<'\n';
		for(int i=0;i<n;i++){
			string all ;
			getline(cin,all);
			int j,qq;
			for(j=all.size()-1,qq=0;;j--){
				if(all[j]==' ')qq++;
				if(qq==2)break;
			} 
			string name = all.substr(0,j);
			ll num = 0,pen = 0;
			for(j++;all[j]!=' ';j++){
				num = num*10 + all[j]-'0';
			}
			for(j++;j<all.size();j++){
				pen = pen*10 + all[j]-'0';
			}
			//cout<<name<<" "<<num<<" "<<pen<<'\n';
			v[i].name = name;
			v[i].sol = num;
			v[i].pen = pen;
		}
		sort(all(v),cmp);
		for(int i=0;i<v.size();i++){
			if( i&& v[i].pen == v[i-1].pen &&v[i].sol == v[i-1].sol) rk[i] = rk[i-1];
			else rk[i] = i+1;
			maxrk = max(maxrk,rk[i]);
			maxsol = max(maxsol,v[i].sol);
			maxpen = max(maxpen,v[i].pen);
			maxname = max(maxname,int(v[i].name.size()));
		}
		maxrk = int(log10(maxrk)) +1 ;
		maxsol = int(log10(maxsol)) +1;
		maxpen = int(log10(maxpen)) +1;
		for(int i=0;i<v.size();i++){
			cout<<"Rank ";
			int x = maxrk - int(log10(max(rk[i],1))) -1;
			for(int i=0;i<x;i++)cout<<"0";
			cout<<rk[i]<<": ";
			x = maxname - v[i].name.size();
			for(int i=0;i<x;i++)cout<<" ";
			cout<<v[i].name<<" ";
			x = maxsol - int(log10(max(1,v[i].sol))) -1;
			for(int i=0;i<x;i++)cout<<"0";
			cout<<v[i].sol<<" ";
			x = maxpen - int(log10(max(1,v[i].pen))) -1;
			for(int i=0;i<x;i++)cout<<"0";
			cout<<v[i].pen<<'\n';
		}
		cnt++;
	}



}

