#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int whole_bag(int n,int b,vector<int> &v,vector<int> &w)
{
    //cout<<"进入"<<endl;
    vector<vector<int> > dp(n+1,vector<int>(b+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=w[i])
            {
                dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
            }
        }
    }
    return dp[n][b];
}
int main()
{
    int n=0;
    cin>>n;
    vector<int> v(n+1);
    vector<int> w(n+1);
    int b=0;
    cin>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<whole_bag(n,b,v,w)<<endl;
}