#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=25000
int bag_01(int n,int b,vector<int>&w,vector<int>&v,vector<int>&s)
{
    vector<vector<int> > dp(n+1,vector<int>(b+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(dp[i][j])dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]);

        }
    }
    return dp[n][b];
}
int main()
{
    int n=0;
    cin>>n;
    int b=0;
    cin>>b;

}