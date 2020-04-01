#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct point{
	int x;
	int y;
	int z;
	int num;
};
vector<int> xs;
vector<int> ys;
vector<int> zs;
vector<point> p;
bool cmp(point a,point b){
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	if(a.z!=b.z)return a.z<b.z;
	return false;
}

bool used[100000];

int main(){
	int n,tx,ty,tz;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tx>>ty>>tz;
		xs.emplace_back(tx);
		ys.emplace_back(ty);
		zs.emplace_back(tz);
		p.push_back({tx,ty,tz,i});
	}
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	sort(zs.begin(),zs.end());
	xs.resize(unique(xs.begin(),xs.end())-xs.begin());
	ys.resize(unique(ys.begin(),ys.end())-ys.begin());
	zs.resize(unique(zs.begin(),zs.end())-zs.begin());
	//for(auto i:xs)cout<<i<<'\n';
	
	for(int i=0;i<p.size();i++){
	//	cout<<i<<" "<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<" "<<p[i].num<<'\n';
		p[i].x=lower_bound(xs.begin(),xs.end(),p[i].x)-xs.begin()+1;
		p[i].y=lower_bound(ys.begin(),ys.end(),p[i].y)-ys.begin()+1;
		p[i].z=lower_bound(zs.begin(),zs.end(),p[i].z)-zs.begin()+1;
		//cout<<i<<" "<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<" "<<p[i].num<<'\n';
	}
	sort(p.begin(),p.end(),cmp);
	
	for(int i=0;i<p.size();i++){
		//cout<<i<<" "<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<" "<<p[i].num<<'\n';
		if(used[i])continue;
		used[i]=1;
		int ansnum=0;
		int dis=100000000;
		for(int j=i+1;j<p.size();j++){
			if(used[j])continue;
			if(p[j].x-p[i].x>2)break;
			if(p[j].x==p[i].x&&abs(p[j].y-p[i].y)>dis)break;
			if(p[j].x==p[i].x&&p[j].y==p[i].y&&abs(p[j].z-p[i].z)>dis)break;
			
			if(abs(p[j].x-p[i].x)+abs(p[j].y-p[i].y)+abs(p[j].z-p[i].z)<dis){
				ansnum=j;
				dis=abs(p[j].x-p[i].x)+abs(p[j].y-p[i].y)+abs(p[j].z-p[i].z);
			}
		}
		used[ansnum]=1;
		cout<<p[i].num<<" "<<p[ansnum].num<<'\n';
	}
	
}

