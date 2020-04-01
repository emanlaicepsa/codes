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
queue<int> q1;
queue<int> q2;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i] == 'D')q1.push(i);
		else q2.push(i);
	}
	while(!q1.empty() && !q2.empty()){
		if(q1.front() < q2.front()){
			//cout<<q1.front() << " "<<q2.front()<<'\n';
			q2.pop();
			q1.push(q1.front()+n);
			q1.pop();
		}
		else{
			q1.pop();
			q2.push(q2.front()+n);
			q2.pop();
		}
	}
	if(q1.size()){
		cout<<"D\n";
	}
	else cout<<"R\n";

}

