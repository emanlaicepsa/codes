#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vll=vector<ll>;
vi v;
vi res;
vi two;
bool bigger(vi &a, vi &b){
	if(a.size()!=b.size())return a.size()>b.size();
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])return a[i]>b[i];
	}
	return false;
}
void tovec(vi &v,vll &j){
	v.resize(j.size()*8);
	int idx=0;
	for(int i=0;i<j.size();i++){
		int cnt=0;
		ll k=j[i];
		while(k){
			//cout<<k<<'\n';
			v[idx++]=k%10;
			k/=10;
			cnt++;
		}
		while(cnt<8&&i!=j.size()-1){
			v[idx++]=0;
			cnt++;
		}
	}
	while(!v.empty()&&v[v.size()-1]==0)v.pop_back();
	reverse(v.begin(),v.end());
}
void mul(vi &v,vi &j){
	vi k=v;
	v.clear();
	vll t1,t2;
	reverse(k.begin(),k.end());
	reverse(j.begin(),j.end());
	ll t=1;
	ll tempans=0;
	for(int i=0;i<k.size();i++){
		tempans+=(k[i])*t;
		t*=10;
		if(t==100000000||i==k.size()-1){
			//cout<<tempans<<'\n';
			t1.push_back(tempans);
			tempans=0;
			t=1;
		}
	}
	//for(auto i:t1)cout<<i;cout<<'\n';
	for(int i=0;i<j.size();i++){
		tempans+=(j[i])*t;
		t*=10;
		if(t==100000000||i==j.size()-1){
			t2.push_back(tempans);
			tempans=0;
			t=1;
		}
	}
	//for(auto i:t2)cout<<i;cout<<'\n';
	vll t3;
	t3.resize(t1.size()+t2.size()+1);
	for(int i=0;i<t3.size();i++)t3[i]=0;
	for(int i=0;i<t1.size();i++){
		for(int j=0;j<t2.size();j++){
			t3[i+j]+=t1[i]*t2[j];
		}
	}
	for(int i=0;i<t3.size();i++){
		t3[i+1]+=t3[i]/100000000;
		t3[i]%=100000000;
	}
	
	tovec(v,t3);
	//for(auto i:v)cout<<i; cout<<'\n';
}

void mins(vi &v,vi j){
	reverse(v.begin(),v.end());
	reverse(j.begin(),j.end());
	for(int i=0;i<j.size();i++){
		v[i]-=j[i];
	}
	for(int i=0;i<v.size();i++){
		while(v[i]<0)v[i]+=10,v[i+1]--;
	}
	while(!v.empty()&&v[v.size()-1]==0)v.pop_back();
	reverse(v.begin(),v.end());
}

void add(vi &v,vi j){
	reverse(v.begin(),v.end());
	reverse(j.begin(),j.end());
	if(v.size()<j.size())swap(v,j);
	for(int i=0;i<j.size();i++){
		v[i]+=j[i];
	}
	for(int i=0;i<v.size();i++){
		if(v[i]>=10){
			if(i==v.size()-1)v.push_back(v[i]/10);
			else v[i+1]+=v[i]/10;
			v[i]%=10;
		}
	}
	reverse(v.begin(),v.end());
}

vi findnum(vi &v,vi &res,int zeros){
	vi t,t2;
	t.resize(zeros+1);
	t2.resize(zeros+1);
	for(int i=0;i<=zeros;i++){
        t[i]=0;
        t2[i]=0;
    }
    int l=0,r=9;
    while(l<r){
    	int m=(l+r+1)>>1;
    	//cout<<m<<'\n';
    	t[0]=m;
    	t2[0]=m;
    	vi t3=t;
    	vi t4=t2;
    	add(t4,res);
    	mul(t3,t4);
    	//for(auto i:t3)cout<<i;cout<<'\n';
    	if(bigger(t3,v)){
            r=m-1;
        }
        else l=m;
	}
	t[0]=l;
	//cout<<l<<'\n';
    return t;
}

vi ans(vi &v){
	vi aa;
	aa.push_back(0);
	res.push_back(0);
	aa.resize((v.size()-1)/2+1);
	int zeros=(v.size()-1)/2;
	while(!v.empty()&&zeros>-1){
		//for(auto i:v)cout<<i;cout<<'\n';
		vi j=findnum(v,res,zeros);
		//for(auto i:j)cout<<i;cout<<'\n';
		vi t=j;
		vi t2=t;
		add(t2,res);
		mul(t,t2);
		mins(v,t);
		//for(auto i:v)cout<<i;cout<<'\n';
		add(aa,j);
		mul(j,two);
		//for(auto i:j)cout<<i;cout<<'\n';
		add(res,j);
		//for(auto i:res)cout<<i;cout<<'\n';
		zeros--;
	}
	return aa;
} 

int main(){
	two.push_back(2);
	int n;
	cin>>n;
	string s;
	while(n--){
		v.clear();
		res.clear();
		cin>>s;
		v.resize(s.size());
		for(int i=0;i<s.size();i++){
			v[i]=s[i]-'0';
		}
		vi aa=ans(v);
		for(int i=0;i<aa.size();i++){
			cout<<aa[i];
		}
		cout<<'\n';
	}
}

