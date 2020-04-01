#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline bool bigger(string &a,string &b){
    //if(a==b)return false;
    if(a.size()!=b.size())return a.size()>b.size();
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return a[i]>b[i];
        }
    }
    return false;
}
inline string add(string a,string b){
    if(a=="")return b;
    if(b=="")return a;
    vector<int> t1;
    t1.clear();
    if(a.size()<b.size())swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.size();i++){
        t1.push_back(a[i]-'0');
    }
    for(int i=0;i<b.size();i++){
        t1[i]+=(b[i]-'0');
    }
    for(int i=0;i<t1.size();i++){
        if(t1[i]>=10){
            if(i==t1.size()-1){
                t1.push_back(t1[i]/10);
            }
            else t1[i+1]+=t1[i]/10;
            t1[i]%=10;
        }
    }
    string ans="";
    for(int i=0;i<t1.size();i++){
        ans+=(char)t1[i]+'0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

inline string tostr(ll x){
	string ans="";
	while(x){
		//cout<<x<<'\n';
		ans+=(char)(x%10+'0');
		x/=10;
	}
	while(ans.size()<8)ans+="0";
	//cout<<ans<<'\n'<<'\n';
	return ans;
}

inline string mul(string a,string b){
	//cout<<a<<" "<<b<<'\n';
    if(a=="0"||b=="0")return "0";
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<ll> t1,t2;
    t1.clear();
    t2.clear();
	ll t=1;
	ll tempans=0;
	for(int i=0;i<a.size();i++){
		tempans+=(a[i]-'0')*t;
		t*=10;
		if(t==100000000||i==a.size()-1){
			//cout<<tempans<<'\n';
			t1.push_back(tempans);
			tempans=0;
			t=1;
		}
	}
	//for(auto i:t1)cout<<i<<'\n';
	tempans=0;
	t=1;
	for(int i=0;i<b.size();i++){
		tempans+=(b[i]-'0')*t;
		t*=10;
		if(t==100000000||i==b.size()-1){
			t2.push_back(tempans);
			tempans=0;
			t=1;
		}
	}
	vector<ll> t3;
	t3.resize(t1.size()+t2.size()+1);
	for(int i=0;i<t3.size();i++)t3[i]=0;
	for(int i=0;i<t1.size();i++){
		for(int j=0;j<t2.size();j++){
			t3[i+j]+=t1[i]*t2[j];
		}
	}
	//for(auto i:t3)cout<<i<<'\n';
	string ans="";
	for(int i=0;i<t3.size();i++){
		t3[i+1]+=t3[i]/100000000;
		t3[i]%=100000000;
		ans+=tostr(t3[i]);
	}
	
	while(ans[ans.size()-1]=='0')ans.pop_back();
	reverse(ans.begin(),ans.end());
	//cout<<ans<<'\n';
	return ans;
}

inline string mins(string a,string b){
    if(bigger(b,a)){
        cout<<"ERROR!\n";
        return "";
    }
    //cout<<1<<' ';
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int> t1;
    t1.clear();
    for(int i=0;i<a.size();i++){
        t1.push_back(a[i]-'0');
    }
    for(int i=0;i<b.size();i++){
        t1[i]-=(b[i]-'0');
    }
    for(int i=0;i<t1.size();i++){
        while(t1[i]<0){
            t1[i+1]-=1;
            t1[i]+=10;
        }
    }
    while(!t1.empty() && t1[t1.size()-1]==0)t1.pop_back();
//    return "";
    string ans="";
    for(int i=0;i<t1.size();i++){
        ans+=(char)t1[i]+'0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
inline string findnum(string s,string res,int zeros){
    string t="";
    for(int i=0;i<=zeros;i++){
        t+='0';
    }
    //cout<<t<<'\n';
    int l=0,r=9;
    while(l<r){
    	int m=(l+r+1)>>1;
    	//cout<<m<<'\n';
    	t[0]=m+'0';
    	string temp=mul(t,add(res,t));
    	if(bigger(temp,s)){
            r=m-1;
        }
        else l=m;
	}
	t[0]=l+'0';
//	cout<<t<<'\n';
    /*for(int i=1;i<=9;i++){
        t[0]+=1;
        string temp=mul(t,add(res,t));
        //cout<<s<<" "<<temp<<'\n';
        if(bigger(temp,s)){
            t[0]-=1;
            return t;
        }
        //cout<<t<<'\n';
    }*/
    return t;
}

inline string sqr(string s){
    string ans="";
    int zeros=(s.size()-1)/2;
    //cout<<zeros<<'\n';
    string res="";
    while(zeros>-1&&s!=""){
        string x=findnum(s,res,zeros);
        string temp=mul(x,add(res,x));
        /*if(zeros==0){
            cout<<s<<" "<<temp<<' ';
        }*/
        s=mins(s,temp);
        ans=add(ans,x);
        res=add(res,mul(x,"2"));
        //cout<<s<<" "<<res<<'\n';
        zeros--;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*string x="5";
    for(int i=0;i<900;i++){
    	x+='9';
	}
	cout<<sqr(mul(x,x))<<'\n';
	return 0;*/
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        cout<<sqr(s)<<'\n';
    }
    return 0;
}




