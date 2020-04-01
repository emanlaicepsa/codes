#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int walktime;
int cartime;
bool cango;
vector<int>go[10001];
int height[10001];
int dis[10001];
bool walk[10001];
int low;
int lowdis;
queue <int> gogogo;
void bfswalk(int x){
	if(height[x]==low){
		//cout<<x<<1<<endl;
		lowdis=min(lowdis,dis[x]);
	}
    for(int a=0;a<go[x].size();a++){
        if(walk[go[x][a]]==false){
            dis[go[x][a]]=min(dis[go[x][a]],dis[x]+1);
            walk[go[x][a]]=true;
            gogogo.push(go[x][a]);
        }
    }
}
void bfscar(int x){
	int steep=height[x];
	int togo=x;
    if(height[x]==low)
	{
		lowdis=min(lowdis,dis[x]);
	} 
    for(int a=0;a<go[x].size();a++){
        if(height[go[x][a]]<steep){
            togo=go[x][a];
            steep=height[go[x][a]];
        }
    }
    		if(walk[togo]==false){
        	//cout<<x<<" "<<togo<<endl;
            dis[togo]=min(dis[togo],dis[x]+1);
            walk[togo]=true;
            gogogo.push(togo);
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    for(int a=1;a<=T;a++){
        walktime=0,cartime=0,cango=true;
        for(int d=0;d<10001;d++){
            go[d].clear();
            height[d]=0;
            dis[d]=10000000;
            walk[d]=false;}
        
        int N,M,S;
        cin>>N>>M>>S;
        low=20000000;
        lowdis=20000000;
        for(int d=0;d<N;d++){
            cin>>height[d];
            if(height[d]<low){
                low=height[d];
            }
        }
        int X,Y;
        while(M--){
            cin>>X>>Y;
            go[X].emplace_back(Y);
            go[Y].emplace_back(X);  
        }
        gogogo.push(S);
        walk[S]=1;
        dis[S]=0;
        while(!gogogo.empty()){
            bfswalk(gogogo.front());
            gogogo.pop();
        }
        if(lowdis==20000000)cango=false;
        else walktime=lowdis*6;
        //second bfs
        for(int d=0;d<10001;d++){
            dis[d]=10000000;
            walk[d]=false;}
        lowdis=20000000;
        gogogo.push(S);
        walk[S]=1;
        dis[S]=0;
        while(!gogogo.empty()){
            bfscar(gogogo.front());
            gogogo.pop();
        }    
        if(lowdis==20000000)cartime=0;
        else cartime=lowdis;
        cout<<"Case #"<<a<<": ";
        if(cango)cout<<walktime-cartime<<endl;
        else cout<<"Call 119!"<<endl; 
    }
    return 0;
}

