#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
vector<pii> arr;
map<pii,int> cnt;
set<pii> used;
int main(){
	IOS
	int t;
	cin>>t;
	long double t1,t2;
	int kase=0;
	while(t--){
		//memset
		arr.clear();
		cnt.clear();
		used.clear();
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>t1>>t2;
			int x=t1*100;
			int y=t2*100;
			//cout<<x<<y<<endl;
			if(used.find({x,y})==used.end()){
				used.insert({x,y});
				arr.emplace_back(x,y);
			}
		}
		if(arr.size()==1){
			cout<<"Data set #"<<++kase<<" contains a single gnu.\n";
			continue;
		}
		int ans=0;
		for(auto &i:arr){
			cnt.clear();
			for(auto &j:arr){
				int a=j.first-i.first;
				int b=j.second-i.second;
				//cout<<a<<" "<<b<<'\n';
				if(!a&&!b)continue;
				if(!a){
					if(cnt.find({0,0})==cnt.end()){
						cnt[{0,0}]=1;
					}
					else cnt[{0,0}]++;
					ans=max(ans,cnt[{0,0}]);
				}
				else if(!b){
					if(cnt.find({1000000,1000000})==cnt.end()){
						cnt[{1000000,1000000}]=1;
						//cout<<1<<'\n';
					}
					else cnt[{1000000,1000000}]++;
					ans=max(ans,cnt[{1000000,1000000}]);
				}
				else{
					if(b<0)a=-a,b=-b;
					int GCD=__gcd(abs(a),abs(b));
					a/=GCD;
					b/=GCD;
				//	cout<<a<<" "<<b<<endl;
					if(cnt.find({a,b})==cnt.end())cnt[{a,b}]=1;
					else cnt[{a,b}]++;
					ans=max(ans,cnt[{a,b}]);
				}
			}
		}
		cout<<"Data set #"<<++kase<<" contains "<<arr.size()<<" gnus, out of which a maximum of "<<ans+1<<" are aligned.\n";
	} 



}

