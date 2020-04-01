#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<ll> hasha;
vector<ll> hashb;
ll primeforx=97;
ll primeformod=1000000007;
ll power[1000005]={0};
unordered_map<ll,int> strs;
string sa,sb;
int K,X;
ll powermod(ll x,ll y){
    if(y==0)return 1;
    if(y==1)return x;
    if(power[y])return power[y];
    else if(y%2==0)return power[y]=(powermod(x,y/2)*powermod(x,y/2))%primeformod;
    else return power[y]=(powermod(x,y/2)*powermod(x,y/2+1))%primeformod;
}
ll genhash(string x){
    ll ans=0;
    for(int a=0;a<x.length();a++){
        ans=(ans*primeforx+(x[a]-'a'))%primeformod;
    }
    return ans;
}
void buildhasha(string x,int y){
    ll q=0;
    string str;
    str.assign(x,0,y);
    q=genhash(str);
    strs[q]++;
    hasha.push_back(q);
    // cout<<q<<endl;
    for(int i=1;i<x.length()-y+1;i++){
        q=((hasha[i-1]-((x[i-1]-'a')*powermod(primeforx,y-1)))*primeforx+(x[i+y-1]-'a'))%primeformod;
        if(q<0)q+=primeformod;
        hasha.push_back(q);
        strs[q]++;
        //cout<<q<<endl;
    }
        //cout<<endl;
}
void buildhashb(string x,int y){
    ll q=0;
    string str;
    str.assign(x,0,y);
    q=genhash(str);
    hashb.push_back(q);
   // cout<<q<<endl;
    for(int i=1;i<x.length()-y+1;i++){
        q=((hashb[i-1]-((x[i-1]-'a')*powermod(primeforx,y-1)))*primeforx+(x[i+y-1]-'a'))%primeformod;
        if(q<0)q+=primeformod;
        hashb.push_back(q);
       // cout<<q<<endl;
    }
        
}

int main(){
	IOS;
    cin>>sa>>sb>>K>>X;
    buildhasha(sa,K);
    buildhashb(sb,K);
    double copy=0;
    for(int i=0;i<hashb.size();i++){
        if(strs[hashb[i]]>X) copy+=(1.0/(sb.length()-K+1));
    }
    //cout<<copy<<endl; 
    if(copy>0.1)cout<<"copy dog!"<<endl;
    else cout<<"innocent!"<<endl;
}

