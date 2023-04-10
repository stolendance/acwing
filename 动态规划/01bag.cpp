#include<iostream>
#include<vector>
using namespace std;
// 1 2 3 4 5 分别代表商品编号
int bag_01(int n,int b,vector<int> &v,vector<int> &w)
{
    // b 代表bag v代表价值 w代表weight
    vector<vector<int>> dp(n+1,vector<int>(b+1));
    //int dp[v.size()+1][b+1]; // 代表选完i产品，背包有b容积 能获得的最大价值
    
    // 当i=0时
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            // 等于在背包容积允许的情况下给背包加了重量，同时也加入了价值
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[n][b];
}

int main()
{
    // dp[i][j] i 表示第i次选择 j表示剩余的体积
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
    cout<<bag_01(n,b,v,w)<<endl;
}