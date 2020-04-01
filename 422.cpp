#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
vector <int> name;
int val[10005][10005]={0};
bool used[10005][10005]={false};
int dp(int left,int right,int sum){
    if(used[left][right])return val[left][right];
    used[left][right]=true;
    if(left==right)return val[left][left]=sum*sum;
    //cout<<left<<" "<<right<<" "<<sum<<" "<<min(sum*sum,min(name[left]*name[left]+dp(left+1,right,sum-name[left]),name[right]*name[right]+dp(left,right-1,sum-name[right])))<<endl;
    return val[left][right]=min(sum*sum,min(name[left]*name[left]+dp(left+1,right,sum-name[left]),name[right]*name[right]+dp(left,right-1,sum-name[right])));
    
}


main()
{
    int n;
    cin>>n;
    int x,sum=0;
    for(int a=0;a<n;a++){
        cin>>x;
        name.emplace_back(x);
        sum+=x;
    }
    cout<<dp(0,n-1,sum)<<endl;







}
